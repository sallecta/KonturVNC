// Copyright (C) 2011,2012 GlavSoft LLC.
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

#ifndef _VIEWER_WINDOW_H_
#define _VIEWER_WINDOW_H_

#include "ConnectionData.h"
#include "DesktopWindow.h"
#include "FileTransferMainDialog.h"
#include "NamingDefs.h"
#include "OptionsDialog.h"
#include "ScaleManager.h"
#include "ReconnectWnd.h"
#include "ViewerMenu.h"
#include "../libkvnc_gui/ToolBar.h"
#include "../libkvnc_log_writer/LogWriter.h"
#include "../libkvnc_client_core/FileTransferCapability.h"
#include "../libkvnc_client_core/RemoteViewerCore.h"
#include "../libkvnc_client_core/CoreEventsAdapter.h"
#include "../libkvnc_client_core/VncAuthentication.h"
#include "../libkvnc_win_system/SystemInformation.h"
#include "../libkvnc_win_system/WindowsApplication.h"
#include "../libkvnc_win_system/WinHooks.h"

#include "ClientChatDialog.h"

#include "viewer-core/TextCapability.h"

#include "viewer-core/SdpCapability.h"

#include "../libkvnc_server_rfb/TextMsgListener.h"

#include "../libkvnc_p2p/P2pEventListener.h"

class ViewerWindow : public BaseWindow,
                     public CoreEventsAdapter,
                     private HookEventListener, public TextMsgListener, public P2pEventListener
{
public:
  ViewerWindow(WindowsApplication *application,
               ConnectionData *conData, ConnectionConfig *conConf,
               Logger *logger = 0);
  virtual ~ViewerWindow();

  void setFileTransfer(FileTransferCapability *ft);
  void setChatHandler(TextCapability *chat);
  void setRemoteViewerCore(RemoteViewerCore *pCore);

  //
  // This function return value of flag m_requiresReconnect.
  //
  bool requiresReconnect() const;

  //
  // This function return value of flag m_stopped.
  //
  bool isStopped() const;

  virtual void onTextMsg(StringStorage * msg);
  virtual void onP2pSuccess();
  virtual void onP2pFailed();

  void reconnect(BOOL bResetPassword);

  static const int WM_USER_ERROR = WM_USER + 1;
  static const int WM_USER_STOP = WM_USER + 2;
  static const int WM_USER_DISCONNECT = WM_USER + 3;
  static const int WM_USER_AUTH_ERROR = WM_USER + 4;
  static const int WM_USER_FS_WARNING = WM_USER + 5;

protected:
  static const int TIMER_DESKTOP_STATE = 1;
  static const int TIMER_DESKTOP_STATE_DELAY = 50;

  static const int REC_START = 2;
  static const int REC_START_DELAY = 2000;

  bool onMessage(UINT message, WPARAM wParam, LPARAM lParam);
  bool onEraseBackground(HDC hdc);

  bool onDisconnect();
  bool onAuthError(WPARAM wParam);
  bool onError();

  bool onFsWarning();
  bool onSize(WPARAM wParam, LPARAM lParam);
  bool onCreate(LPCREATESTRUCT lps);
  bool onCommand(WPARAM wParam, LPARAM lParam);
  bool onNotify(int idCtrl, LPNMHDR pnmh);
  bool onSysCommand(WPARAM wParam, LPARAM lParam);
  bool onClose();
  bool onDestroy();
  bool onFocus(WPARAM wParam);
  bool onKillFocus(WPARAM wParam);
  bool onTimer(WPARAM idTimer);

  void desktopStateUpdate();
  void commandCtrlAltDel();
  void commandCtrlEsc();
  void commandCtrl();
  void commandAlt();
  void commandToolBar();
  void commandPause();
  void onAbout();
  void commandNewConnection();
  void commandSaveSession();
  void commandScaleIn();
  void commandScaleOut();
  void commandScale100();
  void commandRec();
  void showDisp();
  void remoteCP();
  void beginP2P();
  void remoteReboot();
  void takeScreenShot();
  void commandScaleAuto();
  //
  // It is implementation of CoreEventsAdapter functions.
  //
  void onBell();
  void onConnected(RfbOutputGate *output);
  void onDisconnect(const StringStorage *message);
  void onAuthError(const AuthException *exception);
  void onError(const Exception *exception);
  void onFrameBufferUpdate(const FrameBuffer *fb, const Rect *rect);
  void onFrameBufferPropChange(const FrameBuffer *fb);
  void onCutText(const StringStorage *cutText);

  void notifyErrorWnd();



  int translateAccelToTB(int val);
  void applyScreenChanges(bool isFullScreen);

  // function return default rect of viewer window:
  // if size of remote screen is more local desktop, then return rect of desktop
  // else return rect of remote screen + border
  Rect calculateDefaultSize();

  LogWriter m_logWriter;

  Control m_control;

  ConnectionConfigSM m_ccsm;
  ConnectionConfig *m_conConf;
  WindowsApplication *m_application;
  RemoteViewerCore *m_viewerCore;
  FileTransferCapability *m_fileTransfer;
  FileTransferMainDialog *m_ftDialog;
  TextCapability *m_chatHandler;
  ClientChatDialog * m_chatDialog;
  DesktopWindow m_dsktWnd;
  StringStorage m_strToolTip;
  ToolBar m_toolbar;
  ViewerMenu m_menu;
  ConnectionData *m_conData;
  SystemInformation m_sysinf;

  // This variable save Exception after call onError().
  Exception m_error;
  // This variable save disconnect-message after call onDisconnect().
  StringStorage m_disconnectMessage;

  // Flag is set, if now viewer is in full screen mode
  bool m_isFullScr;
  // It's size of work-area in windowed mode. It is necessary for restore size of window.
  WINDOWPLACEMENT m_workArea;
  // It's size of optimal size of work-area in windowed mode.
  Rect m_rcNormal;


  // Flag is set after recv first message WM_SIZING.
  bool m_sizeIsChanged;
  // Flag is set, if toolbar is visible.
  bool m_bToolBar;
  // It is scale of viewer window in percent.
  int m_scale;

  // Flag is set after onConnected().
  bool m_isConnected;

  // Flag is set, if instance is requires to reconnect.
  bool m_requiresReconnect;

  // Flag is set, if viewer instance is stopped.
  // Destructor of ViewerWindow may be called, if this flag is true.
  bool m_stopped;
private:
  vector<int> m_standardScale;
  void changeCursor(int type);
  void applySettings();
  void setSizeFullScreenWindow();
  void doFullScr();
  void doUnFullScr();
  void doSize();
  void doCommand(int iCommand);
  void showFileTransferDialog();
  void showChatDialog();
  void showWindow();
  void enableUserElements();
  bool viewerCoreSettings();
  void dialogConnectionOptions();
  void dialogConnectionInfo();
  void switchFullScreenMode();
  void dialogConfiguration();
  void adjustWindowSize();
  StringStorage formatWindowName() const;
  void updateKeyState();

  int displayCount;

  // onHookProc function implementation of HookEventListener base abstract class.
  virtual LRESULT onHookProc(int code, WPARAM wParam, LPARAM lParam);
  WinHooks m_winHooks;
  bool m_hooksEnabledFirstTime;

  bool m_p2pEnabled;

};

#endif
