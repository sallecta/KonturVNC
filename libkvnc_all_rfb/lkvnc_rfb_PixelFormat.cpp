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

#include "lkvnc_rfb_PixelFormat.h"

#include <string.h>

lkvnc_rfb_PixelFormat::lkvnc_rfb_PixelFormat()
{
  memset(this, 0, sizeof(lkvnc_rfb_PixelFormat));
}

void lkvnc_rfb_PixelFormat::initBigEndianByNative()
{
  union {
    char test;
    int i;
  } testBigEndian;
  testBigEndian.i = 1;
  bigEndian = (testBigEndian.test == 0);
}

bool lkvnc_rfb_PixelFormat::isEqualTo(const lkvnc_rfb_PixelFormat *argPixelFormat) const {
  return bitsPerPixel == argPixelFormat->bitsPerPixel &&
         colorDepth   == argPixelFormat->colorDepth &&
         redMax       == argPixelFormat->redMax &&
         greenMax     == argPixelFormat->greenMax &&
         blueMax      == argPixelFormat->blueMax &&
         redShift     == argPixelFormat->redShift &&
         greenShift   == argPixelFormat->greenShift &&
         blueShift    == argPixelFormat->blueShift &&
         bigEndian    == argPixelFormat->bigEndian;
}
