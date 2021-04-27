
#ifndef _COMMENT_DIALOG_H_
#define _COMMENT_DIALOG_H_

#include "../libkvnc_all_gui/BaseDialog.h"
#include "../libkvnc_all_gui/ComboBox.h"
#include "kvnc_client_Resource.h"
#include "../libkvnc_all_config/CommentHistory.h"

#include "../libkvnc_all_winSystem/RegistryKey.h"
#include "../libkvnc_all_winSystem/Registry.h"
#include "kvnc_client__Defs.h"



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
