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

#include <crtdbg.h>
#include "lkvnc_rfb_FrameBuffer.h"
#include <string.h>

lkvnc_rfb_FrameBuffer::lkvnc_rfb_FrameBuffer(void)
: m_buffer(0), displayCount(0)
{
  memset(&m_pixelFormat, 0, sizeof(m_pixelFormat));
}

lkvnc_rfb_FrameBuffer::~lkvnc_rfb_FrameBuffer(void)
{
  if (m_buffer != 0) {
    delete []m_buffer;
  }
}

bool lkvnc_rfb_FrameBuffer::assignProperties(const lkvnc_rfb_FrameBuffer *srcFrameBuffer)
{
  Dimension tmpDimension = srcFrameBuffer->getDimension();
  lkvnc_rfb_PixelFormat tmpPixelFormat = srcFrameBuffer->getPixelFormat();
  setProperties(&tmpDimension,
                &tmpPixelFormat);
  return resizeBuffer();
}

bool lkvnc_rfb_FrameBuffer::clone(const lkvnc_rfb_FrameBuffer *srcFrameBuffer)
{
  if (!assignProperties(srcFrameBuffer)) {
    return false;
  }
  //Dimension tmpDimension = m_dimension;
  Rect tmpRect = m_dimension.getRect();
  Rect fbRect = &tmpRect;
  copyFrom(&fbRect, srcFrameBuffer, fbRect.left, fbRect.top);

  return true;
}

void lkvnc_rfb_FrameBuffer::setColor(UINT8 red, UINT8 green, UINT8 blue)
{
  //size_t sizeInPixels = m_dimension.area();
  int pixelSize = m_pixelFormat.bitsPerPixel / 8;
  UINT32 redPix = (red * m_pixelFormat.redMax / 255) <<
                  m_pixelFormat.redShift;
  UINT32 greenPix = (green * m_pixelFormat.greenMax / 255) <<
                    m_pixelFormat.greenShift;
  UINT32 bluePix = (blue * m_pixelFormat.blueMax / 255) <<
                   m_pixelFormat.blueShift;
  UINT32 color = redPix | greenPix | bluePix;

  UINT8 *endPixPtr = (UINT8 *)m_buffer + getBufferSize();
  UINT8 *pixPtr = (UINT8 *)m_buffer;
  for (; pixPtr <= endPixPtr - pixelSize; pixPtr += pixelSize) {
    memcpy(pixPtr, &color, pixelSize);
  }
}

void lkvnc_rfb_FrameBuffer::fillRect(const Rect *dstRect, UINT32 color)
{
  Rect clipRect = m_dimension.getRect().intersection(dstRect);

  int pixelSize = getBytesPerPixel();
  size_t sizeLineFb = getBytesPerRow();
  size_t sizeLineRect = clipRect.getWidth() * pixelSize;

  // it's pointer to first line of rect
  UINT8 *srcLinePtr = reinterpret_cast<UINT8 *>(getBufferPtr(clipRect.left, clipRect.top));

  // it's pointer to pixel in first line
  UINT8 *pixPtr = srcLinePtr;
  for (int x = clipRect.left; x < clipRect.right; x++, pixPtr += pixelSize)
    memcpy(pixPtr, &color, pixelSize);

  // it's pointer to next line of rect
  UINT8 *dstLinePtr = srcLinePtr + sizeLineFb;
  for (int y = clipRect.top + 1; y < clipRect.bottom; y++, dstLinePtr += sizeLineFb)
    memcpy(dstLinePtr, srcLinePtr, sizeLineRect);
}

bool lkvnc_rfb_FrameBuffer::isEqualTo(const lkvnc_rfb_FrameBuffer *lkvnc_rfb_FrameBuffer)
{
  Dimension tmpDimension = lkvnc_rfb_FrameBuffer->getDimension();
  lkvnc_rfb_PixelFormat tmpPixelFormat = lkvnc_rfb_FrameBuffer->getPixelFormat();
  return m_dimension.cmpDim(&tmpDimension) &&
         m_pixelFormat.isEqualTo(&tmpPixelFormat);
}

void lkvnc_rfb_FrameBuffer::clipRect(const Rect *dstRect, const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                           const int srcX, const int srcY,
                           Rect *dstClippedRect, Rect *srcClippedRect)
{
  Rect dstBufferRect = m_dimension.getRect();
  Rect srcBufferRect = srcFrameBuffer->getDimension().getRect();

  // Building srcRect
  Rect srcRect(srcX, srcY, srcX + dstRect->getWidth(), srcY + dstRect->getHeight());

  // Finding common area between the dstRect, srcRect and the lkvnc_rfb_FrameBuffers
  Rect dstRectFB = dstBufferRect.intersection(dstRect);
  Rect srcRectFB = srcBufferRect.intersection(&srcRect);

  // Finding common area between the dstRectFB and the srcRectFB
  Rect dstCommonArea(&dstRectFB);
  Rect srcCommonArea(&srcRectFB);
  // Move to common place (left = 0, top = 0)
  dstCommonArea.move(-dstRect->left, -dstRect->top);
  srcCommonArea.move(-srcRect.left, -srcRect.top);

  Rect tmpRect = dstCommonArea.intersection(&srcCommonArea);
  Rect commonRect(&tmpRect);

  // Moving commonRect to destination coordinates and source
  dstClippedRect->setRect(&commonRect);
  dstClippedRect->move(dstRect->left, dstRect->top);

  srcClippedRect->setRect(&commonRect);
  srcClippedRect->move(srcRect.left, srcRect.top);
}

bool lkvnc_rfb_FrameBuffer::overlay(const Rect *dstRect,
                          const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                          int srcX, int srcY,
                          const char *andMask)
{
  lkvnc_rfb_PixelFormat tmpPixelFormat = srcFrameBuffer->getPixelFormat();
  if (!m_pixelFormat.isEqualTo(&tmpPixelFormat)) {
    return false;
  }
  if (m_pixelFormat.bitsPerPixel == 32) {
    return overlayT<UINT32>(dstRect, srcFrameBuffer, srcX, srcY, andMask);
  } else if (m_pixelFormat.bitsPerPixel == 16) {
    return overlayT<UINT16>(dstRect, srcFrameBuffer, srcX, srcY, andMask);
  } else if (m_pixelFormat.bitsPerPixel == 8) {
    return overlayT<UINT8>(dstRect, srcFrameBuffer, srcX, srcY, andMask);
  } else {
    _ASSERT(false);
  }
  return false;
}

template<class PIXEL_T> bool lkvnc_rfb_FrameBuffer::overlayT(const Rect *dstRect,
                                                   const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                                                   int srcX, int srcY,
                                                   const char *andMask)
{
  Rect srcClippedRect, dstClippedRect;

  clipRect(dstRect, srcFrameBuffer, srcX, srcY, &dstClippedRect, &srcClippedRect);
  if (dstClippedRect.area() <= 0 || srcClippedRect.area() <= 0) {
    return true;
  }

  PIXEL_T *dstPixels = (PIXEL_T *)getBuffer();
  PIXEL_T *srcPixels = (PIXEL_T *)srcFrameBuffer->getBuffer();
  int srcWidth = srcFrameBuffer->getDimension().width;
  int dstWidth = getDimension().width;
  size_t bytesPerRow = (srcWidth + 7) / 8;
  for (int iRow = srcClippedRect.top; iRow < srcClippedRect.bottom; iRow++) {
    for (int iCol = srcClippedRect.left; iCol < srcClippedRect.right; iCol++) {
      unsigned char curByte = andMask[iRow * bytesPerRow + iCol / 8];
      bool andBit = (curByte & 128 >> iCol % 8) != 0;
      if (andBit) {
        int iDstRow = dstClippedRect.top + iRow - srcY - srcClippedRect.top;
        int iDstCol = dstClippedRect.left + iCol - srcX - srcClippedRect.left;
        dstPixels[iDstRow * dstWidth + iDstCol] = srcPixels[iRow * srcWidth + iCol];
      }
    }
  }
  return true;
}

bool lkvnc_rfb_FrameBuffer::copyFrom(const Rect *dstRect, const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                           int srcX, int srcY)
{
  lkvnc_rfb_PixelFormat tmpPixelFormat = srcFrameBuffer->getPixelFormat();
  if (!m_pixelFormat.isEqualTo(&tmpPixelFormat)) {
    return false;
  }

  Rect srcClippedRect, dstClippedRect;

  clipRect(dstRect, srcFrameBuffer, srcX, srcY, &dstClippedRect, &srcClippedRect);
  if (dstClippedRect.area() <= 0 || srcClippedRect.area() <= 0) {
    return true;
  }

  // Shortcuts
  int pixelSize = m_pixelFormat.bitsPerPixel / 8;
  int dstStrideBytes = m_dimension.width * pixelSize;
  int srcStrideBytes = srcFrameBuffer->getDimension().width * pixelSize;

  int resultHeight = dstClippedRect.getHeight();
  int resultWidthBytes = dstClippedRect.getWidth() * pixelSize;

  UINT8 *pdst = (UINT8 *)m_buffer
                + dstClippedRect.top * dstStrideBytes
                + pixelSize * dstClippedRect.left;

  UINT8 *psrc = (UINT8 *)srcFrameBuffer->getBuffer()
                + srcClippedRect.top * srcStrideBytes
                + pixelSize * srcClippedRect.left;

  for (int i = 0; i < resultHeight; i++, pdst += dstStrideBytes, psrc += srcStrideBytes) {
    memcpy(pdst, psrc, resultWidthBytes);
  }

  return true;
}

bool lkvnc_rfb_FrameBuffer::copyFrom(const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                           int srcX, int srcY)
{
  Rect tmpRect = m_dimension.getRect();
  return copyFrom(&tmpRect, srcFrameBuffer, srcX, srcY);
}

bool lkvnc_rfb_FrameBuffer::cmpFrom(const Rect *dstRect, const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                          const int srcX, const int srcY)
{
  lkvnc_rfb_PixelFormat tmpPixelFormat = srcFrameBuffer->getPixelFormat();
  if (!m_pixelFormat.isEqualTo(&tmpPixelFormat)) {
    return false;
  }

  Rect srcClippedRect, dstClippedRect;

  clipRect(dstRect, srcFrameBuffer, srcX, srcY, &dstClippedRect, &srcClippedRect);
  if (dstClippedRect.area() <= 0 || srcClippedRect.area() <= 0) {
    return true;
  }

  // Shortcuts
  int pixelSize = m_pixelFormat.bitsPerPixel / 8;
  int dstStrideBytes = m_dimension.width * pixelSize;
  int srcStrideBytes = srcFrameBuffer->getDimension().width * pixelSize;

  int resultHeight = dstClippedRect.getHeight();
  int resultWidthBytes = dstClippedRect.getWidth() * pixelSize;

  UINT8 *pdst = (UINT8 *)m_buffer
                + dstClippedRect.top * dstStrideBytes
                + pixelSize * dstClippedRect.left;

  UINT8 *psrc = (UINT8 *)srcFrameBuffer->getBuffer()
                + srcClippedRect.top * srcStrideBytes
                + pixelSize * srcClippedRect.left;

  for (int i = 0; i < resultHeight; i++, pdst += dstStrideBytes, psrc += srcStrideBytes) {
    if (memcmp(pdst, psrc, resultWidthBytes) != 0) {
      return false;
    }
  }

  return true;
}

void lkvnc_rfb_FrameBuffer::move(const Rect *dstRect, const int srcX, const int srcY)
{
  Rect srcClippedRect, dstClippedRect;

  clipRect(dstRect, this, srcX, srcY, &dstClippedRect, &srcClippedRect);
  if (dstClippedRect.area() <= 0 || srcClippedRect.area() <= 0) {
    return;
  }

  // Data copy
  int pixelSize = m_pixelFormat.bitsPerPixel / 8;
  int strideBytes = m_dimension.width * pixelSize;

  int resultHeight = dstClippedRect.getHeight();
  int resultWidthBytes = dstClippedRect.getWidth() * pixelSize;

  UINT8 *pdst, *psrc;

  if (srcY > dstRect->top) {
    // Pointers set to first string of the rectanles
    pdst = (UINT8 *)m_buffer + dstClippedRect.top * strideBytes
           + pixelSize * dstClippedRect.left;
    psrc = (UINT8 *)m_buffer + srcClippedRect.top * strideBytes
           + pixelSize * srcClippedRect.left;

    for (int i = 0; i < resultHeight; i++, pdst += strideBytes, psrc += strideBytes) {
      memcpy(pdst, psrc, resultWidthBytes);
    }

  } else {
    // Pointers set to last string of the rectanles
    pdst = (UINT8 *)m_buffer + (dstClippedRect.bottom - 1) * strideBytes
           + pixelSize * dstClippedRect.left;
    psrc = (UINT8 *)m_buffer + (srcClippedRect.bottom - 1) * strideBytes
           + pixelSize * srcClippedRect.left;

    for (int i = resultHeight - 1; i >= 0; i--, pdst -= strideBytes, psrc -= strideBytes) {
      memmove(pdst, psrc, resultWidthBytes);
    }
  }
}

bool lkvnc_rfb_FrameBuffer::setPixelFormat(const lkvnc_rfb_PixelFormat *lkvnc_rfb_PixelFormat)
{
  m_pixelFormat = *lkvnc_rfb_PixelFormat;
  return resizeBuffer();
}

bool lkvnc_rfb_FrameBuffer::setDimension(const Dimension *newDim)
{
  m_dimension = *newDim;
  return resizeBuffer();
}

void lkvnc_rfb_FrameBuffer::setEmptyDimension(const Rect *dimByRect)
{
  m_dimension.setDim(dimByRect);
}

void lkvnc_rfb_FrameBuffer::setEmptyPixelFmt(const lkvnc_rfb_PixelFormat *pf)
{
  m_pixelFormat = *pf;
}

void lkvnc_rfb_FrameBuffer::setPropertiesWithoutResize(const Dimension *newDim, const lkvnc_rfb_PixelFormat *pf)
{
  m_dimension = *newDim;
  m_pixelFormat = *pf;
}

bool lkvnc_rfb_FrameBuffer::setProperties(const Dimension *newDim,
                                const lkvnc_rfb_PixelFormat *lkvnc_rfb_PixelFormat)
{
  m_pixelFormat = *lkvnc_rfb_PixelFormat;
  m_dimension = *newDim;
  return resizeBuffer();
}

bool lkvnc_rfb_FrameBuffer::setProperties(const Rect *dimByRect,
                                const lkvnc_rfb_PixelFormat *lkvnc_rfb_PixelFormat)
{
  m_pixelFormat = *lkvnc_rfb_PixelFormat;
  m_dimension.setDim(dimByRect);
  return resizeBuffer();
}

UINT8 lkvnc_rfb_FrameBuffer::getBitsPerPixel() const
{
  _ASSERT((UINT8)m_pixelFormat.bitsPerPixel == m_pixelFormat.bitsPerPixel);
  return (UINT8)m_pixelFormat.bitsPerPixel;
}

UINT8 lkvnc_rfb_FrameBuffer::getBytesPerPixel() const
{
  return (UINT8)(m_pixelFormat.bitsPerPixel / 8);
}

void *lkvnc_rfb_FrameBuffer::getBufferPtr(int x, int y) const
{
  char *ptr = (char *)m_buffer;
  ptr += (y * m_dimension.width + x) * getBytesPerPixel();

  return (void *)ptr;
}

int lkvnc_rfb_FrameBuffer::getBufferSize() const
{
  return (m_dimension.area() * m_pixelFormat.bitsPerPixel) / 8;
}

bool lkvnc_rfb_FrameBuffer::resizeBuffer()
{
  if (m_buffer != 0) {
    delete []m_buffer;
  }
  if ((m_buffer = new UINT8[getBufferSize()]) == 0) {
    return false;
  }
  return true;
}
