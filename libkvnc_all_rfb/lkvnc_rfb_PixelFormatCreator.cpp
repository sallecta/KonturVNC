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

#include "lkvnc_rfb_PixelFormatCreator.h"


lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormatCreator::create32bppPixelFormat()
{
  lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormat;
  lkvnc_rfb_PixelFormat.initBigEndianByNative();
  lkvnc_rfb_PixelFormat.bitsPerPixel = 32;
  lkvnc_rfb_PixelFormat.blueMax = 255;
  lkvnc_rfb_PixelFormat.blueShift = 0;
  lkvnc_rfb_PixelFormat.greenMax = 255;
  lkvnc_rfb_PixelFormat.greenShift = 8;
  lkvnc_rfb_PixelFormat.redMax = 255;
  lkvnc_rfb_PixelFormat.redShift = 16;
  lkvnc_rfb_PixelFormat.colorDepth = 24;
  return lkvnc_rfb_PixelFormat;
}

lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormatCreator::create16bppPixelFormat()
{
  lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormat;
  lkvnc_rfb_PixelFormat.initBigEndianByNative();
  lkvnc_rfb_PixelFormat.bitsPerPixel = 16;
  lkvnc_rfb_PixelFormat.blueMax = 31;
  lkvnc_rfb_PixelFormat.blueShift = 0;
  lkvnc_rfb_PixelFormat.greenMax = 63;
  lkvnc_rfb_PixelFormat.greenShift = 5;
  lkvnc_rfb_PixelFormat.redMax = 31;
  lkvnc_rfb_PixelFormat.redShift = 11;
  lkvnc_rfb_PixelFormat.colorDepth = 16;
  return lkvnc_rfb_PixelFormat;
}

lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormatCreator::create8bppPixelFormat()
{
  lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormat;
  lkvnc_rfb_PixelFormat.initBigEndianByNative();
  lkvnc_rfb_PixelFormat.bitsPerPixel = 8;
  lkvnc_rfb_PixelFormat.redMax = 7;
  lkvnc_rfb_PixelFormat.redShift = 0;
  lkvnc_rfb_PixelFormat.greenMax = 7;
  lkvnc_rfb_PixelFormat.greenShift = 3;
  lkvnc_rfb_PixelFormat.blueMax = 3;
  lkvnc_rfb_PixelFormat.blueShift = 6;
  lkvnc_rfb_PixelFormat.colorDepth = 8;
  return lkvnc_rfb_PixelFormat;
}

lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormatCreator::create6bppPixelFormat()
{
  lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormat;
  lkvnc_rfb_PixelFormat.initBigEndianByNative();
  lkvnc_rfb_PixelFormat.bitsPerPixel = 8;
  lkvnc_rfb_PixelFormat.blueMax = 3;
  lkvnc_rfb_PixelFormat.blueShift = 0;
  lkvnc_rfb_PixelFormat.greenMax = 3;
  lkvnc_rfb_PixelFormat.greenShift = 2;
  lkvnc_rfb_PixelFormat.redMax = 3;
  lkvnc_rfb_PixelFormat.redShift = 4;
  lkvnc_rfb_PixelFormat.colorDepth = 6;
  return lkvnc_rfb_PixelFormat;
}

lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormatCreator::create3bppPixelFormat()
{
  lkvnc_rfb_PixelFormat lkvnc_rfb_PixelFormat;
  lkvnc_rfb_PixelFormat.initBigEndianByNative();
  lkvnc_rfb_PixelFormat.bitsPerPixel = 8;
  lkvnc_rfb_PixelFormat.blueMax = 1;
  lkvnc_rfb_PixelFormat.blueShift = 0;
  lkvnc_rfb_PixelFormat.greenMax = 1;
  lkvnc_rfb_PixelFormat.greenShift = 1;
  lkvnc_rfb_PixelFormat.redMax = 1;
  lkvnc_rfb_PixelFormat.redShift = 2;
  lkvnc_rfb_PixelFormat.colorDepth = 3;
  return lkvnc_rfb_PixelFormat;
}
