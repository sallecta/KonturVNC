
#ifndef _CHAT_DIALOG_H_
#define _CHAT_DIALOG_H_

#include "../libkvnc_gui/BaseDialog.h"
#include "../libkvnc_gui/TextBox.h"
#include "../libkvnc_thread/LocalMutex.h"

#include "../libkvnc_server_rfb/TextMsgListener.h"


class ChatDialog :
	public BaseDialog
{
public:
	ChatDialog(TextMsgListener * extMsgListener);
	void PositionFlyout();
	virtual ~ChatDialog(void);
	virtual BOOL onInitDialog();
    virtual BOOL onCommand(UINT controlID, UINT notificationID);

	void addMsg(StringStorage msg);


	int show();
	void hide();
private:
	void initControls();

	void Send();
	static LRESULT CALLBACK subEditProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

	StringStorage chatHist;
	TextBox m_chatlog;
	TextBox m_message;



	TextMsgListener *m_extMsgListener;

protected:

	WNDPROC oldEditProc;

};

#endif
