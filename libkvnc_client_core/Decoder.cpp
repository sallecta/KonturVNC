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
#include <crtdbg.h>
#include "Decoder.h"

Decoder::Decoder(LogWriter *logWriter)
: m_logWriter(logWriter)
{
}

Decoder::~Decoder()
{
}

int Decoder::getCode() const
{
  return m_encoding;
}

bool Decoder::isPseudo() const
{
  return isPseudo(getCode());
}

bool Decoder::isPseudo(int encoding)
{
  switch (encoding) {
  case lkvnc_rfb_DefsEncoding::RAW:
  case lkvnc_rfb_DefsEncoding::COPYRECT:
  case lkvnc_rfb_DefsEncoding::RRE:
  case lkvnc_rfb_DefsEncoding::HEXTILE:
  case lkvnc_rfb_DefsEncoding::TIGHT:
  case lkvnc_rfb_DefsEncoding::ZRLE:
    return false;

  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_0:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_1:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_2:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_3:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_4:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_5:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_6:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_7:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_8:
  case lkvnc_rfb_DefsEncoding__Pseudo::COMPR_LEVEL_9:

  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_0:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_1:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_2:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_3:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_4:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_5:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_6:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_7:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_8:
  case lkvnc_rfb_DefsEncoding__Pseudo::QUALITY_LEVEL_9:

  case lkvnc_rfb_DefsEncoding__Pseudo::DESKTOP_SIZE:
  case lkvnc_rfb_DefsEncoding__Pseudo::X_CURSOR:
  case lkvnc_rfb_DefsEncoding__Pseudo::RICH_CURSOR:
  case lkvnc_rfb_DefsEncoding__Pseudo::POINTER_POS:
  case lkvnc_rfb_DefsEncoding__Pseudo::LAST_RECT:
    return true;
  default:
    // if the encoding type is unknown, then generate assertions.
    _ASSERT(TRUE);
    return true;
  }
}
