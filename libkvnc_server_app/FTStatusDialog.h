
#ifndef _FTS_DIALOG_H_
#define _FTS_DIALOG_H_

#include "../libkvnc_all_gui/BaseDialog.h"
#include "../libkvnc_all_thread/LocalMutex.h"



class FTStatusDialog :
	public BaseDialog
{
public:
	FTStatusDialog();
	void PositionFlyout();
	virtual ~FTStatusDialog(void);
	virtual BOOL onInitDialog();
        virtual BOOL onCommand(UINT controlID, UINT notificationID);
	virtual void onMessageReceived(UINT uMsg, WPARAM wParam, LPARAM lParam);
   void SetStatus(StringStorage status);
	int show();
	void hide();
private:
	void initControls();

	HWND hWndLabel;


};

#endif
