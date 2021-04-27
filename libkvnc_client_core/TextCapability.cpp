

#include "../libkvnc_all_rfb/lkvnc_rfb_DefsVendor.h"
#include "TextCapability.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_Defs.cpp"


TextCapability::TextCapability()
{

}

TextCapability::~TextCapability()
{

}


void TextCapability::setChatDialog(ClientChatDialog * dialog)
{
	m_clientDialog = dialog;

}
void TextCapability::onServerMessage(UINT32 code, DataInputStream *input)
{

		UINT32 length = input->readUInt32();

		std::vector<TCHAR> charBuff(length + 1);

		input->readFully(&charBuff.front(), length);
		charBuff[length] = '\0';
		StringStorage msg(&charBuff.front());

		m_clientDialog->addMsg(msg);

}

void TextCapability::addCapabilities(CapabilitiesManager *capabilities)
{

  capabilities->addServerMsgCapability(this,
                                  lkvnc_rfb_Defs__Client::SERVER_CHAT_MSG,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  lkvnc_rfb_DefsVendor__Common::TIGHTVNC,
                                  _T("Text Chat"));


}
