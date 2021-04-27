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

#include "lkvnc_rfb_CursorShape.h"

lkvnc_rfb_CursorShape::~lkvnc_rfb_CursorShape()
{
}

bool lkvnc_rfb_CursorShape::clone(const lkvnc_rfb_CursorShape *srcCursorShape)
{
  m_hotSpot = srcCursorShape->getHotSpot();
  if (m_pixels.clone(srcCursorShape->getPixels())) {
    m_mask = srcCursorShape->m_mask;
    return true;
  } else {
    return false;
  }
}

void lkvnc_rfb_CursorShape::assignMaskFromRfb(const char *srcMask)
{
  if (!m_mask.empty()) {
    int height = m_pixels.getDimension().height;
    size_t rfbWidthInBytes = getMaskWidthInBytes();
    size_t maskLen = height * rfbWidthInBytes;
    memcpy(&m_mask.front(), srcMask, maskLen);
  }
}

void lkvnc_rfb_CursorShape::assignMaskFromWindows(const char *srcMask)
{
  if (!m_mask.empty()) {
    int height = m_pixels.getDimension().height;
    int winWidthInBytes = ((m_pixels.getDimension().width + 15) / 16) * 2;
    int rfbWidthInBytes = getMaskWidthInBytes();
    for (int i = 0; i < height; i++) {
      memcpy(&m_mask[i * rfbWidthInBytes],
             &srcMask[i * winWidthInBytes],
             rfbWidthInBytes);
    }
  }
}

bool lkvnc_rfb_CursorShape::setDimension(const Dimension *newDim)
{
  bool result = m_pixels.setDimension(newDim);
  return result && resizeBuffer();
}

bool lkvnc_rfb_CursorShape::setPixelFormat(const lkvnc_rfb_PixelFormat *pixFormat)
{
  bool result = m_pixels.setPixelFormat(pixFormat);
  return result && resizeBuffer();
}

bool lkvnc_rfb_CursorShape::setProperties(const Dimension *newDim,
                                const lkvnc_rfb_PixelFormat *lkvnc_rfb_PixelFormat)
{
  bool result = m_pixels.setDimension(newDim) &&
                m_pixels.setPixelFormat(lkvnc_rfb_PixelFormat);
  return result && resizeBuffer();
}

void lkvnc_rfb_CursorShape::resetToEmpty()
{
  Dimension tmpDimension = Dimension(0, 0);
  setDimension(&tmpDimension);
  setHotSpot(0, 0);
}

bool lkvnc_rfb_CursorShape::resizeBuffer()
{
  m_mask.resize(getMaskSize());
  return true;
}

int lkvnc_rfb_CursorShape::getMaskSize() const
{
  return getMaskWidthInBytes() * m_pixels.getDimension().height;
}

int lkvnc_rfb_CursorShape::getMaskWidthInBytes() const
{
  return (m_pixels.getDimension().width + 7) / 8;
}
