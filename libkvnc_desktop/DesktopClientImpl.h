// Copyright (C) 2008,2009,2010,2011,2012 GlavSoft LLC.
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

#ifndef __DESKTOPCLIENTIMPL_H__
#define __DESKTOPCLIENTIMPL_H__

#include "../libkvnc_util/CommonHeader.h"
#include "DesktopServerWatcher.h"
#include "../libkvnc_desktop_ipc/DesktopConfigClient.h"
#include "../libkvnc_desktop_ipc/ReconnectingChannel.h"
#include "../libkvnc_desktop_ipc/BlockingGate.h"
#include "../libkvnc_desktop_ipc/GateKicker.h"
#include "../libkvnc_desktop_ipc/DesktopSrvDispatcher.h"
#include "DesktopBaseImpl.h"
#include "../libkvnc_log_writer/LogWriter.h"

//Interfaces
#include "../libkvnc_util/AnEventListener.h"
#include "../libkvnc_desktop_ipc/ReconnectionListener.h"
#include "UpdateListener.h"

class DesktopClientImpl : public AnEventListener,
                   public ReconnectionListener,
                   public Thread,
                   public DesktopBaseImpl
{
public:
  DesktopClientImpl(ClipboardListener *extClipListener,
                UpdateSendingListener *extUpdSendingListener,
                AbnormDeskTermListener *extDeskTermListener,
                LogWriter *log);
  virtual ~DesktopClientImpl();

protected:
  virtual void execute();
  virtual void onTerminate();

private:
  // Interface functions
  virtual void onAnObjectEvent();
  virtual void onReconnect(Channel *newChannelTo, Channel *newChannelFrom);

  void freeResource();
  void closeDesktopServerTransport();

  virtual bool isRemoteInputTempBlocked();
  virtual void applyNewConfiguration();

  // Inter process transport
  ReconnectingChannel *m_clToSrvChan;
  ReconnectingChannel *m_srvToClChan;
  BlockingGate *m_clToSrvGate;
  BlockingGate *m_srvToClGate;

  DesktopServerWatcher *m_deskServWatcher;
  DesktopSrvDispatcher *m_dispatcher;

  GateKicker *m_gateKicker;
  UserInput *m_userInputClient; // It uses for delegation by the SasUserInput.

  DesktopConfigClient *m_deskConf;

  LogWriter *m_log;
};

#endif // __DESKTOPCLIENTIMPL_H__
