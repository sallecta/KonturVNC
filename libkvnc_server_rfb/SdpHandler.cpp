
#include "SdpHandler.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_Defs.cpp"

#include "../libkvnc_all_util/AnsiStringStorage.h"


SdpHandler::SdpHandler(RfbCodeRegistrator *registrator,
                             RfbOutputGate *output,
                             LogWriter *log, P2pTransport * p2p)
:
  m_output(output), m_log(log), m_p2p(p2p)
{
  // Request codes
  registrator->regCode(lkvnc_rfb_Defs__Client::CLIENT_SDP, this);
  registrator->regCode(lkvnc_rfb_Defs__Client::BEGIN_NEG, this);
  registrator->regCode(lkvnc_rfb_Defs__Client::ENABLE_P2P, this);
  registrator->regCode(lkvnc_rfb_Defs__Client::DISABLE_P2P, this);

}

SdpHandler::~SdpHandler()
{
}

void SdpHandler::sendSDPToClient(){

AnsiStringStorage msg;

m_p2p->GetSDP(&msg);

UINT32 length = static_cast<UINT32>(msg.getSize());
if (length > 0){
AutoLock al(m_output);
m_output->writeUInt8(lkvnc_rfb_Defs__Client::SERVER_SDP);
m_output->writeUInt32(length);
m_output->writeFully(msg.getString(), length);
m_output->flush();
}


}

void SdpHandler::onRequest(UINT32 reqCode, RfbInputGate *input)
{

UINT32 length ;

 switch (reqCode) {
    case lkvnc_rfb_Defs__Client::CLIENT_SDP:
	static char buffer[1000];

	length = input->readUInt32();
	input->readFully(&buffer, length);
	buffer[length] = '\0';
	m_p2p->ice.InputSession(buffer);
	m_p2p->ice.StartNego();

		break;
    case lkvnc_rfb_Defs__Client::BEGIN_NEG:

		sendSDPToClient();
	  break;
	case lkvnc_rfb_Defs__Client::ENABLE_P2P:
		{
		AutoLock al(m_output);
		m_output->writeUInt8(lkvnc_rfb_Defs__Client::P2P_OK);
		m_output->flush();
		}
		m_p2p->m_enable = true;
	  break;

	case lkvnc_rfb_Defs__Client::DISABLE_P2P:
		{
		AutoLock al(m_output);
		m_output->writeUInt8(lkvnc_rfb_Defs__Client::P2P_OK);
		m_output->flush();
		}
		m_p2p->m_enable = false;
	  break;

	default:
	  break;
    }

}
