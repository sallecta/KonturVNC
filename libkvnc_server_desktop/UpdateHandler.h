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

#ifndef __UPDATEHANDLER_H__
#define __UPDATEHANDLER_H__

#include "UpdateContainer.h"
#include "UpdateKeeper.h"
#include "UpdateFilter.h"
#include "ScreenGrabber.h"
#include "WindowsCursorShapeGrabber.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_FrameBuffer.h"
#include "../libkvnc_all_thread/AutoLock.h"
#include "UpdateListener.h"
#include "UpdateDetector.h"
#include "CopyRectDetector.h"
#include "../libkvnc_server_desktopIpc/BlockingGate.h"

class UpdateHandler
{
public:
  UpdateHandler();
  virtual ~UpdateHandler(void);

  // The extract() function fills in a UpdateContainer object.
  // Also, if screen properties (such as resolution, pixel format)
  // has changed the function reconfigures lkvnc_rfb_FrameBuffers. The
  // reconfiguration posible the only one function.
  //
  // If screen size or pixel format have changed the copied region
  // and the changed region will be cleaned, lkvnc_rfb_FrameBuffers will
  // be reinitialized. Also, if screen size have changed the
  // screenSizeChanged flag will be set to true. In the next
  // time call of this function no additional information about
  // these changes will present.

  // Parameters:
  //   updateContainer - pointer to a UpdateContainer object that will be filled
  virtual void extract(UpdateContainer *updateContainer) = 0;

  // This function unconventionally set to update pending of the frame buffer
  // in the next time call of the extract() function. All found changes
  // saves to the changedRegion and copiedRegion.
  virtual void setFullUpdateRequested(const Region *region) = 0;

  // Checking a region for updates.
  // Return:
  //   true - if updates presents,
  //   false - if not.
  virtual bool checkForUpdates(Region *region) = 0;

  // Set a region excluded from the region that updates detects.
  // excludedRegion will never be present in changedRegion or copiedRegion.
  virtual void setExcludedRegion(const Region *excludedRegion) = 0;

  // The function provides access to lkvnc_rfb_FrameBuffer data.
  // The data usage be able until next extract() function call.
  // Return:
  //   constant pointer to the lkvnc_rfb_FrameBuffer object.
  const lkvnc_rfb_FrameBuffer *getFrameBuffer() const { return &m_backupFrameBuffer; }
  const lkvnc_rfb_CursorShape *getCursorShape() const { return &m_cursorShape; }
  // This function for asynchronous access to frame buffer properties
  // (dimension and pixel format)
  void getFrameBufferProp(Dimension *dim, lkvnc_rfb_PixelFormat *pf)
  {
    AutoLock al(&m_fbLocMut);
    *dim = m_backupFrameBuffer.getDimension();
    *pf = m_backupFrameBuffer.getPixelFormat();
  }

  void initFrameBuffer(const lkvnc_rfb_FrameBuffer *newFb);

  virtual bool updateExternalFrameBuffer(lkvnc_rfb_FrameBuffer *fb, const Region *region,
                                         const Rect *viewPort);

  // FIXME: It's no good idea to place this function to here.
  // Because it uses only for the UpdateHandlerClient class.
  virtual void sendInit(BlockingGate *gate) {}

protected:
  virtual bool updateExternalFrameBuffer(lkvnc_rfb_FrameBuffer *dstFb, lkvnc_rfb_FrameBuffer *srcFb,
                                         const Region *region,
                                         const Rect *viewPort);

  lkvnc_rfb_FrameBuffer m_backupFrameBuffer;
  LocalMutex m_fbLocMut;

  // m_cursorShape not thread safed
  lkvnc_rfb_CursorShape m_cursorShape;
};

#endif // __UPDATEHANDLER_H__
