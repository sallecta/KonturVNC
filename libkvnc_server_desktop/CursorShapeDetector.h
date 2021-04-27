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

#ifndef __CURSORHAPEDETECTOR_H__
#define __CURSORHAPEDETECTOR_H__

#include "UpdateKeeper.h"
#include "CursorShapeGrabber.h"
#include "UpdateDetector.h"
#include "../libkvnc_all_winSystem/WindowsEvent.h"
#include "../libkvnc_all_logger/LogWriter.h"

class lkvnc_rfb_CursorShapeDetector : public UpdateDetector
{
public:
  lkvnc_rfb_CursorShapeDetector(UpdateKeeper *updateKeeper,
                     UpdateListener *updateListener,
                     lkvnc_rfb_CursorShapeGrabber *mouseGrabber,
                     LocalMutex *mouseGrabLocMut,
                     LogWriter *log);
  virtual ~lkvnc_rfb_CursorShapeDetector();

protected:
  virtual void execute();
  virtual void onTerminate();

  lkvnc_rfb_CursorShapeGrabber *m_mouseGrabber;
  LocalMutex *m_mouseGrabLocMut;
  WindowsEvent m_sleepTimer;

  LogWriter *m_log;
};

#endif // __CURSORHAPEDETECTOR_H__
