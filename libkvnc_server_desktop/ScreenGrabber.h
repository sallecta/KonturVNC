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

#ifndef __SCREENGRABBER_H__
#define __SCREENGRABBER_H__

#include "../libkvnc_all_region/Rect.h"
#include "../libkvnc_all_region/Dimension.h"
#include "../libkvnc_all_region/Point.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_PixelFormat.h"
#include "../libkvnc_all_rfb/lkvnc_rfb_FrameBuffer.h"

//
// An abstract interface for screen grabbing.
//

/*
  //
  // Usage example:
  //

  ScreenGrabber *lkvnc_rfb_FrameBuffer;

  // Initialisation
  lkvnc_rfb_FrameBuffer = new WindowsScreenGrabber;

  Rect grabRect, workRect;
  workRect.setRect(100, 100, 500, 500);
  grabRect.setRect(20, 20, 120, 120); // Relative to the workRect
  lkvnc_rfb_FrameBuffer->setWorkRect(&workRect);

  // One-time grabbing
  while (!lkvnc_rfb_FrameBuffer->grab(&grabRect)) {
    if (lkvnc_rfb_FrameBuffer->getPropertiesChanged()) { // Check desktop properties
      if (!lkvnc_rfb_FrameBuffer->applyNewProperties()) {
        MessageBox(NULL, _T("Cannot apply new screen properties"), _T("Error"), MB_ICONHAND);
        return 1;
      }
    } else {
      MessageBox(NULL, _T("Cannot grab screen"), _T("Error"), MB_ICONHAND);
      return 1;
    }
  }
*/

class ScreenGrabber
{
public:
  // Derived constructors will ensure that the getScreenBuffer() returns
  // a frame buffer with valid screen properties.
  ScreenGrabber(void);
  virtual ~ScreenGrabber(void);

  /* Provides grabbing.
  Parameters:     *rect - Pointer to a Rect object with relative workRect coordinates.
  Return value:   true if success.
  */
  virtual bool grab(const Rect *rect = 0) = 0;

  virtual lkvnc_rfb_FrameBuffer *getScreenBuffer() { return &m_workFrameBuffer; }
  virtual void setWorkRect(Rect *workRect);
  virtual Rect getWorkRect() const { return Rect(m_offsetFrameBuffer.x,
                                                 m_offsetFrameBuffer.y,
                                                 m_workFrameBuffer.getDimension().width +
                                                 m_offsetFrameBuffer.x,
                                                 m_workFrameBuffer.getDimension().height +
                                                 m_offsetFrameBuffer.y); }
  /* Provides read access to rectangular coordinates of the screen (desktop).*/
  virtual Rect getScreenRect() { return m_fullScreenRect; }

  // Checks screen(desktop) properties on changes
  inline virtual bool getPropertiesChanged() = 0;
  inline virtual bool getPixelFormatChanged() = 0;
  inline virtual bool getScreenSizeChanged() = 0;

  // Set new values of the WorkRect to default (to full screen rectangle coordinates)
  // and m_fullScreenRect if desktop properties has been changed.
  // Also m_pixelFormat set to actual value.
  virtual bool applyNewProperties();

protected:
  virtual bool applyNewFullScreenRect() = 0;
  virtual bool applyNewPixelFormat() = 0;

  virtual bool setWorkRectDefault();

  Rect m_fullScreenRect;
  Point m_offsetFrameBuffer;

  lkvnc_rfb_FrameBuffer m_workFrameBuffer;
};

#endif // __SCREENGRABBER_H__
