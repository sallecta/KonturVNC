
#include "TextChatHandler.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_Defs.cpp"

#include "../libkvnc_all_util/AnsiStringStorage.h"


TextChatHandler::TextChatHandler(RfbCodeRegistrator *registrator,
                             RfbOutputGate *output,
                             LogWriter *log, ChatDialog * chatDialog)
:
  m_output(output), m_log(log), m_chatdialog(chatDialog)
{
  // Request codes
  registrator->regCode(lkvnc_rfb_Defs__Client::CHAT_REQ, this);
  registrator->regCode(lkvnc_rfb_Defs__Client::CLIENT_CHAT_MSG, this);


}

TextChatHandler::~TextChatHandler()
{
}

void TextChatHandler::sendMsgToClient(const StringStorage * msg){

UINT32 length = static_cast<UINT32>(msg->getSize());


AutoLock al(m_output);
m_output->writeUInt8(lkvnc_rfb_Defs__Client::SERVER_CHAT_MSG);
m_output->writeUInt32(length);
m_output->writeFully(msg->getString(), length);
m_output->flush();


}

void TextChatHandler::onRequest(UINT32 reqCode, RfbInputGate *input)
{
 switch (reqCode) {
    case lkvnc_rfb_Defs__Client::CHAT_REQ:
		m_chatdialog->show();
      break;
    case lkvnc_rfb_Defs__Client::CLIENT_CHAT_MSG:
		{
		UINT32 length = input->readUInt32();

		std::vector<TCHAR> charBuff(length + 1);

		input->readFully(&charBuff.front(), length);
		charBuff[length] = '\0';
		StringStorage msg(&charBuff.front());

     	m_chatdialog->addMsg(msg);



		}
	  break;
	default:
	  break;
    }

}
