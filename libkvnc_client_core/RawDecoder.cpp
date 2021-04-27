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

#include "RawDecoder.h"

RawDecoder::RawDecoder(LogWriter *logWriter)
: DecoderOfRectangle(logWriter)
{
  m_encoding = lkvnc_rfb_DefsEncoding::RAW;
}

RawDecoder::~RawDecoder()
{
}

void RawDecoder::process(RfbInputGate *input,
                         lkvnc_rfb_FrameBuffer *argFrameBuffer,
                         lkvnc_rfb_FrameBuffer *secondFrameBuffer,
                         const Rect *rect,
                         LocalMutex *fbLock,
                         FbUpdateNotifier *fbNotifier)
{
  // If area of rectangle is 0, then exit from process: nothing update.
  if (rect->area() == 0) {
    return;
  }

  int width = rect->getWidth();
  //int height = rect->getHeight();

  // Division with round to up.
  int deltaHeight = (AREA_OF_ONE_PART + width - 1) / width;

  Rect deltaRect(width, deltaHeight);
  deltaRect.setLocation(rect->left, rect->top);

  // Process all rectangle without last part of rectangle or
  // two last part, if area of last part is less half of AREA_OF_ONE_PART.
  while (deltaRect.bottom + deltaHeight / 2 < rect->bottom) {
    DecoderOfRectangle::process(input, argFrameBuffer, secondFrameBuffer, &deltaRect, fbLock,
                                fbNotifier);

    // Increment position of rectangle.
    deltaRect.move(0, deltaHeight);
  }

  // And process remainder parts of rectangle.
  deltaRect.top = std::max(rect->top, deltaRect.bottom - deltaHeight);
  deltaRect.bottom = rect->bottom;
  DecoderOfRectangle::process(input, argFrameBuffer, secondFrameBuffer, &deltaRect, fbLock,
                              fbNotifier);
}

void RawDecoder::decode(RfbInputGate *input,
                     lkvnc_rfb_FrameBuffer *lkvnc_rfb_FrameBuffer,
                     const Rect *rect)
{
  size_t bytesPerPixel = lkvnc_rfb_FrameBuffer->getPixelFormat().bitsPerPixel / 8;
  size_t bytesPerLine = bytesPerPixel * rect->getWidth();

  if (!lkvnc_rfb_FrameBuffer->getDimension().getRect().intersection(rect).isEqualTo(rect))
    throw Exception(_T("Error in protocol: incorrect size of rectangle"));
  for (int y = rect->top; y < rect->bottom; y++)
    input->readFully(lkvnc_rfb_FrameBuffer->getBufferPtr(rect->left, y), bytesPerLine);
}
