// Copyright (C) 2009,2010,2011,2012 GlavSoft LLC.
// All rights reserved.
//
//-------------------------------------------------------------------------
// This file is part of the TightVNC software.  Please visit our Web site:
//
//                       http://www.tightvnc.com/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//-------------------------------------------------------------------------
//

#ifndef _OUTGOING_CONNECTION_DIALOG_H_
#define _OUTGOING_CONNECTION_DIALOG_H_

#include "../libkvnc_all_util/winhdr.h"

#include "../libkvnc_all_gui/BaseDialog.h"
#include "../libkvnc_all_gui/ComboBox.h"
#include "../libkvnc_all_gui/CheckBox.h"

#include "../libkvnc_all_winSystem/RegistryKey.h"

#include "../libkvnc_all_config/ConnectionHistory.h"

/**
 * Outgoing connection dialog. Just allows user to put connection string
 * and select mode for connection.
 */
class OutgoingConnectionDialog : public BaseDialog
{
public:
  OutgoingConnectionDialog();
  virtual ~OutgoingConnectionDialog();

  /**
   * Gets connection string, specified by user.
   * @return connection string.
   */
  const TCHAR *getConnectString() const;

  /**
   * Gets view only flag, specified by user.
   * @return view only flag.
   */
  bool isViewOnly() const;

protected:
  void initControls();

  virtual BOOL onInitDialog();
  virtual BOOL onNotify(UINT controlID, LPARAM data);
  virtual BOOL onCommand(UINT controlID, UINT notificationID);
  virtual BOOL onDestroy();

  void onOkButtonClick();
  void onCancelButtonClick();

protected:
  /**
   * Member to hold connection string after dialog is destroyed.
   */
  StringStorage m_connectString;
  /**
   * Like m_connectString, but for view only flag.
   */
  bool m_isViewOnly;

  /**
   * Connection history registry key.
   */
  RegistryKey m_connHistoryKey;
  /**
   * Connection history container.
   */
  ConnectionHistory m_connHistory;

  /**
   * Combo box with connection history.
   */
  ComboBox m_connectStringCB;
  /**
   * "View-only" checkbox.
   */
  CheckBox m_viewOnlyCB;
};

#endif
