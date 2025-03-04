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

#ifndef _VIEWER_CONFIG_H_
#define _VIEWER_CONFIG_H_

#include "../libkvnc_all_util/StringStorage.h"
#include "../libkvnc_all_util/Singleton.h"
#include "../libkvnc_all_config/ConnectionHistory.h"
#include "../libkvnc_all_logger/FileLogger.h"
#include "../libkvnc_all_thread/LocalMutex.h"
#include "../libkvnc_all_thread/AutoLock.h"

#include "ConnectionConfig.h"

//
// Contains base set of viewer configuration options.
//

class ViewerConfig : public Singleton<ViewerConfig>
{
public:
  ViewerConfig(const TCHAR registryPath[]);
  ~ViewerConfig();

  // Deserializes client configuration from settings storage.
  // Returns true if was no errors during deserialization,
  // false, otherwise.
  bool loadFromStorage(SettingsManager *storage);

  // Serializes client configuration from settings storage.
  // Returns true if was no errors during serialization,
  // false, otherwise.
  bool saveToStorage(SettingsManager *storage) const;

  // Sets port for incoming connection when client runs in daemoon mode
  void setListenPort(UINT16 listenPort);
  // Returns listen port value
  UINT16 getListenPort() const;

  // Returns log level in 0 - 9 range
  void setLogLevel(int logLevel);
  // Returns log level
  int getLogLevel() const;

  // Puts log directory to the logDir argument.
  void getLogDir(StringStorage *logDir) const;

  // Creates path to log file and place value to m_pathToLogFile member
  // creates logger and return pointer to him
  Logger *initLog(const TCHAR logDir[], const TCHAR logName[]);

  // function return pointer to logger
  Logger *getLogger();

  // Sets number of connections to remember
  void setHistoryLimit(int historyLimit);
  // Returns number of connections to remember
  int getHistoryLimit() const;

  // Sets "show toolbar" flag
  void showToolbar(bool show);
  // Returns "show toolbar" flag
  bool isToolbarShown() const;

  // Sets "prompt on fullscreen flag"
  void promptOnFullscreen(bool promt);
  // Returns "prompt on fullscreen flag"
  bool isPromptOnFullscreenEnabled() const;


    // Sets "show toolbar" flag
  void autoRecord(bool rec);
  // Returns "show toolbar" flag
  bool isAutoRecord() const;


  void askComment(bool ask);
  bool isAskComment() const;




  // Returns path to log file if file is avaliable to write,
  // returns NULL otherwise
  const TCHAR *getPathToLogFile() const;

   const TCHAR *getPathToVLogFile() const;

   const TCHAR *getFullPathToVLogFile() const;

   const void setPathToVLogFile(StringStorage vPath);

   const void setFullPathToVLogFile(StringStorage vPath);

     const TCHAR *getUserName() const;

	 const TCHAR *getPeerName() const;

	const void setPeerName(StringStorage peer);

  // Returns connection history
  ConnectionHistory *getConnectionHistory();

protected:
  // TCP port for accepting incoming connection
  // when client runs in daemon mode
  int m_listenPort;
  // Current level of logging
  int m_logLevel;
  // Number of connections to remember
  int m_historyLimit;
  // If set then toolbar is shown, otherwise not shown
  bool m_showToolbar;
  // If set then app must show promt dialog when viewer window
  // become fullscreen
  bool m_promptOnFullscreen;

  bool m_autoRecord;
  bool m_askComment;
  // Log file
  StringStorage m_pathToLogFile;
  StringStorage m_pathToVLogFile;
  StringStorage m_fullpathToVLogFile;
  StringStorage m_userName;
  StringStorage m_peerName;
  StringStorage m_logName;
  FileLogger *m_logger;
  // Connection history
  RegistryKey m_conHistoryKey; // Used by m_conHistory
  ConnectionHistory m_conHistory;
private:
  // Critical section for synchronization
  mutable LocalMutex m_cs;
};

#endif
