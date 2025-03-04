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

#ifndef __WSCONFIGRUNNER_H__
#define __WSCONFIGRUNNER_H__

#include "../libkvnc_all_thread/Thread.h"
#include "../libkvnc_all_logger/LogWriter.h"

// This class runs TvnControl in current session.
// This class only for application mode running.
class WsConfigRunner : private Thread
{
public:
  WsConfigRunner(Logger *logger, bool serviceMode = false);
  virtual ~WsConfigRunner();

protected:
  virtual void execute();

private:
  bool m_serviceMode;

  LogWriter m_log;
};

#endif // __WSCONFIGRUNNER_H__
