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

#include "CopyRectDecoder.h"

CopyRectDecoder::CopyRectDecoder(LogWriter *logWriter)
: DecoderOfRectangle(logWriter)
{
  m_encoding = lkvnc_rfb_DefsEncoding::COPYRECT;
}

CopyRectDecoder::~CopyRectDecoder()
{
}

void CopyRectDecoder::decode(RfbInputGate *input,
                             lkvnc_rfb_FrameBuffer *lkvnc_rfb_FrameBuffer,
                             const Rect *dstRect)
{
  m_sourcePosition.x = input->readInt16();
  m_sourcePosition.y = input->readInt16();
}

void CopyRectDecoder::copy(lkvnc_rfb_FrameBuffer *dstFrameBuffer,
                           const lkvnc_rfb_FrameBuffer *srcFrameBuffer,
                           const Rect *rect,
                           LocalMutex *fbLock)
{
  AutoLock al(fbLock);
  dstFrameBuffer->move(rect, m_sourcePosition.x, m_sourcePosition.y);
}
