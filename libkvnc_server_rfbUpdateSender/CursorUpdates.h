// Copyright (C) 2010,2011,2012 GlavSoft LLC.
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

#ifndef __CURSORUPDATES_H__
#define __CURSORUPDATES_H__

#include "../libkvnc_server_rfb/EncodeOptions.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_CursorShape.h"
#include "../libkvnc_server_desktop/UpdateContainer.h"
#include "../libkvnc_all_util/DateTime.h"
#include "../libkvnc_all_thread/LocalMutex.h"
#include "../libkvnc_all_logger/LogWriter.h"

class CursorUpdates
{
public:
  CursorUpdates(LogWriter *log);
  virtual ~CursorUpdates();

  // Important: After calling the update() function frame buffer
  // may contain a cursor image to send it as a frame buffer update.
  // After sending the frame buffer updates the user code must at sight
  // call the restoreFrameBuffer() function. Also function clones
  // actual cursor shape to the lkvnc_rfb_CursorShape argument (Only when after call
  // the updCont->lkvnc_rfb_CursorShapeChanged flag is raised).
  void update(const EncodeOptions *encodeOptions,
              UpdateContainer *updCont,
              bool fullRegReq,
              const Rect *viewPort,
              bool shareOnlyApp,
              const Region *shareAppRegion,
              lkvnc_rfb_FrameBuffer *fb,
              lkvnc_rfb_CursorShape *lkvnc_rfb_CursorShape);
  void restoreFrameBuffer(lkvnc_rfb_FrameBuffer *fb);

  // Returns current cursor position. Beetween
  Point getCurPos();

  // Returns background rectangle.
  Rect getBackgroundRect();

  // Block cursor pos sending by this
  // connection to a client. Unblocking will
  // be automaticly for a time.
  void blockCursorPosSending();

  // Clones (updates internal) the cursor shape.
  void updateCursorShape(const lkvnc_rfb_CursorShape *curShape);

private:
  // Clones the internal cursor shape to curShape.
  void extractCursorShape(lkvnc_rfb_CursorShape *curShape);

  // Check cursor position for changing and store it to the m_cursorPos.
  // Return true value if cursor position has been changed.
  bool checkCursorPos(UpdateContainer *updCont,
                      const Rect *viewPort,
                      bool curPosBlockingIsIgnored);

  // Shortcut function to draw cursor on the frame buffer directly.
  void drawCursor(UpdateContainer *updCont, lkvnc_rfb_FrameBuffer *fb);

  // Check for cursor blocking state and
  // return true if it is blocked and false
  // otherwise.
  bool isCursorPosBlocked();

  // Current state
  Point m_cursorPos;
  DateTime m_blockCurPosTime;
  lkvnc_rfb_CursorShape m_cursorShape;
  lkvnc_rfb_FrameBuffer m_shapeBackground;
  Point m_backgroundPos;
  LocalMutex m_curPosLocMut;
  // Uses when the rich enabled but pointer pos disabled to determine
  // the last send method: by a cursor shape update or drawing on the
  // frame buffer.
  bool m_isDrawCursorMethod;

  LogWriter *m_log;
};

#endif // __CURSORUPDATES_H__
