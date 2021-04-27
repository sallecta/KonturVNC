

#include "../libkvnc_all_rfb/lkvnc_rfb_DefsVendor.h"
#include "SdpCapability.h"

#include "../libkvnc_all_rfb/lkvnc_rfb_Defs.cpp"

SdpCapability::SdpCapability()
{

}

SdpCapability::~SdpCapability()
{

}

void SdpCapability::setCore(RemoteViewerCore * core, P2pTransport * p2p)
{
	m_core = core;
	m_p2p = p2p;
}

void SdpCapability::onServerMessage(UINT32 code, DataInputStream *input)
{
static char buffer[1000];
AnsiStringStorage msg;
UINT32 length;

switch (code) {
    case (lkvnc_rfb_Defs__Client::SERVER_SDP):

	length = input->readUInt32();
	input->readFully(&buffer, length);
	buffer[length] = '\0';
	m_p2p->ice.InputSession(buffer);

	m_p2p->ice.StartNego();


	m_p2p->GetSDP(&msg);
	m_core->sendClientSdp(&msg);
	break;

	case lkvnc_rfb_Defs__Client::P2P_OK:
		break;
}



}

void SdpCapability::addCapabilities(CapabilitiesManager *capabilities)
{

  capabilities->addClientMsgCapability(lkvnc_rfb_Defs__Client::BEGIN_NEG,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  ("P2PBEGNE"),
                                  _T("p2p support"));

  capabilities->addServerMsgCapability(this,
                                  lkvnc_rfb_Defs__Client::SERVER_SDP,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  _T("SDP"));
  capabilities->addServerMsgCapability(this,
                                  lkvnc_rfb_Defs__Client::P2P_OK,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  _T("P2P"));


}
