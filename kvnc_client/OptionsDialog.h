// Copyright (C) 2012 GlavSoft LLC.
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

#ifndef _OPTIONS_DIALOG_H_
#define _OPTIONS_DIALOG_H_

#include "../libkvnc_client_config/ViewerConfig.h"
#include "../libkvnc_client_config/ConnectionConfig.h"
#include "../libkvnc_client_config/ConnectionConfigSM.h"
#include "../libkvnc_client_config/ViewerSettingsManager.h"
#include "../libkvnc_all_util/StringParser.h"
#include "../libkvnc_all_gui/BaseDialog.h"
#include "../libkvnc_all_gui/TextBox.h"
#include "../libkvnc_all_gui/CheckBox.h"
#include "../libkvnc_all_gui/ComboBox.h"
#include "../libkvnc_all_gui/TrackBar.h"
#include "kvnc_client_Resource.h"

class OptionsDialog : public BaseDialog
{
public:
  OptionsDialog();

  void setConnectionConfig(ConnectionConfig *conConfig);
  void setConnected();

protected:
  ComboBox m_useEnc;
  CheckBox m_eightBit;
  CheckBox m_compLvl;
  Trackbar m_tcompLvl;
  Control m_quality;
  CheckBox m_jpeg;
  Trackbar m_tjpeg;
  Control m_quality2;
  CheckBox m_copyrect;
  CheckBox m_viewonly;
  CheckBox m_disclip;
  CheckBox m_sharedses;
  ComboBox m_scale;
  CheckBox m_fullscr;
  CheckBox m_deiconfy;
  CheckBox m_swapmouse;
  CheckBox m_track;       // Track remote control locally
  CheckBox m_cursor;      // Let remote server deal with mouse cursor
  CheckBox m_ncursor;     // Don't show remote cursor
  CheckBox m_dot;
  CheckBox m_smalldot;
  CheckBox m_arrow;
  CheckBox m_nlocal;

  void onMessageReceived(UINT uMsg, WPARAM wParam, LPARAM lParam);
  BOOL onCommand(UINT controlID, UINT notificationID);
  BOOL onInitDialog();

  ConnectionConfig *m_conConfig;
  bool m_connected;

private:
  void updateControlValues();
  void onViewOnlyClick();
  void on8BitColorClick();
  void enableJpegCompression(bool enable);
  void onAllowCustomCompressionClick();
  void enableCustomCompression(bool enable);
  void onAllowJpegCompressionClick();
  void onPreferredEncodingSelectionChange();
  void onCustomCompressionLevelScroll();
  void onJpegCompressionLevelScroll();
  void onScaleKillFocus();
  bool isInputValid();
  bool onOkPressed();
  void apply();

};

#endif
