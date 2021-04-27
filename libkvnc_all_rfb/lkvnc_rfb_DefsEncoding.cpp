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

#include "lkvnc_rfb_DefsEncoding.h"

const char *const lkvnc_rfb_DefsEncoding::SIG_RAW = "RAW_____";
const char *const lkvnc_rfb_DefsEncoding::SIG_COPYRECT = "COPYRECT";
const char *const lkvnc_rfb_DefsEncoding::SIG_RRE = "RRE_____";
const char *const lkvnc_rfb_DefsEncoding::SIG_HEXTILE = "HEXTILE_";
const char *const lkvnc_rfb_DefsEncoding::SIG_TIGHT = "TIGHT___";
const char *const lkvnc_rfb_DefsEncoding::SIG_ZRLE = "ZRLE____";

const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_COMPR_LEVEL = "COMPRLVL";
const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_X_CURSOR = "X11CURSR";
const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_RICH_CURSOR = "RCHCURSR";
const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_POINTER_POS = "POINTPOS";
const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_LAST_RECT = "LASTRECT";
const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_DESKTOP_SIZE = "NEWFBSIZ";
const char *const lkvnc_rfb_DefsEncoding__Pseudo::SIG_QUALITY_LEVEL = "JPEGQLVL";
