
#ifndef _COMMENT_DIALOG_H_
#define _COMMENT_DIALOG_H_

#include "../libkvnc_gui/BaseDialog.h"
#include "../libkvnc_gui/ComboBox.h"
#include "resource.h"
#include "../libkvnc_config/CommentHistory.h"

#include "../libkvnc_win_system/RegistryKey.h"
#include "../libkvnc_win_system/Registry.h"
#include "NamingDefs.h"



class CommentDialog : public BaseDialog
{
public:
  CommentDialog();
  StringStorage *getComment();

protected:
  BOOL onCommand(UINT controlID, UINT notificationID);
  BOOL onInitDialog();

  ComboBox m_combo;
  StringStorage m_strComment;
  CommentHistory m_commHist;
  RegistryKey m_comHistoryKey;

};

#endif
