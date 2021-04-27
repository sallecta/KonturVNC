/* $TOG: keysymdef.h /main/28 1998/05/22 16:18:01 kaleb $ */

/***********************************************************
Copyright 1987, 1994, 1998  The Open Group

All Rights Reserved.

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall
not be used in advertising or otherwise to promote the sale, use or
other dealings in this Software without prior written authorization
from The Open Group.


Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its
documentation for any purpose and without fee is hereby granted,
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

#define lkvnc_rfb_DefsKeySym_VoidSymbol		0xFFFFFF	/* void symbol */

#ifdef lkvnc_rfb_DefsKeySym_MISCELLANY
/*
 * TTY Functions, cleverly chosen to map to ascii, for convenience of
 * programming, but could have been arbitrary (at the cost of lookup
 * tables in client code.
 */

#define lkvnc_rfb_DefsKeySym_BackSpace		0xFF08	/* back space, back char */
#define lkvnc_rfb_DefsKeySym_Tab			0xFF09
#define lkvnc_rfb_DefsKeySym_Linefeed		0xFF0A	/* Linefeed, LF */
#define lkvnc_rfb_DefsKeySym_Clear		0xFF0B
#define lkvnc_rfb_DefsKeySym_Return		0xFF0D	/* Return, enter */
#define lkvnc_rfb_DefsKeySym_Pause		0xFF13	/* Pause, hold */
#define lkvnc_rfb_DefsKeySym_Scroll_Lock		0xFF14
#define lkvnc_rfb_DefsKeySym_Sys_Req		0xFF15
#define lkvnc_rfb_DefsKeySym_Escape		0xFF1B
#define lkvnc_rfb_DefsKeySym_Delete		0xFFFF	/* Delete, rubout */



/* International & multi-key character composition */

#define lkvnc_rfb_DefsKeySym_Multi_key		0xFF20  /* Multi-key character compose */
#define lkvnc_rfb_DefsKeySym_Codeinput		0xFF37
#define lkvnc_rfb_DefsKeySym_SingleCandidate	0xFF3C
#define lkvnc_rfb_DefsKeySym_MultipleCandidate	0xFF3D
#define lkvnc_rfb_DefsKeySym_PreviousCandidate	0xFF3E

/* Japanese keyboard support */

#define lkvnc_rfb_DefsKeySym_Kanji		0xFF21	/* Kanji, Kanji convert */
#define lkvnc_rfb_DefsKeySym_Muhenkan		0xFF22  /* Cancel Conversion */
#define lkvnc_rfb_DefsKeySym_Henkan_Mode		0xFF23  /* Start/Stop Conversion */
#define lkvnc_rfb_DefsKeySym_Henkan		0xFF23  /* Alias for Henkan_Mode */
#define lkvnc_rfb_DefsKeySym_Romaji		0xFF24  /* to Romaji */
#define lkvnc_rfb_DefsKeySym_Hiragana		0xFF25  /* to Hiragana */
#define lkvnc_rfb_DefsKeySym_Katakana		0xFF26  /* to Katakana */
#define lkvnc_rfb_DefsKeySym_Hiragana_Katakana	0xFF27  /* Hiragana/Katakana toggle */
#define lkvnc_rfb_DefsKeySym_Zenkaku		0xFF28  /* to Zenkaku */
#define lkvnc_rfb_DefsKeySym_Hankaku		0xFF29  /* to Hankaku */
#define lkvnc_rfb_DefsKeySym_Zenkaku_Hankaku	0xFF2A  /* Zenkaku/Hankaku toggle */
#define lkvnc_rfb_DefsKeySym_Touroku		0xFF2B  /* Add to Dictionary */
#define lkvnc_rfb_DefsKeySym_Massyo		0xFF2C  /* Delete from Dictionary */
#define lkvnc_rfb_DefsKeySym_Kana_Lock		0xFF2D  /* Kana Lock */
#define lkvnc_rfb_DefsKeySym_Kana_Shift		0xFF2E  /* Kana Shift */
#define lkvnc_rfb_DefsKeySym_Eisu_Shift		0xFF2F  /* Alphanumeric Shift */
#define lkvnc_rfb_DefsKeySym_Eisu_toggle		0xFF30  /* Alphanumeric toggle */
#define lkvnc_rfb_DefsKeySym_Kanji_Bangou		0xFF37  /* Codeinput */
#define lkvnc_rfb_DefsKeySym_Zen_Koho		0xFF3D	/* Multiple/All Candidate(s) */
#define lkvnc_rfb_DefsKeySym_Mae_Koho		0xFF3E	/* Previous Candidate */

/* 0xFF31 thru 0xFF3F are under lkvnc_rfb_DefsKeySym_KOREAN */

/* Cursor control & motion */

#define lkvnc_rfb_DefsKeySym_Home			0xFF50
#define lkvnc_rfb_DefsKeySym_Left			0xFF51	/* Move left, left arrow */
#define lkvnc_rfb_DefsKeySym_Up			0xFF52	/* Move up, up arrow */
#define lkvnc_rfb_DefsKeySym_Right		0xFF53	/* Move right, right arrow */
#define lkvnc_rfb_DefsKeySym_Down			0xFF54	/* Move down, down arrow */
#define lkvnc_rfb_DefsKeySym_Prior		0xFF55	/* Prior, previous */
#define lkvnc_rfb_DefsKeySym_Page_Up		0xFF55
#define lkvnc_rfb_DefsKeySym_Next			0xFF56	/* Next */
#define lkvnc_rfb_DefsKeySym_Page_Down		0xFF56
#define lkvnc_rfb_DefsKeySym_End			0xFF57	/* EOL */
#define lkvnc_rfb_DefsKeySym_Begin		0xFF58	/* BOL */


/* Misc Functions */

#define lkvnc_rfb_DefsKeySym_Select		0xFF60	/* Select, mark */
#define lkvnc_rfb_DefsKeySym_Print		0xFF61
#define lkvnc_rfb_DefsKeySym_Execute		0xFF62	/* Execute, run, do */
#define lkvnc_rfb_DefsKeySym_Insert		0xFF63	/* Insert, insert here */
#define lkvnc_rfb_DefsKeySym_Undo			0xFF65	/* Undo, oops */
#define lkvnc_rfb_DefsKeySym_Redo			0xFF66	/* redo, again */
#define lkvnc_rfb_DefsKeySym_Menu			0xFF67
#define lkvnc_rfb_DefsKeySym_Find			0xFF68	/* Find, search */
#define lkvnc_rfb_DefsKeySym_Cancel		0xFF69	/* Cancel, stop, abort, exit */
#define lkvnc_rfb_DefsKeySym_Help			0xFF6A	/* Help */
#define lkvnc_rfb_DefsKeySym_Break		0xFF6B
#define lkvnc_rfb_DefsKeySym_Mode_switch		0xFF7E	/* Character set switch */
#define lkvnc_rfb_DefsKeySym_script_switch        0xFF7E  /* Alias for mode_switch */
#define lkvnc_rfb_DefsKeySym_Num_Lock		0xFF7F

/* Keypad Functions, keypad numbers cleverly chosen to map to ascii */

#define lkvnc_rfb_DefsKeySym_KP_Space		0xFF80	/* space */
#define lkvnc_rfb_DefsKeySym_KP_Tab		0xFF89
#define lkvnc_rfb_DefsKeySym_KP_Enter		0xFF8D	/* enter */
#define lkvnc_rfb_DefsKeySym_KP_F1		0xFF91	/* PF1, KP_A, ... */
#define lkvnc_rfb_DefsKeySym_KP_F2		0xFF92
#define lkvnc_rfb_DefsKeySym_KP_F3		0xFF93
#define lkvnc_rfb_DefsKeySym_KP_F4		0xFF94
#define lkvnc_rfb_DefsKeySym_KP_Home		0xFF95
#define lkvnc_rfb_DefsKeySym_KP_Left		0xFF96
#define lkvnc_rfb_DefsKeySym_KP_Up		0xFF97
#define lkvnc_rfb_DefsKeySym_KP_Right		0xFF98
#define lkvnc_rfb_DefsKeySym_KP_Down		0xFF99
#define lkvnc_rfb_DefsKeySym_KP_Prior		0xFF9A
#define lkvnc_rfb_DefsKeySym_KP_Page_Up		0xFF9A
#define lkvnc_rfb_DefsKeySym_KP_Next		0xFF9B
#define lkvnc_rfb_DefsKeySym_KP_Page_Down		0xFF9B
#define lkvnc_rfb_DefsKeySym_KP_End		0xFF9C
#define lkvnc_rfb_DefsKeySym_KP_Begin		0xFF9D
#define lkvnc_rfb_DefsKeySym_KP_Insert		0xFF9E
#define lkvnc_rfb_DefsKeySym_KP_Delete		0xFF9F
#define lkvnc_rfb_DefsKeySym_KP_Equal		0xFFBD	/* equals */
#define lkvnc_rfb_DefsKeySym_KP_Multiply		0xFFAA
#define lkvnc_rfb_DefsKeySym_KP_Add		0xFFAB
#define lkvnc_rfb_DefsKeySym_KP_Separator		0xFFAC	/* separator, often comma */
#define lkvnc_rfb_DefsKeySym_KP_Subtract		0xFFAD
#define lkvnc_rfb_DefsKeySym_KP_Decimal		0xFFAE
#define lkvnc_rfb_DefsKeySym_KP_Divide		0xFFAF

#define lkvnc_rfb_DefsKeySym_KP_0			0xFFB0
#define lkvnc_rfb_DefsKeySym_KP_1			0xFFB1
#define lkvnc_rfb_DefsKeySym_KP_2			0xFFB2
#define lkvnc_rfb_DefsKeySym_KP_3			0xFFB3
#define lkvnc_rfb_DefsKeySym_KP_4			0xFFB4
#define lkvnc_rfb_DefsKeySym_KP_5			0xFFB5
#define lkvnc_rfb_DefsKeySym_KP_6			0xFFB6
#define lkvnc_rfb_DefsKeySym_KP_7			0xFFB7
#define lkvnc_rfb_DefsKeySym_KP_8			0xFFB8
#define lkvnc_rfb_DefsKeySym_KP_9			0xFFB9



/*
 * Auxilliary Functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufactures have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

#define lkvnc_rfb_DefsKeySym_F1			0xFFBE
#define lkvnc_rfb_DefsKeySym_F2			0xFFBF
#define lkvnc_rfb_DefsKeySym_F3			0xFFC0
#define lkvnc_rfb_DefsKeySym_F4			0xFFC1
#define lkvnc_rfb_DefsKeySym_F5			0xFFC2
#define lkvnc_rfb_DefsKeySym_F6			0xFFC3
#define lkvnc_rfb_DefsKeySym_F7			0xFFC4
#define lkvnc_rfb_DefsKeySym_F8			0xFFC5
#define lkvnc_rfb_DefsKeySym_F9			0xFFC6
#define lkvnc_rfb_DefsKeySym_F10			0xFFC7
#define lkvnc_rfb_DefsKeySym_F11			0xFFC8
#define lkvnc_rfb_DefsKeySym_L1			0xFFC8
#define lkvnc_rfb_DefsKeySym_F12			0xFFC9
#define lkvnc_rfb_DefsKeySym_L2			0xFFC9
#define lkvnc_rfb_DefsKeySym_F13			0xFFCA
#define lkvnc_rfb_DefsKeySym_L3			0xFFCA
#define lkvnc_rfb_DefsKeySym_F14			0xFFCB
#define lkvnc_rfb_DefsKeySym_L4			0xFFCB
#define lkvnc_rfb_DefsKeySym_F15			0xFFCC
#define lkvnc_rfb_DefsKeySym_L5			0xFFCC
#define lkvnc_rfb_DefsKeySym_F16			0xFFCD
#define lkvnc_rfb_DefsKeySym_L6			0xFFCD
#define lkvnc_rfb_DefsKeySym_F17			0xFFCE
#define lkvnc_rfb_DefsKeySym_L7			0xFFCE
#define lkvnc_rfb_DefsKeySym_F18			0xFFCF
#define lkvnc_rfb_DefsKeySym_L8			0xFFCF
#define lkvnc_rfb_DefsKeySym_F19			0xFFD0
#define lkvnc_rfb_DefsKeySym_L9			0xFFD0
#define lkvnc_rfb_DefsKeySym_F20			0xFFD1
#define lkvnc_rfb_DefsKeySym_L10			0xFFD1
#define lkvnc_rfb_DefsKeySym_F21			0xFFD2
#define lkvnc_rfb_DefsKeySym_R1			0xFFD2
#define lkvnc_rfb_DefsKeySym_F22			0xFFD3
#define lkvnc_rfb_DefsKeySym_R2			0xFFD3
#define lkvnc_rfb_DefsKeySym_F23			0xFFD4
#define lkvnc_rfb_DefsKeySym_R3			0xFFD4
#define lkvnc_rfb_DefsKeySym_F24			0xFFD5
#define lkvnc_rfb_DefsKeySym_R4			0xFFD5
#define lkvnc_rfb_DefsKeySym_F25			0xFFD6
#define lkvnc_rfb_DefsKeySym_R5			0xFFD6
#define lkvnc_rfb_DefsKeySym_F26			0xFFD7
#define lkvnc_rfb_DefsKeySym_R6			0xFFD7
#define lkvnc_rfb_DefsKeySym_F27			0xFFD8
#define lkvnc_rfb_DefsKeySym_R7			0xFFD8
#define lkvnc_rfb_DefsKeySym_F28			0xFFD9
#define lkvnc_rfb_DefsKeySym_R8			0xFFD9
#define lkvnc_rfb_DefsKeySym_F29			0xFFDA
#define lkvnc_rfb_DefsKeySym_R9			0xFFDA
#define lkvnc_rfb_DefsKeySym_F30			0xFFDB
#define lkvnc_rfb_DefsKeySym_R10			0xFFDB
#define lkvnc_rfb_DefsKeySym_F31			0xFFDC
#define lkvnc_rfb_DefsKeySym_R11			0xFFDC
#define lkvnc_rfb_DefsKeySym_F32			0xFFDD
#define lkvnc_rfb_DefsKeySym_R12			0xFFDD
#define lkvnc_rfb_DefsKeySym_F33			0xFFDE
#define lkvnc_rfb_DefsKeySym_R13			0xFFDE
#define lkvnc_rfb_DefsKeySym_F34			0xFFDF
#define lkvnc_rfb_DefsKeySym_R14			0xFFDF
#define lkvnc_rfb_DefsKeySym_F35			0xFFE0
#define lkvnc_rfb_DefsKeySym_R15			0xFFE0

/* Modifiers */

#define lkvnc_rfb_DefsKeySym_Shift_L		0xFFE1	/* Left shift */
#define lkvnc_rfb_DefsKeySym_Shift_R		0xFFE2	/* Right shift */
#define lkvnc_rfb_DefsKeySym_Control_L		0xFFE3	/* Left control */
#define lkvnc_rfb_DefsKeySym_Control_R		0xFFE4	/* Right control */
#define lkvnc_rfb_DefsKeySym_Caps_Lock		0xFFE5	/* Caps lock */
#define lkvnc_rfb_DefsKeySym_Shift_Lock		0xFFE6	/* Shift lock */

#define lkvnc_rfb_DefsKeySym_Meta_L		0xFFE7	/* Left meta */
#define lkvnc_rfb_DefsKeySym_Meta_R		0xFFE8	/* Right meta */
#define lkvnc_rfb_DefsKeySym_Alt_L		0xFFE9	/* Left alt */
#define lkvnc_rfb_DefsKeySym_Alt_R		0xFFEA	/* Right alt */
#define lkvnc_rfb_DefsKeySym_Super_L		0xFFEB	/* Left super */
#define lkvnc_rfb_DefsKeySym_Super_R		0xFFEC	/* Right super */
#define lkvnc_rfb_DefsKeySym_Hyper_L		0xFFED	/* Left hyper */
#define lkvnc_rfb_DefsKeySym_Hyper_R		0xFFEE	/* Right hyper */
#endif /* lkvnc_rfb_DefsKeySym_MISCELLANY */

/*
 * ISO 9995 Function and Modifier Keys
 * Byte 3 = 0xFE
 */

#ifdef lkvnc_rfb_DefsKeySym_XKB_KEYS
#define	lkvnc_rfb_DefsKeySym_ISO_Lock					0xFE01
#define	lkvnc_rfb_DefsKeySym_ISO_Level2_Latch				0xFE02
#define	lkvnc_rfb_DefsKeySym_ISO_Level3_Shift				0xFE03
#define	lkvnc_rfb_DefsKeySym_ISO_Level3_Latch				0xFE04
#define	lkvnc_rfb_DefsKeySym_ISO_Level3_Lock				0xFE05
#define	lkvnc_rfb_DefsKeySym_ISO_Group_Shift		0xFF7E	/* Alias for mode_switch */
#define	lkvnc_rfb_DefsKeySym_ISO_Group_Latch				0xFE06
#define	lkvnc_rfb_DefsKeySym_ISO_Group_Lock				0xFE07
#define	lkvnc_rfb_DefsKeySym_ISO_Next_Group				0xFE08
#define	lkvnc_rfb_DefsKeySym_ISO_Next_Group_Lock				0xFE09
#define	lkvnc_rfb_DefsKeySym_ISO_Prev_Group				0xFE0A
#define	lkvnc_rfb_DefsKeySym_ISO_Prev_Group_Lock				0xFE0B
#define	lkvnc_rfb_DefsKeySym_ISO_First_Group				0xFE0C
#define	lkvnc_rfb_DefsKeySym_ISO_First_Group_Lock				0xFE0D
#define	lkvnc_rfb_DefsKeySym_ISO_Last_Group				0xFE0E
#define	lkvnc_rfb_DefsKeySym_ISO_Last_Group_Lock				0xFE0F

#define	lkvnc_rfb_DefsKeySym_ISO_Left_Tab					0xFE20
#define	lkvnc_rfb_DefsKeySym_ISO_Move_Line_Up				0xFE21
#define	lkvnc_rfb_DefsKeySym_ISO_Move_Line_Down				0xFE22
#define	lkvnc_rfb_DefsKeySym_ISO_Partial_Line_Up				0xFE23
#define	lkvnc_rfb_DefsKeySym_ISO_Partial_Line_Down			0xFE24
#define	lkvnc_rfb_DefsKeySym_ISO_Partial_Space_Left			0xFE25
#define	lkvnc_rfb_DefsKeySym_ISO_Partial_Space_Right			0xFE26
#define	lkvnc_rfb_DefsKeySym_ISO_Set_Margin_Left				0xFE27
#define	lkvnc_rfb_DefsKeySym_ISO_Set_Margin_Right				0xFE28
#define	lkvnc_rfb_DefsKeySym_ISO_Release_Margin_Left			0xFE29
#define	lkvnc_rfb_DefsKeySym_ISO_Release_Margin_Right			0xFE2A
#define	lkvnc_rfb_DefsKeySym_ISO_Release_Both_Margins			0xFE2B
#define	lkvnc_rfb_DefsKeySym_ISO_Fast_Cursor_Left				0xFE2C
#define	lkvnc_rfb_DefsKeySym_ISO_Fast_Cursor_Right			0xFE2D
#define	lkvnc_rfb_DefsKeySym_ISO_Fast_Cursor_Up				0xFE2E
#define	lkvnc_rfb_DefsKeySym_ISO_Fast_Cursor_Down				0xFE2F
#define	lkvnc_rfb_DefsKeySym_ISO_Continuous_Underline			0xFE30
#define	lkvnc_rfb_DefsKeySym_ISO_Discontinuous_Underline			0xFE31
#define	lkvnc_rfb_DefsKeySym_ISO_Emphasize				0xFE32
#define	lkvnc_rfb_DefsKeySym_ISO_Center_Object				0xFE33
#define	lkvnc_rfb_DefsKeySym_ISO_Enter					0xFE34

#define	lkvnc_rfb_DefsKeySym_dead_grave					0xFE50
#define	lkvnc_rfb_DefsKeySym_dead_acute					0xFE51
#define	lkvnc_rfb_DefsKeySym_dead_circumflex				0xFE52
#define	lkvnc_rfb_DefsKeySym_dead_tilde					0xFE53
#define	lkvnc_rfb_DefsKeySym_dead_macron					0xFE54
#define	lkvnc_rfb_DefsKeySym_dead_breve					0xFE55
#define	lkvnc_rfb_DefsKeySym_dead_abovedot				0xFE56
#define	lkvnc_rfb_DefsKeySym_dead_diaeresis				0xFE57
#define	lkvnc_rfb_DefsKeySym_dead_abovering				0xFE58
#define	lkvnc_rfb_DefsKeySym_dead_doubleacute				0xFE59
#define	lkvnc_rfb_DefsKeySym_dead_caron					0xFE5A
#define	lkvnc_rfb_DefsKeySym_dead_cedilla					0xFE5B
#define	lkvnc_rfb_DefsKeySym_dead_ogonek					0xFE5C
#define	lkvnc_rfb_DefsKeySym_dead_iota					0xFE5D
#define	lkvnc_rfb_DefsKeySym_dead_voiced_sound				0xFE5E
#define	lkvnc_rfb_DefsKeySym_dead_semivoiced_sound			0xFE5F
#define	lkvnc_rfb_DefsKeySym_dead_belowdot				0xFE60

#define	lkvnc_rfb_DefsKeySym_First_Virtual_Screen				0xFED0
#define	lkvnc_rfb_DefsKeySym_Prev_Virtual_Screen				0xFED1
#define	lkvnc_rfb_DefsKeySym_Next_Virtual_Screen				0xFED2
#define	lkvnc_rfb_DefsKeySym_Last_Virtual_Screen				0xFED4
#define	lkvnc_rfb_DefsKeySym_Terminate_Server				0xFED5

#define	lkvnc_rfb_DefsKeySym_AccessX_Enable				0xFE70
#define	lkvnc_rfb_DefsKeySym_AccessX_Feedback_Enable			0xFE71
#define	lkvnc_rfb_DefsKeySym_RepeatKeys_Enable				0xFE72
#define	lkvnc_rfb_DefsKeySym_SlowKeys_Enable				0xFE73
#define	lkvnc_rfb_DefsKeySym_BounceKeys_Enable				0xFE74
#define	lkvnc_rfb_DefsKeySym_StickyKeys_Enable				0xFE75
#define	lkvnc_rfb_DefsKeySym_MouseKeys_Enable				0xFE76
#define	lkvnc_rfb_DefsKeySym_MouseKeys_Accel_Enable			0xFE77
#define	lkvnc_rfb_DefsKeySym_Overlay1_Enable				0xFE78
#define	lkvnc_rfb_DefsKeySym_Overlay2_Enable				0xFE79
#define	lkvnc_rfb_DefsKeySym_AudibleBell_Enable				0xFE7A

#define	lkvnc_rfb_DefsKeySym_Pointer_Left					0xFEE0
#define	lkvnc_rfb_DefsKeySym_Pointer_Right				0xFEE1
#define	lkvnc_rfb_DefsKeySym_Pointer_Up					0xFEE2
#define	lkvnc_rfb_DefsKeySym_Pointer_Down					0xFEE3
#define	lkvnc_rfb_DefsKeySym_Pointer_UpLeft				0xFEE4
#define	lkvnc_rfb_DefsKeySym_Pointer_UpRight				0xFEE5
#define	lkvnc_rfb_DefsKeySym_Pointer_DownLeft				0xFEE6
#define	lkvnc_rfb_DefsKeySym_Pointer_DownRight				0xFEE7
#define	lkvnc_rfb_DefsKeySym_Pointer_Button_Dflt				0xFEE8
#define	lkvnc_rfb_DefsKeySym_Pointer_Button1				0xFEE9
#define	lkvnc_rfb_DefsKeySym_Pointer_Button2				0xFEEA
#define	lkvnc_rfb_DefsKeySym_Pointer_Button3				0xFEEB
#define	lkvnc_rfb_DefsKeySym_Pointer_Button4				0xFEEC
#define	lkvnc_rfb_DefsKeySym_Pointer_Button5				0xFEED
#define	lkvnc_rfb_DefsKeySym_Pointer_DblClick_Dflt			0xFEEE
#define	lkvnc_rfb_DefsKeySym_Pointer_DblClick1				0xFEEF
#define	lkvnc_rfb_DefsKeySym_Pointer_DblClick2				0xFEF0
#define	lkvnc_rfb_DefsKeySym_Pointer_DblClick3				0xFEF1
#define	lkvnc_rfb_DefsKeySym_Pointer_DblClick4				0xFEF2
#define	lkvnc_rfb_DefsKeySym_Pointer_DblClick5				0xFEF3
#define	lkvnc_rfb_DefsKeySym_Pointer_Drag_Dflt				0xFEF4
#define	lkvnc_rfb_DefsKeySym_Pointer_Drag1				0xFEF5
#define	lkvnc_rfb_DefsKeySym_Pointer_Drag2				0xFEF6
#define	lkvnc_rfb_DefsKeySym_Pointer_Drag3				0xFEF7
#define	lkvnc_rfb_DefsKeySym_Pointer_Drag4				0xFEF8
#define	lkvnc_rfb_DefsKeySym_Pointer_Drag5				0xFEFD

#define	lkvnc_rfb_DefsKeySym_Pointer_EnableKeys				0xFEF9
#define	lkvnc_rfb_DefsKeySym_Pointer_Accelerate				0xFEFA
#define	lkvnc_rfb_DefsKeySym_Pointer_DfltBtnNext				0xFEFB
#define	lkvnc_rfb_DefsKeySym_Pointer_DfltBtnPrev				0xFEFC

#endif

/*
 * 3270 Terminal Keys
 * Byte 3 = 0xFD
 */

#ifdef lkvnc_rfb_DefsKeySym_3270
#define lkvnc_rfb_DefsKeySym_3270_Duplicate      0xFD01
#define lkvnc_rfb_DefsKeySym_3270_FieldMark      0xFD02
#define lkvnc_rfb_DefsKeySym_3270_Right2         0xFD03
#define lkvnc_rfb_DefsKeySym_3270_Left2          0xFD04
#define lkvnc_rfb_DefsKeySym_3270_BackTab        0xFD05
#define lkvnc_rfb_DefsKeySym_3270_EraseEOF       0xFD06
#define lkvnc_rfb_DefsKeySym_3270_EraseInput     0xFD07
#define lkvnc_rfb_DefsKeySym_3270_Reset          0xFD08
#define lkvnc_rfb_DefsKeySym_3270_Quit           0xFD09
#define lkvnc_rfb_DefsKeySym_3270_PA1            0xFD0A
#define lkvnc_rfb_DefsKeySym_3270_PA2            0xFD0B
#define lkvnc_rfb_DefsKeySym_3270_PA3            0xFD0C
#define lkvnc_rfb_DefsKeySym_3270_Test           0xFD0D
#define lkvnc_rfb_DefsKeySym_3270_Attn           0xFD0E
#define lkvnc_rfb_DefsKeySym_3270_CursorBlink    0xFD0F
#define lkvnc_rfb_DefsKeySym_3270_AltCursor      0xFD10
#define lkvnc_rfb_DefsKeySym_3270_KeyClick       0xFD11
#define lkvnc_rfb_DefsKeySym_3270_Jump           0xFD12
#define lkvnc_rfb_DefsKeySym_3270_Ident          0xFD13
#define lkvnc_rfb_DefsKeySym_3270_Rule           0xFD14
#define lkvnc_rfb_DefsKeySym_3270_Copy           0xFD15
#define lkvnc_rfb_DefsKeySym_3270_Play           0xFD16
#define lkvnc_rfb_DefsKeySym_3270_Setup          0xFD17
#define lkvnc_rfb_DefsKeySym_3270_Record         0xFD18
#define lkvnc_rfb_DefsKeySym_3270_ChangeScreen   0xFD19
#define lkvnc_rfb_DefsKeySym_3270_DeleteWord     0xFD1A
#define lkvnc_rfb_DefsKeySym_3270_ExSelect       0xFD1B
#define lkvnc_rfb_DefsKeySym_3270_CursorSelect   0xFD1C
#define lkvnc_rfb_DefsKeySym_3270_PrintScreen    0xFD1D
#define lkvnc_rfb_DefsKeySym_3270_Enter          0xFD1E
#endif

/*
 *  Latin 1
 *  Byte 3 = 0
 */
#ifdef lkvnc_rfb_DefsKeySym_LATIN1
#define lkvnc_rfb_DefsKeySym_space               0x020
#define lkvnc_rfb_DefsKeySym_exclam              0x021
#define lkvnc_rfb_DefsKeySym_quotedbl            0x022
#define lkvnc_rfb_DefsKeySym_numbersign          0x023
#define lkvnc_rfb_DefsKeySym_dollar              0x024
#define lkvnc_rfb_DefsKeySym_percent             0x025
#define lkvnc_rfb_DefsKeySym_ampersand           0x026
#define lkvnc_rfb_DefsKeySym_apostrophe          0x027
#define lkvnc_rfb_DefsKeySym_quoteright          0x027	/* deprecated */
#define lkvnc_rfb_DefsKeySym_parenleft           0x028
#define lkvnc_rfb_DefsKeySym_parenright          0x029
#define lkvnc_rfb_DefsKeySym_asterisk            0x02a
#define lkvnc_rfb_DefsKeySym_plus                0x02b
#define lkvnc_rfb_DefsKeySym_comma               0x02c
#define lkvnc_rfb_DefsKeySym_minus               0x02d
#define lkvnc_rfb_DefsKeySym_period              0x02e
#define lkvnc_rfb_DefsKeySym_slash               0x02f
#define lkvnc_rfb_DefsKeySym_0                   0x030
#define lkvnc_rfb_DefsKeySym_1                   0x031
#define lkvnc_rfb_DefsKeySym_2                   0x032
#define lkvnc_rfb_DefsKeySym_3                   0x033
#define lkvnc_rfb_DefsKeySym_4                   0x034
#define lkvnc_rfb_DefsKeySym_5                   0x035
#define lkvnc_rfb_DefsKeySym_6                   0x036
#define lkvnc_rfb_DefsKeySym_7                   0x037
#define lkvnc_rfb_DefsKeySym_8                   0x038
#define lkvnc_rfb_DefsKeySym_9                   0x039
#define lkvnc_rfb_DefsKeySym_colon               0x03a
#define lkvnc_rfb_DefsKeySym_semicolon           0x03b
#define lkvnc_rfb_DefsKeySym_less                0x03c
#define lkvnc_rfb_DefsKeySym_equal               0x03d
#define lkvnc_rfb_DefsKeySym_greater             0x03e
#define lkvnc_rfb_DefsKeySym_question            0x03f
#define lkvnc_rfb_DefsKeySym_at                  0x040
#define lkvnc_rfb_DefsKeySym_A                   0x041
#define lkvnc_rfb_DefsKeySym_B                   0x042
#define lkvnc_rfb_DefsKeySym_C                   0x043
#define lkvnc_rfb_DefsKeySym_D                   0x044
#define lkvnc_rfb_DefsKeySym_E                   0x045
#define lkvnc_rfb_DefsKeySym_F                   0x046
#define lkvnc_rfb_DefsKeySym_G                   0x047
#define lkvnc_rfb_DefsKeySym_H                   0x048
#define lkvnc_rfb_DefsKeySym_I                   0x049
#define lkvnc_rfb_DefsKeySym_J                   0x04a
#define lkvnc_rfb_DefsKeySym_K                   0x04b
#define lkvnc_rfb_DefsKeySym_L                   0x04c
#define lkvnc_rfb_DefsKeySym_M                   0x04d
#define lkvnc_rfb_DefsKeySym_N                   0x04e
#define lkvnc_rfb_DefsKeySym_O                   0x04f
#define lkvnc_rfb_DefsKeySym_P                   0x050
#define lkvnc_rfb_DefsKeySym_Q                   0x051
#define lkvnc_rfb_DefsKeySym_R                   0x052
#define lkvnc_rfb_DefsKeySym_S                   0x053
#define lkvnc_rfb_DefsKeySym_T                   0x054
#define lkvnc_rfb_DefsKeySym_U                   0x055
#define lkvnc_rfb_DefsKeySym_V                   0x056
#define lkvnc_rfb_DefsKeySym_W                   0x057
#define lkvnc_rfb_DefsKeySym_X                   0x058
#define lkvnc_rfb_DefsKeySym_Y                   0x059
#define lkvnc_rfb_DefsKeySym_Z                   0x05a
#define lkvnc_rfb_DefsKeySym_bracketleft         0x05b
#define lkvnc_rfb_DefsKeySym_backslash           0x05c
#define lkvnc_rfb_DefsKeySym_bracketright        0x05d
#define lkvnc_rfb_DefsKeySym_asciicircum         0x05e
#define lkvnc_rfb_DefsKeySym_underscore          0x05f
#define lkvnc_rfb_DefsKeySym_grave               0x060
#define lkvnc_rfb_DefsKeySym_quoteleft           0x060	/* deprecated */
#define lkvnc_rfb_DefsKeySym_a                   0x061
#define lkvnc_rfb_DefsKeySym_b                   0x062
#define lkvnc_rfb_DefsKeySym_c                   0x063
#define lkvnc_rfb_DefsKeySym_d                   0x064
#define lkvnc_rfb_DefsKeySym_e                   0x065
#define lkvnc_rfb_DefsKeySym_f                   0x066
#define lkvnc_rfb_DefsKeySym_g                   0x067
#define lkvnc_rfb_DefsKeySym_h                   0x068
#define lkvnc_rfb_DefsKeySym_i                   0x069
#define lkvnc_rfb_DefsKeySym_j                   0x06a
#define lkvnc_rfb_DefsKeySym_k                   0x06b
#define lkvnc_rfb_DefsKeySym_l                   0x06c
#define lkvnc_rfb_DefsKeySym_m                   0x06d
#define lkvnc_rfb_DefsKeySym_n                   0x06e
#define lkvnc_rfb_DefsKeySym_o                   0x06f
#define lkvnc_rfb_DefsKeySym_p                   0x070
#define lkvnc_rfb_DefsKeySym_q                   0x071
#define lkvnc_rfb_DefsKeySym_r                   0x072
#define lkvnc_rfb_DefsKeySym_s                   0x073
#define lkvnc_rfb_DefsKeySym_t                   0x074
#define lkvnc_rfb_DefsKeySym_u                   0x075
#define lkvnc_rfb_DefsKeySym_v                   0x076
#define lkvnc_rfb_DefsKeySym_w                   0x077
#define lkvnc_rfb_DefsKeySym_x                   0x078
#define lkvnc_rfb_DefsKeySym_y                   0x079
#define lkvnc_rfb_DefsKeySym_z                   0x07a
#define lkvnc_rfb_DefsKeySym_braceleft           0x07b
#define lkvnc_rfb_DefsKeySym_bar                 0x07c
#define lkvnc_rfb_DefsKeySym_braceright          0x07d
#define lkvnc_rfb_DefsKeySym_asciitilde          0x07e

#define lkvnc_rfb_DefsKeySym_nobreakspace        0x0a0
#define lkvnc_rfb_DefsKeySym_exclamdown          0x0a1
#define lkvnc_rfb_DefsKeySym_cent        	       0x0a2
#define lkvnc_rfb_DefsKeySym_sterling            0x0a3
#define lkvnc_rfb_DefsKeySym_currency            0x0a4
#define lkvnc_rfb_DefsKeySym_yen                 0x0a5
#define lkvnc_rfb_DefsKeySym_brokenbar           0x0a6
#define lkvnc_rfb_DefsKeySym_section             0x0a7
#define lkvnc_rfb_DefsKeySym_diaeresis           0x0a8
#define lkvnc_rfb_DefsKeySym_copyright           0x0a9
#define lkvnc_rfb_DefsKeySym_ordfeminine         0x0aa
#define lkvnc_rfb_DefsKeySym_guillemotleft       0x0ab	/* left angle quotation mark */
#define lkvnc_rfb_DefsKeySym_notsign             0x0ac
#define lkvnc_rfb_DefsKeySym_hyphen              0x0ad
#define lkvnc_rfb_DefsKeySym_registered          0x0ae
#define lkvnc_rfb_DefsKeySym_macron              0x0af
#define lkvnc_rfb_DefsKeySym_degree              0x0b0
#define lkvnc_rfb_DefsKeySym_plusminus           0x0b1
#define lkvnc_rfb_DefsKeySym_twosuperior         0x0b2
#define lkvnc_rfb_DefsKeySym_threesuperior       0x0b3
#define lkvnc_rfb_DefsKeySym_acute               0x0b4
#define lkvnc_rfb_DefsKeySym_mu                  0x0b5
#define lkvnc_rfb_DefsKeySym_paragraph           0x0b6
#define lkvnc_rfb_DefsKeySym_periodcentered      0x0b7
#define lkvnc_rfb_DefsKeySym_cedilla             0x0b8
#define lkvnc_rfb_DefsKeySym_onesuperior         0x0b9
#define lkvnc_rfb_DefsKeySym_masculine           0x0ba
#define lkvnc_rfb_DefsKeySym_guillemotright      0x0bb	/* right angle quotation mark */
#define lkvnc_rfb_DefsKeySym_onequarter          0x0bc
#define lkvnc_rfb_DefsKeySym_onehalf             0x0bd
#define lkvnc_rfb_DefsKeySym_threequarters       0x0be
#define lkvnc_rfb_DefsKeySym_questiondown        0x0bf
#define lkvnc_rfb_DefsKeySym_Agrave              0x0c0
#define lkvnc_rfb_DefsKeySym_Aacute              0x0c1
#define lkvnc_rfb_DefsKeySym_Acircumflex         0x0c2
#define lkvnc_rfb_DefsKeySym_Atilde              0x0c3
#define lkvnc_rfb_DefsKeySym_Adiaeresis          0x0c4
#define lkvnc_rfb_DefsKeySym_Aring               0x0c5
#define lkvnc_rfb_DefsKeySym_AE                  0x0c6
#define lkvnc_rfb_DefsKeySym_Ccedilla            0x0c7
#define lkvnc_rfb_DefsKeySym_Egrave              0x0c8
#define lkvnc_rfb_DefsKeySym_Eacute              0x0c9
#define lkvnc_rfb_DefsKeySym_Ecircumflex         0x0ca
#define lkvnc_rfb_DefsKeySym_Ediaeresis          0x0cb
#define lkvnc_rfb_DefsKeySym_Igrave              0x0cc
#define lkvnc_rfb_DefsKeySym_Iacute              0x0cd
#define lkvnc_rfb_DefsKeySym_Icircumflex         0x0ce
#define lkvnc_rfb_DefsKeySym_Idiaeresis          0x0cf
#define lkvnc_rfb_DefsKeySym_ETH                 0x0d0
#define lkvnc_rfb_DefsKeySym_Eth                 0x0d0	/* deprecated */
#define lkvnc_rfb_DefsKeySym_Ntilde              0x0d1
#define lkvnc_rfb_DefsKeySym_Ograve              0x0d2
#define lkvnc_rfb_DefsKeySym_Oacute              0x0d3
#define lkvnc_rfb_DefsKeySym_Ocircumflex         0x0d4
#define lkvnc_rfb_DefsKeySym_Otilde              0x0d5
#define lkvnc_rfb_DefsKeySym_Odiaeresis          0x0d6
#define lkvnc_rfb_DefsKeySym_multiply            0x0d7
#define lkvnc_rfb_DefsKeySym_Ooblique            0x0d8
#define lkvnc_rfb_DefsKeySym_Ugrave              0x0d9
#define lkvnc_rfb_DefsKeySym_Uacute              0x0da
#define lkvnc_rfb_DefsKeySym_Ucircumflex         0x0db
#define lkvnc_rfb_DefsKeySym_Udiaeresis          0x0dc
#define lkvnc_rfb_DefsKeySym_Yacute              0x0dd
#define lkvnc_rfb_DefsKeySym_THORN               0x0de
#define lkvnc_rfb_DefsKeySym_Thorn               0x0de	/* deprecated */
#define lkvnc_rfb_DefsKeySym_ssharp              0x0df
#define lkvnc_rfb_DefsKeySym_agrave              0x0e0
#define lkvnc_rfb_DefsKeySym_aacute              0x0e1
#define lkvnc_rfb_DefsKeySym_acircumflex         0x0e2
#define lkvnc_rfb_DefsKeySym_atilde              0x0e3
#define lkvnc_rfb_DefsKeySym_adiaeresis          0x0e4
#define lkvnc_rfb_DefsKeySym_aring               0x0e5
#define lkvnc_rfb_DefsKeySym_ae                  0x0e6
#define lkvnc_rfb_DefsKeySym_ccedilla            0x0e7
#define lkvnc_rfb_DefsKeySym_egrave              0x0e8
#define lkvnc_rfb_DefsKeySym_eacute              0x0e9
#define lkvnc_rfb_DefsKeySym_ecircumflex         0x0ea
#define lkvnc_rfb_DefsKeySym_ediaeresis          0x0eb
#define lkvnc_rfb_DefsKeySym_igrave              0x0ec
#define lkvnc_rfb_DefsKeySym_iacute              0x0ed
#define lkvnc_rfb_DefsKeySym_icircumflex         0x0ee
#define lkvnc_rfb_DefsKeySym_idiaeresis          0x0ef
#define lkvnc_rfb_DefsKeySym_eth                 0x0f0
#define lkvnc_rfb_DefsKeySym_ntilde              0x0f1
#define lkvnc_rfb_DefsKeySym_ograve              0x0f2
#define lkvnc_rfb_DefsKeySym_oacute              0x0f3
#define lkvnc_rfb_DefsKeySym_ocircumflex         0x0f4
#define lkvnc_rfb_DefsKeySym_otilde              0x0f5
#define lkvnc_rfb_DefsKeySym_odiaeresis          0x0f6
#define lkvnc_rfb_DefsKeySym_division            0x0f7
#define lkvnc_rfb_DefsKeySym_oslash              0x0f8
#define lkvnc_rfb_DefsKeySym_ugrave              0x0f9
#define lkvnc_rfb_DefsKeySym_uacute              0x0fa
#define lkvnc_rfb_DefsKeySym_ucircumflex         0x0fb
#define lkvnc_rfb_DefsKeySym_udiaeresis          0x0fc
#define lkvnc_rfb_DefsKeySym_yacute              0x0fd
#define lkvnc_rfb_DefsKeySym_thorn               0x0fe
#define lkvnc_rfb_DefsKeySym_ydiaeresis          0x0ff
#endif /* lkvnc_rfb_DefsKeySym_LATIN1 */

/*
 *   Latin 2
 *   Byte 3 = 1
 */

#ifdef lkvnc_rfb_DefsKeySym_LATIN2
#define lkvnc_rfb_DefsKeySym_Aogonek             0x1a1
#define lkvnc_rfb_DefsKeySym_breve               0x1a2
#define lkvnc_rfb_DefsKeySym_Lstroke             0x1a3
#define lkvnc_rfb_DefsKeySym_Lcaron              0x1a5
#define lkvnc_rfb_DefsKeySym_Sacute              0x1a6
#define lkvnc_rfb_DefsKeySym_Scaron              0x1a9
#define lkvnc_rfb_DefsKeySym_Scedilla            0x1aa
#define lkvnc_rfb_DefsKeySym_Tcaron              0x1ab
#define lkvnc_rfb_DefsKeySym_Zacute              0x1ac
#define lkvnc_rfb_DefsKeySym_Zcaron              0x1ae
#define lkvnc_rfb_DefsKeySym_Zabovedot           0x1af
#define lkvnc_rfb_DefsKeySym_aogonek             0x1b1
#define lkvnc_rfb_DefsKeySym_ogonek              0x1b2
#define lkvnc_rfb_DefsKeySym_lstroke             0x1b3
#define lkvnc_rfb_DefsKeySym_lcaron              0x1b5
#define lkvnc_rfb_DefsKeySym_sacute              0x1b6
#define lkvnc_rfb_DefsKeySym_caron               0x1b7
#define lkvnc_rfb_DefsKeySym_scaron              0x1b9
#define lkvnc_rfb_DefsKeySym_scedilla            0x1ba
#define lkvnc_rfb_DefsKeySym_tcaron              0x1bb
#define lkvnc_rfb_DefsKeySym_zacute              0x1bc
#define lkvnc_rfb_DefsKeySym_doubleacute         0x1bd
#define lkvnc_rfb_DefsKeySym_zcaron              0x1be
#define lkvnc_rfb_DefsKeySym_zabovedot           0x1bf
#define lkvnc_rfb_DefsKeySym_Racute              0x1c0
#define lkvnc_rfb_DefsKeySym_Abreve              0x1c3
#define lkvnc_rfb_DefsKeySym_Lacute              0x1c5
#define lkvnc_rfb_DefsKeySym_Cacute              0x1c6
#define lkvnc_rfb_DefsKeySym_Ccaron              0x1c8
#define lkvnc_rfb_DefsKeySym_Eogonek             0x1ca
#define lkvnc_rfb_DefsKeySym_Ecaron              0x1cc
#define lkvnc_rfb_DefsKeySym_Dcaron              0x1cf
#define lkvnc_rfb_DefsKeySym_Dstroke             0x1d0
#define lkvnc_rfb_DefsKeySym_Nacute              0x1d1
#define lkvnc_rfb_DefsKeySym_Ncaron              0x1d2
#define lkvnc_rfb_DefsKeySym_Odoubleacute        0x1d5
#define lkvnc_rfb_DefsKeySym_Rcaron              0x1d8
#define lkvnc_rfb_DefsKeySym_Uring               0x1d9
#define lkvnc_rfb_DefsKeySym_Udoubleacute        0x1db
#define lkvnc_rfb_DefsKeySym_Tcedilla            0x1de
#define lkvnc_rfb_DefsKeySym_racute              0x1e0
#define lkvnc_rfb_DefsKeySym_abreve              0x1e3
#define lkvnc_rfb_DefsKeySym_lacute              0x1e5
#define lkvnc_rfb_DefsKeySym_cacute              0x1e6
#define lkvnc_rfb_DefsKeySym_ccaron              0x1e8
#define lkvnc_rfb_DefsKeySym_eogonek             0x1ea
#define lkvnc_rfb_DefsKeySym_ecaron              0x1ec
#define lkvnc_rfb_DefsKeySym_dcaron              0x1ef
#define lkvnc_rfb_DefsKeySym_dstroke             0x1f0
#define lkvnc_rfb_DefsKeySym_nacute              0x1f1
#define lkvnc_rfb_DefsKeySym_ncaron              0x1f2
#define lkvnc_rfb_DefsKeySym_odoubleacute        0x1f5
#define lkvnc_rfb_DefsKeySym_udoubleacute        0x1fb
#define lkvnc_rfb_DefsKeySym_rcaron              0x1f8
#define lkvnc_rfb_DefsKeySym_uring               0x1f9
#define lkvnc_rfb_DefsKeySym_tcedilla            0x1fe
#define lkvnc_rfb_DefsKeySym_abovedot            0x1ff
#endif /* lkvnc_rfb_DefsKeySym_LATIN2 */

/*
 *   Latin 3
 *   Byte 3 = 2
 */

#ifdef lkvnc_rfb_DefsKeySym_LATIN3
#define lkvnc_rfb_DefsKeySym_Hstroke             0x2a1
#define lkvnc_rfb_DefsKeySym_Hcircumflex         0x2a6
#define lkvnc_rfb_DefsKeySym_Iabovedot           0x2a9
#define lkvnc_rfb_DefsKeySym_Gbreve              0x2ab
#define lkvnc_rfb_DefsKeySym_Jcircumflex         0x2ac
#define lkvnc_rfb_DefsKeySym_hstroke             0x2b1
#define lkvnc_rfb_DefsKeySym_hcircumflex         0x2b6
#define lkvnc_rfb_DefsKeySym_idotless            0x2b9
#define lkvnc_rfb_DefsKeySym_gbreve              0x2bb
#define lkvnc_rfb_DefsKeySym_jcircumflex         0x2bc
#define lkvnc_rfb_DefsKeySym_Cabovedot           0x2c5
#define lkvnc_rfb_DefsKeySym_Ccircumflex         0x2c6
#define lkvnc_rfb_DefsKeySym_Gabovedot           0x2d5
#define lkvnc_rfb_DefsKeySym_Gcircumflex         0x2d8
#define lkvnc_rfb_DefsKeySym_Ubreve              0x2dd
#define lkvnc_rfb_DefsKeySym_Scircumflex         0x2de
#define lkvnc_rfb_DefsKeySym_cabovedot           0x2e5
#define lkvnc_rfb_DefsKeySym_ccircumflex         0x2e6
#define lkvnc_rfb_DefsKeySym_gabovedot           0x2f5
#define lkvnc_rfb_DefsKeySym_gcircumflex         0x2f8
#define lkvnc_rfb_DefsKeySym_ubreve              0x2fd
#define lkvnc_rfb_DefsKeySym_scircumflex         0x2fe
#endif /* lkvnc_rfb_DefsKeySym_LATIN3 */


/*
 *   Latin 4
 *   Byte 3 = 3
 */

#ifdef lkvnc_rfb_DefsKeySym_LATIN4
#define lkvnc_rfb_DefsKeySym_kra                 0x3a2
#define lkvnc_rfb_DefsKeySym_kappa               0x3a2	/* deprecated */
#define lkvnc_rfb_DefsKeySym_Rcedilla            0x3a3
#define lkvnc_rfb_DefsKeySym_Itilde              0x3a5
#define lkvnc_rfb_DefsKeySym_Lcedilla            0x3a6
#define lkvnc_rfb_DefsKeySym_Emacron             0x3aa
#define lkvnc_rfb_DefsKeySym_Gcedilla            0x3ab
#define lkvnc_rfb_DefsKeySym_Tslash              0x3ac
#define lkvnc_rfb_DefsKeySym_rcedilla            0x3b3
#define lkvnc_rfb_DefsKeySym_itilde              0x3b5
#define lkvnc_rfb_DefsKeySym_lcedilla            0x3b6
#define lkvnc_rfb_DefsKeySym_emacron             0x3ba
#define lkvnc_rfb_DefsKeySym_gcedilla            0x3bb
#define lkvnc_rfb_DefsKeySym_tslash              0x3bc
#define lkvnc_rfb_DefsKeySym_ENG                 0x3bd
#define lkvnc_rfb_DefsKeySym_eng                 0x3bf
#define lkvnc_rfb_DefsKeySym_Amacron             0x3c0
#define lkvnc_rfb_DefsKeySym_Iogonek             0x3c7
#define lkvnc_rfb_DefsKeySym_Eabovedot           0x3cc
#define lkvnc_rfb_DefsKeySym_Imacron             0x3cf
#define lkvnc_rfb_DefsKeySym_Ncedilla            0x3d1
#define lkvnc_rfb_DefsKeySym_Omacron             0x3d2
#define lkvnc_rfb_DefsKeySym_Kcedilla            0x3d3
#define lkvnc_rfb_DefsKeySym_Uogonek             0x3d9
#define lkvnc_rfb_DefsKeySym_Utilde              0x3dd
#define lkvnc_rfb_DefsKeySym_Umacron             0x3de
#define lkvnc_rfb_DefsKeySym_amacron             0x3e0
#define lkvnc_rfb_DefsKeySym_iogonek             0x3e7
#define lkvnc_rfb_DefsKeySym_eabovedot           0x3ec
#define lkvnc_rfb_DefsKeySym_imacron             0x3ef
#define lkvnc_rfb_DefsKeySym_ncedilla            0x3f1
#define lkvnc_rfb_DefsKeySym_omacron             0x3f2
#define lkvnc_rfb_DefsKeySym_kcedilla            0x3f3
#define lkvnc_rfb_DefsKeySym_uogonek             0x3f9
#define lkvnc_rfb_DefsKeySym_utilde              0x3fd
#define lkvnc_rfb_DefsKeySym_umacron             0x3fe
#endif /* lkvnc_rfb_DefsKeySym_LATIN4 */

/*
 * Latin-9 (a.k.a. Latin-0)
 * Byte 3 = 19
 */

#ifdef lkvnc_rfb_DefsKeySym_LATIN9
#define lkvnc_rfb_DefsKeySym_OE                  0x13bc
#define lkvnc_rfb_DefsKeySym_oe                  0x13bd
#define lkvnc_rfb_DefsKeySym_Ydiaeresis          0x13be
#endif /* lkvnc_rfb_DefsKeySym_LATIN9 */

/*
 * Katakana
 * Byte 3 = 4
 */

#ifdef lkvnc_rfb_DefsKeySym_KATAKANA
#define lkvnc_rfb_DefsKeySym_overline				       0x47e
#define lkvnc_rfb_DefsKeySym_kana_fullstop                               0x4a1
#define lkvnc_rfb_DefsKeySym_kana_openingbracket                         0x4a2
#define lkvnc_rfb_DefsKeySym_kana_closingbracket                         0x4a3
#define lkvnc_rfb_DefsKeySym_kana_comma                                  0x4a4
#define lkvnc_rfb_DefsKeySym_kana_conjunctive                            0x4a5
#define lkvnc_rfb_DefsKeySym_kana_middledot                              0x4a5  /* deprecated */
#define lkvnc_rfb_DefsKeySym_kana_WO                                     0x4a6
#define lkvnc_rfb_DefsKeySym_kana_a                                      0x4a7
#define lkvnc_rfb_DefsKeySym_kana_i                                      0x4a8
#define lkvnc_rfb_DefsKeySym_kana_u                                      0x4a9
#define lkvnc_rfb_DefsKeySym_kana_e                                      0x4aa
#define lkvnc_rfb_DefsKeySym_kana_o                                      0x4ab
#define lkvnc_rfb_DefsKeySym_kana_ya                                     0x4ac
#define lkvnc_rfb_DefsKeySym_kana_yu                                     0x4ad
#define lkvnc_rfb_DefsKeySym_kana_yo                                     0x4ae
#define lkvnc_rfb_DefsKeySym_kana_tsu                                    0x4af
#define lkvnc_rfb_DefsKeySym_kana_tu                                     0x4af  /* deprecated */
#define lkvnc_rfb_DefsKeySym_prolongedsound                              0x4b0
#define lkvnc_rfb_DefsKeySym_kana_A                                      0x4b1
#define lkvnc_rfb_DefsKeySym_kana_I                                      0x4b2
#define lkvnc_rfb_DefsKeySym_kana_U                                      0x4b3
#define lkvnc_rfb_DefsKeySym_kana_E                                      0x4b4
#define lkvnc_rfb_DefsKeySym_kana_O                                      0x4b5
#define lkvnc_rfb_DefsKeySym_kana_KA                                     0x4b6
#define lkvnc_rfb_DefsKeySym_kana_KI                                     0x4b7
#define lkvnc_rfb_DefsKeySym_kana_KU                                     0x4b8
#define lkvnc_rfb_DefsKeySym_kana_KE                                     0x4b9
#define lkvnc_rfb_DefsKeySym_kana_KO                                     0x4ba
#define lkvnc_rfb_DefsKeySym_kana_SA                                     0x4bb
#define lkvnc_rfb_DefsKeySym_kana_SHI                                    0x4bc
#define lkvnc_rfb_DefsKeySym_kana_SU                                     0x4bd
#define lkvnc_rfb_DefsKeySym_kana_SE                                     0x4be
#define lkvnc_rfb_DefsKeySym_kana_SO                                     0x4bf
#define lkvnc_rfb_DefsKeySym_kana_TA                                     0x4c0
#define lkvnc_rfb_DefsKeySym_kana_CHI                                    0x4c1
#define lkvnc_rfb_DefsKeySym_kana_TI                                     0x4c1  /* deprecated */
#define lkvnc_rfb_DefsKeySym_kana_TSU                                    0x4c2
#define lkvnc_rfb_DefsKeySym_kana_TU                                     0x4c2  /* deprecated */
#define lkvnc_rfb_DefsKeySym_kana_TE                                     0x4c3
#define lkvnc_rfb_DefsKeySym_kana_TO                                     0x4c4
#define lkvnc_rfb_DefsKeySym_kana_NA                                     0x4c5
#define lkvnc_rfb_DefsKeySym_kana_NI                                     0x4c6
#define lkvnc_rfb_DefsKeySym_kana_NU                                     0x4c7
#define lkvnc_rfb_DefsKeySym_kana_NE                                     0x4c8
#define lkvnc_rfb_DefsKeySym_kana_NO                                     0x4c9
#define lkvnc_rfb_DefsKeySym_kana_HA                                     0x4ca
#define lkvnc_rfb_DefsKeySym_kana_HI                                     0x4cb
#define lkvnc_rfb_DefsKeySym_kana_FU                                     0x4cc
#define lkvnc_rfb_DefsKeySym_kana_HU                                     0x4cc  /* deprecated */
#define lkvnc_rfb_DefsKeySym_kana_HE                                     0x4cd
#define lkvnc_rfb_DefsKeySym_kana_HO                                     0x4ce
#define lkvnc_rfb_DefsKeySym_kana_MA                                     0x4cf
#define lkvnc_rfb_DefsKeySym_kana_MI                                     0x4d0
#define lkvnc_rfb_DefsKeySym_kana_MU                                     0x4d1
#define lkvnc_rfb_DefsKeySym_kana_ME                                     0x4d2
#define lkvnc_rfb_DefsKeySym_kana_MO                                     0x4d3
#define lkvnc_rfb_DefsKeySym_kana_YA                                     0x4d4
#define lkvnc_rfb_DefsKeySym_kana_YU                                     0x4d5
#define lkvnc_rfb_DefsKeySym_kana_YO                                     0x4d6
#define lkvnc_rfb_DefsKeySym_kana_RA                                     0x4d7
#define lkvnc_rfb_DefsKeySym_kana_RI                                     0x4d8
#define lkvnc_rfb_DefsKeySym_kana_RU                                     0x4d9
#define lkvnc_rfb_DefsKeySym_kana_RE                                     0x4da
#define lkvnc_rfb_DefsKeySym_kana_RO                                     0x4db
#define lkvnc_rfb_DefsKeySym_kana_WA                                     0x4dc
#define lkvnc_rfb_DefsKeySym_kana_N                                      0x4dd
#define lkvnc_rfb_DefsKeySym_voicedsound                                 0x4de
#define lkvnc_rfb_DefsKeySym_semivoicedsound                             0x4df
#define lkvnc_rfb_DefsKeySym_kana_switch          0xFF7E  /* Alias for mode_switch */
#endif /* lkvnc_rfb_DefsKeySym_KATAKANA */

/*
 *  Arabic
 *  Byte 3 = 5
 */

#ifdef lkvnc_rfb_DefsKeySym_ARABIC
#define lkvnc_rfb_DefsKeySym_Arabic_comma                                0x5ac
#define lkvnc_rfb_DefsKeySym_Arabic_semicolon                            0x5bb
#define lkvnc_rfb_DefsKeySym_Arabic_question_mark                        0x5bf
#define lkvnc_rfb_DefsKeySym_Arabic_hamza                                0x5c1
#define lkvnc_rfb_DefsKeySym_Arabic_maddaonalef                          0x5c2
#define lkvnc_rfb_DefsKeySym_Arabic_hamzaonalef                          0x5c3
#define lkvnc_rfb_DefsKeySym_Arabic_hamzaonwaw                           0x5c4
#define lkvnc_rfb_DefsKeySym_Arabic_hamzaunderalef                       0x5c5
#define lkvnc_rfb_DefsKeySym_Arabic_hamzaonyeh                           0x5c6
#define lkvnc_rfb_DefsKeySym_Arabic_alef                                 0x5c7
#define lkvnc_rfb_DefsKeySym_Arabic_beh                                  0x5c8
#define lkvnc_rfb_DefsKeySym_Arabic_tehmarbuta                           0x5c9
#define lkvnc_rfb_DefsKeySym_Arabic_teh                                  0x5ca
#define lkvnc_rfb_DefsKeySym_Arabic_theh                                 0x5cb
#define lkvnc_rfb_DefsKeySym_Arabic_jeem                                 0x5cc
#define lkvnc_rfb_DefsKeySym_Arabic_hah                                  0x5cd
#define lkvnc_rfb_DefsKeySym_Arabic_khah                                 0x5ce
#define lkvnc_rfb_DefsKeySym_Arabic_dal                                  0x5cf
#define lkvnc_rfb_DefsKeySym_Arabic_thal                                 0x5d0
#define lkvnc_rfb_DefsKeySym_Arabic_ra                                   0x5d1
#define lkvnc_rfb_DefsKeySym_Arabic_zain                                 0x5d2
#define lkvnc_rfb_DefsKeySym_Arabic_seen                                 0x5d3
#define lkvnc_rfb_DefsKeySym_Arabic_sheen                                0x5d4
#define lkvnc_rfb_DefsKeySym_Arabic_sad                                  0x5d5
#define lkvnc_rfb_DefsKeySym_Arabic_dad                                  0x5d6
#define lkvnc_rfb_DefsKeySym_Arabic_tah                                  0x5d7
#define lkvnc_rfb_DefsKeySym_Arabic_zah                                  0x5d8
#define lkvnc_rfb_DefsKeySym_Arabic_ain                                  0x5d9
#define lkvnc_rfb_DefsKeySym_Arabic_ghain                                0x5da
#define lkvnc_rfb_DefsKeySym_Arabic_tatweel                              0x5e0
#define lkvnc_rfb_DefsKeySym_Arabic_feh                                  0x5e1
#define lkvnc_rfb_DefsKeySym_Arabic_qaf                                  0x5e2
#define lkvnc_rfb_DefsKeySym_Arabic_kaf                                  0x5e3
#define lkvnc_rfb_DefsKeySym_Arabic_lam                                  0x5e4
#define lkvnc_rfb_DefsKeySym_Arabic_meem                                 0x5e5
#define lkvnc_rfb_DefsKeySym_Arabic_noon                                 0x5e6
#define lkvnc_rfb_DefsKeySym_Arabic_ha                                   0x5e7
#define lkvnc_rfb_DefsKeySym_Arabic_heh                                  0x5e7  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Arabic_waw                                  0x5e8
#define lkvnc_rfb_DefsKeySym_Arabic_alefmaksura                          0x5e9
#define lkvnc_rfb_DefsKeySym_Arabic_yeh                                  0x5ea
#define lkvnc_rfb_DefsKeySym_Arabic_fathatan                             0x5eb
#define lkvnc_rfb_DefsKeySym_Arabic_dammatan                             0x5ec
#define lkvnc_rfb_DefsKeySym_Arabic_kasratan                             0x5ed
#define lkvnc_rfb_DefsKeySym_Arabic_fatha                                0x5ee
#define lkvnc_rfb_DefsKeySym_Arabic_damma                                0x5ef
#define lkvnc_rfb_DefsKeySym_Arabic_kasra                                0x5f0
#define lkvnc_rfb_DefsKeySym_Arabic_shadda                               0x5f1
#define lkvnc_rfb_DefsKeySym_Arabic_sukun                                0x5f2
#define lkvnc_rfb_DefsKeySym_Arabic_switch        0xFF7E  /* Alias for mode_switch */
#endif /* lkvnc_rfb_DefsKeySym_ARABIC */

/*
 * Cyrillic
 * Byte 3 = 6
 */
#ifdef lkvnc_rfb_DefsKeySym_CYRILLIC
#define lkvnc_rfb_DefsKeySym_Serbian_dje                                 0x6a1
#define lkvnc_rfb_DefsKeySym_Macedonia_gje                               0x6a2
#define lkvnc_rfb_DefsKeySym_Cyrillic_io                                 0x6a3
#define lkvnc_rfb_DefsKeySym_Ukrainian_ie                                0x6a4
#define lkvnc_rfb_DefsKeySym_Ukranian_je                                 0x6a4  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Macedonia_dse                               0x6a5
#define lkvnc_rfb_DefsKeySym_Ukrainian_i                                 0x6a6
#define lkvnc_rfb_DefsKeySym_Ukranian_i                                  0x6a6  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Ukrainian_yi                                0x6a7
#define lkvnc_rfb_DefsKeySym_Ukranian_yi                                 0x6a7  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_je                                 0x6a8
#define lkvnc_rfb_DefsKeySym_Serbian_je                                  0x6a8  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_lje                                0x6a9
#define lkvnc_rfb_DefsKeySym_Serbian_lje                                 0x6a9  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_nje                                0x6aa
#define lkvnc_rfb_DefsKeySym_Serbian_nje                                 0x6aa  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Serbian_tshe                                0x6ab
#define lkvnc_rfb_DefsKeySym_Macedonia_kje                               0x6ac
#define lkvnc_rfb_DefsKeySym_Byelorussian_shortu                         0x6ae
#define lkvnc_rfb_DefsKeySym_Cyrillic_dzhe                               0x6af
#define lkvnc_rfb_DefsKeySym_Serbian_dze                                 0x6af  /* deprecated */
#define lkvnc_rfb_DefsKeySym_numerosign                                  0x6b0
#define lkvnc_rfb_DefsKeySym_Serbian_DJE                                 0x6b1
#define lkvnc_rfb_DefsKeySym_Macedonia_GJE                               0x6b2
#define lkvnc_rfb_DefsKeySym_Cyrillic_IO                                 0x6b3
#define lkvnc_rfb_DefsKeySym_Ukrainian_IE                                0x6b4
#define lkvnc_rfb_DefsKeySym_Ukranian_JE                                 0x6b4  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Macedonia_DSE                               0x6b5
#define lkvnc_rfb_DefsKeySym_Ukrainian_I                                 0x6b6
#define lkvnc_rfb_DefsKeySym_Ukranian_I                                  0x6b6  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Ukrainian_YI                                0x6b7
#define lkvnc_rfb_DefsKeySym_Ukranian_YI                                 0x6b7  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_JE                                 0x6b8
#define lkvnc_rfb_DefsKeySym_Serbian_JE                                  0x6b8  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_LJE                                0x6b9
#define lkvnc_rfb_DefsKeySym_Serbian_LJE                                 0x6b9  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_NJE                                0x6ba
#define lkvnc_rfb_DefsKeySym_Serbian_NJE                                 0x6ba  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Serbian_TSHE                                0x6bb
#define lkvnc_rfb_DefsKeySym_Macedonia_KJE                               0x6bc
#define lkvnc_rfb_DefsKeySym_Byelorussian_SHORTU                         0x6be
#define lkvnc_rfb_DefsKeySym_Cyrillic_DZHE                               0x6bf
#define lkvnc_rfb_DefsKeySym_Serbian_DZE                                 0x6bf  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Cyrillic_yu                                 0x6c0
#define lkvnc_rfb_DefsKeySym_Cyrillic_a                                  0x6c1
#define lkvnc_rfb_DefsKeySym_Cyrillic_be                                 0x6c2
#define lkvnc_rfb_DefsKeySym_Cyrillic_tse                                0x6c3
#define lkvnc_rfb_DefsKeySym_Cyrillic_de                                 0x6c4
#define lkvnc_rfb_DefsKeySym_Cyrillic_ie                                 0x6c5
#define lkvnc_rfb_DefsKeySym_Cyrillic_ef                                 0x6c6
#define lkvnc_rfb_DefsKeySym_Cyrillic_ghe                                0x6c7
#define lkvnc_rfb_DefsKeySym_Cyrillic_ha                                 0x6c8
#define lkvnc_rfb_DefsKeySym_Cyrillic_i                                  0x6c9
#define lkvnc_rfb_DefsKeySym_Cyrillic_shorti                             0x6ca
#define lkvnc_rfb_DefsKeySym_Cyrillic_ka                                 0x6cb
#define lkvnc_rfb_DefsKeySym_Cyrillic_el                                 0x6cc
#define lkvnc_rfb_DefsKeySym_Cyrillic_em                                 0x6cd
#define lkvnc_rfb_DefsKeySym_Cyrillic_en                                 0x6ce
#define lkvnc_rfb_DefsKeySym_Cyrillic_o                                  0x6cf
#define lkvnc_rfb_DefsKeySym_Cyrillic_pe                                 0x6d0
#define lkvnc_rfb_DefsKeySym_Cyrillic_ya                                 0x6d1
#define lkvnc_rfb_DefsKeySym_Cyrillic_er                                 0x6d2
#define lkvnc_rfb_DefsKeySym_Cyrillic_es                                 0x6d3
#define lkvnc_rfb_DefsKeySym_Cyrillic_te                                 0x6d4
#define lkvnc_rfb_DefsKeySym_Cyrillic_u                                  0x6d5
#define lkvnc_rfb_DefsKeySym_Cyrillic_zhe                                0x6d6
#define lkvnc_rfb_DefsKeySym_Cyrillic_ve                                 0x6d7
#define lkvnc_rfb_DefsKeySym_Cyrillic_softsign                           0x6d8
#define lkvnc_rfb_DefsKeySym_Cyrillic_yeru                               0x6d9
#define lkvnc_rfb_DefsKeySym_Cyrillic_ze                                 0x6da
#define lkvnc_rfb_DefsKeySym_Cyrillic_sha                                0x6db
#define lkvnc_rfb_DefsKeySym_Cyrillic_e                                  0x6dc
#define lkvnc_rfb_DefsKeySym_Cyrillic_shcha                              0x6dd
#define lkvnc_rfb_DefsKeySym_Cyrillic_che                                0x6de
#define lkvnc_rfb_DefsKeySym_Cyrillic_hardsign                           0x6df
#define lkvnc_rfb_DefsKeySym_Cyrillic_YU                                 0x6e0
#define lkvnc_rfb_DefsKeySym_Cyrillic_A                                  0x6e1
#define lkvnc_rfb_DefsKeySym_Cyrillic_BE                                 0x6e2
#define lkvnc_rfb_DefsKeySym_Cyrillic_TSE                                0x6e3
#define lkvnc_rfb_DefsKeySym_Cyrillic_DE                                 0x6e4
#define lkvnc_rfb_DefsKeySym_Cyrillic_IE                                 0x6e5
#define lkvnc_rfb_DefsKeySym_Cyrillic_EF                                 0x6e6
#define lkvnc_rfb_DefsKeySym_Cyrillic_GHE                                0x6e7
#define lkvnc_rfb_DefsKeySym_Cyrillic_HA                                 0x6e8
#define lkvnc_rfb_DefsKeySym_Cyrillic_I                                  0x6e9
#define lkvnc_rfb_DefsKeySym_Cyrillic_SHORTI                             0x6ea
#define lkvnc_rfb_DefsKeySym_Cyrillic_KA                                 0x6eb
#define lkvnc_rfb_DefsKeySym_Cyrillic_EL                                 0x6ec
#define lkvnc_rfb_DefsKeySym_Cyrillic_EM                                 0x6ed
#define lkvnc_rfb_DefsKeySym_Cyrillic_EN                                 0x6ee
#define lkvnc_rfb_DefsKeySym_Cyrillic_O                                  0x6ef
#define lkvnc_rfb_DefsKeySym_Cyrillic_PE                                 0x6f0
#define lkvnc_rfb_DefsKeySym_Cyrillic_YA                                 0x6f1
#define lkvnc_rfb_DefsKeySym_Cyrillic_ER                                 0x6f2
#define lkvnc_rfb_DefsKeySym_Cyrillic_ES                                 0x6f3
#define lkvnc_rfb_DefsKeySym_Cyrillic_TE                                 0x6f4
#define lkvnc_rfb_DefsKeySym_Cyrillic_U                                  0x6f5
#define lkvnc_rfb_DefsKeySym_Cyrillic_ZHE                                0x6f6
#define lkvnc_rfb_DefsKeySym_Cyrillic_VE                                 0x6f7
#define lkvnc_rfb_DefsKeySym_Cyrillic_SOFTSIGN                           0x6f8
#define lkvnc_rfb_DefsKeySym_Cyrillic_YERU                               0x6f9
#define lkvnc_rfb_DefsKeySym_Cyrillic_ZE                                 0x6fa
#define lkvnc_rfb_DefsKeySym_Cyrillic_SHA                                0x6fb
#define lkvnc_rfb_DefsKeySym_Cyrillic_E                                  0x6fc
#define lkvnc_rfb_DefsKeySym_Cyrillic_SHCHA                              0x6fd
#define lkvnc_rfb_DefsKeySym_Cyrillic_CHE                                0x6fe
#define lkvnc_rfb_DefsKeySym_Cyrillic_HARDSIGN                           0x6ff
#endif /* lkvnc_rfb_DefsKeySym_CYRILLIC */

/*
 * Greek
 * Byte 3 = 7
 */

#ifdef lkvnc_rfb_DefsKeySym_GREEK
#define lkvnc_rfb_DefsKeySym_Greek_ALPHAaccent                           0x7a1
#define lkvnc_rfb_DefsKeySym_Greek_EPSILONaccent                         0x7a2
#define lkvnc_rfb_DefsKeySym_Greek_ETAaccent                             0x7a3
#define lkvnc_rfb_DefsKeySym_Greek_IOTAaccent                            0x7a4
#define lkvnc_rfb_DefsKeySym_Greek_IOTAdiaeresis                         0x7a5
#define lkvnc_rfb_DefsKeySym_Greek_OMICRONaccent                         0x7a7
#define lkvnc_rfb_DefsKeySym_Greek_UPSILONaccent                         0x7a8
#define lkvnc_rfb_DefsKeySym_Greek_UPSILONdieresis                       0x7a9
#define lkvnc_rfb_DefsKeySym_Greek_OMEGAaccent                           0x7ab
#define lkvnc_rfb_DefsKeySym_Greek_accentdieresis                        0x7ae
#define lkvnc_rfb_DefsKeySym_Greek_horizbar                              0x7af
#define lkvnc_rfb_DefsKeySym_Greek_alphaaccent                           0x7b1
#define lkvnc_rfb_DefsKeySym_Greek_epsilonaccent                         0x7b2
#define lkvnc_rfb_DefsKeySym_Greek_etaaccent                             0x7b3
#define lkvnc_rfb_DefsKeySym_Greek_iotaaccent                            0x7b4
#define lkvnc_rfb_DefsKeySym_Greek_iotadieresis                          0x7b5
#define lkvnc_rfb_DefsKeySym_Greek_iotaaccentdieresis                    0x7b6
#define lkvnc_rfb_DefsKeySym_Greek_omicronaccent                         0x7b7
#define lkvnc_rfb_DefsKeySym_Greek_upsilonaccent                         0x7b8
#define lkvnc_rfb_DefsKeySym_Greek_upsilondieresis                       0x7b9
#define lkvnc_rfb_DefsKeySym_Greek_upsilonaccentdieresis                 0x7ba
#define lkvnc_rfb_DefsKeySym_Greek_omegaaccent                           0x7bb
#define lkvnc_rfb_DefsKeySym_Greek_ALPHA                                 0x7c1
#define lkvnc_rfb_DefsKeySym_Greek_BETA                                  0x7c2
#define lkvnc_rfb_DefsKeySym_Greek_GAMMA                                 0x7c3
#define lkvnc_rfb_DefsKeySym_Greek_DELTA                                 0x7c4
#define lkvnc_rfb_DefsKeySym_Greek_EPSILON                               0x7c5
#define lkvnc_rfb_DefsKeySym_Greek_ZETA                                  0x7c6
#define lkvnc_rfb_DefsKeySym_Greek_ETA                                   0x7c7
#define lkvnc_rfb_DefsKeySym_Greek_THETA                                 0x7c8
#define lkvnc_rfb_DefsKeySym_Greek_IOTA                                  0x7c9
#define lkvnc_rfb_DefsKeySym_Greek_KAPPA                                 0x7ca
#define lkvnc_rfb_DefsKeySym_Greek_LAMDA                                 0x7cb
#define lkvnc_rfb_DefsKeySym_Greek_LAMBDA                                0x7cb
#define lkvnc_rfb_DefsKeySym_Greek_MU                                    0x7cc
#define lkvnc_rfb_DefsKeySym_Greek_NU                                    0x7cd
#define lkvnc_rfb_DefsKeySym_Greek_XI                                    0x7ce
#define lkvnc_rfb_DefsKeySym_Greek_OMICRON                               0x7cf
#define lkvnc_rfb_DefsKeySym_Greek_PI                                    0x7d0
#define lkvnc_rfb_DefsKeySym_Greek_RHO                                   0x7d1
#define lkvnc_rfb_DefsKeySym_Greek_SIGMA                                 0x7d2
#define lkvnc_rfb_DefsKeySym_Greek_TAU                                   0x7d4
#define lkvnc_rfb_DefsKeySym_Greek_UPSILON                               0x7d5
#define lkvnc_rfb_DefsKeySym_Greek_PHI                                   0x7d6
#define lkvnc_rfb_DefsKeySym_Greek_CHI                                   0x7d7
#define lkvnc_rfb_DefsKeySym_Greek_PSI                                   0x7d8
#define lkvnc_rfb_DefsKeySym_Greek_OMEGA                                 0x7d9
#define lkvnc_rfb_DefsKeySym_Greek_alpha                                 0x7e1
#define lkvnc_rfb_DefsKeySym_Greek_beta                                  0x7e2
#define lkvnc_rfb_DefsKeySym_Greek_gamma                                 0x7e3
#define lkvnc_rfb_DefsKeySym_Greek_delta                                 0x7e4
#define lkvnc_rfb_DefsKeySym_Greek_epsilon                               0x7e5
#define lkvnc_rfb_DefsKeySym_Greek_zeta                                  0x7e6
#define lkvnc_rfb_DefsKeySym_Greek_eta                                   0x7e7
#define lkvnc_rfb_DefsKeySym_Greek_theta                                 0x7e8
#define lkvnc_rfb_DefsKeySym_Greek_iota                                  0x7e9
#define lkvnc_rfb_DefsKeySym_Greek_kappa                                 0x7ea
#define lkvnc_rfb_DefsKeySym_Greek_lamda                                 0x7eb
#define lkvnc_rfb_DefsKeySym_Greek_lambda                                0x7eb
#define lkvnc_rfb_DefsKeySym_Greek_mu                                    0x7ec
#define lkvnc_rfb_DefsKeySym_Greek_nu                                    0x7ed
#define lkvnc_rfb_DefsKeySym_Greek_xi                                    0x7ee
#define lkvnc_rfb_DefsKeySym_Greek_omicron                               0x7ef
#define lkvnc_rfb_DefsKeySym_Greek_pi                                    0x7f0
#define lkvnc_rfb_DefsKeySym_Greek_rho                                   0x7f1
#define lkvnc_rfb_DefsKeySym_Greek_sigma                                 0x7f2
#define lkvnc_rfb_DefsKeySym_Greek_finalsmallsigma                       0x7f3
#define lkvnc_rfb_DefsKeySym_Greek_tau                                   0x7f4
#define lkvnc_rfb_DefsKeySym_Greek_upsilon                               0x7f5
#define lkvnc_rfb_DefsKeySym_Greek_phi                                   0x7f6
#define lkvnc_rfb_DefsKeySym_Greek_chi                                   0x7f7
#define lkvnc_rfb_DefsKeySym_Greek_psi                                   0x7f8
#define lkvnc_rfb_DefsKeySym_Greek_omega                                 0x7f9
#define lkvnc_rfb_DefsKeySym_Greek_switch         0xFF7E  /* Alias for mode_switch */
#endif /* lkvnc_rfb_DefsKeySym_GREEK */

/*
 * Technical
 * Byte 3 = 8
 */

#ifdef lkvnc_rfb_DefsKeySym_TECHNICAL
#define lkvnc_rfb_DefsKeySym_leftradical                                 0x8a1
#define lkvnc_rfb_DefsKeySym_topleftradical                              0x8a2
#define lkvnc_rfb_DefsKeySym_horizconnector                              0x8a3
#define lkvnc_rfb_DefsKeySym_topintegral                                 0x8a4
#define lkvnc_rfb_DefsKeySym_botintegral                                 0x8a5
#define lkvnc_rfb_DefsKeySym_vertconnector                               0x8a6
#define lkvnc_rfb_DefsKeySym_topleftsqbracket                            0x8a7
#define lkvnc_rfb_DefsKeySym_botleftsqbracket                            0x8a8
#define lkvnc_rfb_DefsKeySym_toprightsqbracket                           0x8a9
#define lkvnc_rfb_DefsKeySym_botrightsqbracket                           0x8aa
#define lkvnc_rfb_DefsKeySym_topleftparens                               0x8ab
#define lkvnc_rfb_DefsKeySym_botleftparens                               0x8ac
#define lkvnc_rfb_DefsKeySym_toprightparens                              0x8ad
#define lkvnc_rfb_DefsKeySym_botrightparens                              0x8ae
#define lkvnc_rfb_DefsKeySym_leftmiddlecurlybrace                        0x8af
#define lkvnc_rfb_DefsKeySym_rightmiddlecurlybrace                       0x8b0
#define lkvnc_rfb_DefsKeySym_topleftsummation                            0x8b1
#define lkvnc_rfb_DefsKeySym_botleftsummation                            0x8b2
#define lkvnc_rfb_DefsKeySym_topvertsummationconnector                   0x8b3
#define lkvnc_rfb_DefsKeySym_botvertsummationconnector                   0x8b4
#define lkvnc_rfb_DefsKeySym_toprightsummation                           0x8b5
#define lkvnc_rfb_DefsKeySym_botrightsummation                           0x8b6
#define lkvnc_rfb_DefsKeySym_rightmiddlesummation                        0x8b7
#define lkvnc_rfb_DefsKeySym_lessthanequal                               0x8bc
#define lkvnc_rfb_DefsKeySym_notequal                                    0x8bd
#define lkvnc_rfb_DefsKeySym_greaterthanequal                            0x8be
#define lkvnc_rfb_DefsKeySym_integral                                    0x8bf
#define lkvnc_rfb_DefsKeySym_therefore                                   0x8c0
#define lkvnc_rfb_DefsKeySym_variation                                   0x8c1
#define lkvnc_rfb_DefsKeySym_infinity                                    0x8c2
#define lkvnc_rfb_DefsKeySym_nabla                                       0x8c5
#define lkvnc_rfb_DefsKeySym_approximate                                 0x8c8
#define lkvnc_rfb_DefsKeySym_similarequal                                0x8c9
#define lkvnc_rfb_DefsKeySym_ifonlyif                                    0x8cd
#define lkvnc_rfb_DefsKeySym_implies                                     0x8ce
#define lkvnc_rfb_DefsKeySym_identical                                   0x8cf
#define lkvnc_rfb_DefsKeySym_radical                                     0x8d6
#define lkvnc_rfb_DefsKeySym_includedin                                  0x8da
#define lkvnc_rfb_DefsKeySym_includes                                    0x8db
#define lkvnc_rfb_DefsKeySym_intersection                                0x8dc
#define lkvnc_rfb_DefsKeySym_union                                       0x8dd
#define lkvnc_rfb_DefsKeySym_logicaland                                  0x8de
#define lkvnc_rfb_DefsKeySym_logicalor                                   0x8df
#define lkvnc_rfb_DefsKeySym_partialderivative                           0x8ef
#define lkvnc_rfb_DefsKeySym_function                                    0x8f6
#define lkvnc_rfb_DefsKeySym_leftarrow                                   0x8fb
#define lkvnc_rfb_DefsKeySym_uparrow                                     0x8fc
#define lkvnc_rfb_DefsKeySym_rightarrow                                  0x8fd
#define lkvnc_rfb_DefsKeySym_downarrow                                   0x8fe
#endif /* lkvnc_rfb_DefsKeySym_TECHNICAL */

/*
 *  Special
 *  Byte 3 = 9
 */

#ifdef lkvnc_rfb_DefsKeySym_SPECIAL
#define lkvnc_rfb_DefsKeySym_blank                                       0x9df
#define lkvnc_rfb_DefsKeySym_soliddiamond                                0x9e0
#define lkvnc_rfb_DefsKeySym_checkerboard                                0x9e1
#define lkvnc_rfb_DefsKeySym_ht                                          0x9e2
#define lkvnc_rfb_DefsKeySym_ff                                          0x9e3
#define lkvnc_rfb_DefsKeySym_cr                                          0x9e4
#define lkvnc_rfb_DefsKeySym_lf                                          0x9e5
#define lkvnc_rfb_DefsKeySym_nl                                          0x9e8
#define lkvnc_rfb_DefsKeySym_vt                                          0x9e9
#define lkvnc_rfb_DefsKeySym_lowrightcorner                              0x9ea
#define lkvnc_rfb_DefsKeySym_uprightcorner                               0x9eb
#define lkvnc_rfb_DefsKeySym_upleftcorner                                0x9ec
#define lkvnc_rfb_DefsKeySym_lowleftcorner                               0x9ed
#define lkvnc_rfb_DefsKeySym_crossinglines                               0x9ee
#define lkvnc_rfb_DefsKeySym_horizlinescan1                              0x9ef
#define lkvnc_rfb_DefsKeySym_horizlinescan3                              0x9f0
#define lkvnc_rfb_DefsKeySym_horizlinescan5                              0x9f1
#define lkvnc_rfb_DefsKeySym_horizlinescan7                              0x9f2
#define lkvnc_rfb_DefsKeySym_horizlinescan9                              0x9f3
#define lkvnc_rfb_DefsKeySym_leftt                                       0x9f4
#define lkvnc_rfb_DefsKeySym_rightt                                      0x9f5
#define lkvnc_rfb_DefsKeySym_bott                                        0x9f6
#define lkvnc_rfb_DefsKeySym_topt                                        0x9f7
#define lkvnc_rfb_DefsKeySym_vertbar                                     0x9f8
#endif /* lkvnc_rfb_DefsKeySym_SPECIAL */

/*
 *  Publishing
 *  Byte 3 = a
 */

#ifdef lkvnc_rfb_DefsKeySym_PUBLISHING
#define lkvnc_rfb_DefsKeySym_emspace                                     0xaa1
#define lkvnc_rfb_DefsKeySym_enspace                                     0xaa2
#define lkvnc_rfb_DefsKeySym_em3space                                    0xaa3
#define lkvnc_rfb_DefsKeySym_em4space                                    0xaa4
#define lkvnc_rfb_DefsKeySym_digitspace                                  0xaa5
#define lkvnc_rfb_DefsKeySym_punctspace                                  0xaa6
#define lkvnc_rfb_DefsKeySym_thinspace                                   0xaa7
#define lkvnc_rfb_DefsKeySym_hairspace                                   0xaa8
#define lkvnc_rfb_DefsKeySym_emdash                                      0xaa9
#define lkvnc_rfb_DefsKeySym_endash                                      0xaaa
#define lkvnc_rfb_DefsKeySym_signifblank                                 0xaac
#define lkvnc_rfb_DefsKeySym_ellipsis                                    0xaae
#define lkvnc_rfb_DefsKeySym_doubbaselinedot                             0xaaf
#define lkvnc_rfb_DefsKeySym_onethird                                    0xab0
#define lkvnc_rfb_DefsKeySym_twothirds                                   0xab1
#define lkvnc_rfb_DefsKeySym_onefifth                                    0xab2
#define lkvnc_rfb_DefsKeySym_twofifths                                   0xab3
#define lkvnc_rfb_DefsKeySym_threefifths                                 0xab4
#define lkvnc_rfb_DefsKeySym_fourfifths                                  0xab5
#define lkvnc_rfb_DefsKeySym_onesixth                                    0xab6
#define lkvnc_rfb_DefsKeySym_fivesixths                                  0xab7
#define lkvnc_rfb_DefsKeySym_careof                                      0xab8
#define lkvnc_rfb_DefsKeySym_figdash                                     0xabb
#define lkvnc_rfb_DefsKeySym_leftanglebracket                            0xabc
#define lkvnc_rfb_DefsKeySym_decimalpoint                                0xabd
#define lkvnc_rfb_DefsKeySym_rightanglebracket                           0xabe
#define lkvnc_rfb_DefsKeySym_marker                                      0xabf
#define lkvnc_rfb_DefsKeySym_oneeighth                                   0xac3
#define lkvnc_rfb_DefsKeySym_threeeighths                                0xac4
#define lkvnc_rfb_DefsKeySym_fiveeighths                                 0xac5
#define lkvnc_rfb_DefsKeySym_seveneighths                                0xac6
#define lkvnc_rfb_DefsKeySym_trademark                                   0xac9
#define lkvnc_rfb_DefsKeySym_signaturemark                               0xaca
#define lkvnc_rfb_DefsKeySym_trademarkincircle                           0xacb
#define lkvnc_rfb_DefsKeySym_leftopentriangle                            0xacc
#define lkvnc_rfb_DefsKeySym_rightopentriangle                           0xacd
#define lkvnc_rfb_DefsKeySym_emopencircle                                0xace
#define lkvnc_rfb_DefsKeySym_emopenrectangle                             0xacf
#define lkvnc_rfb_DefsKeySym_leftsinglequotemark                         0xad0
#define lkvnc_rfb_DefsKeySym_rightsinglequotemark                        0xad1
#define lkvnc_rfb_DefsKeySym_leftdoublequotemark                         0xad2
#define lkvnc_rfb_DefsKeySym_rightdoublequotemark                        0xad3
#define lkvnc_rfb_DefsKeySym_prescription                                0xad4
#define lkvnc_rfb_DefsKeySym_minutes                                     0xad6
#define lkvnc_rfb_DefsKeySym_seconds                                     0xad7
#define lkvnc_rfb_DefsKeySym_latincross                                  0xad9
#define lkvnc_rfb_DefsKeySym_hexagram                                    0xada
#define lkvnc_rfb_DefsKeySym_filledrectbullet                            0xadb
#define lkvnc_rfb_DefsKeySym_filledlefttribullet                         0xadc
#define lkvnc_rfb_DefsKeySym_filledrighttribullet                        0xadd
#define lkvnc_rfb_DefsKeySym_emfilledcircle                              0xade
#define lkvnc_rfb_DefsKeySym_emfilledrect                                0xadf
#define lkvnc_rfb_DefsKeySym_enopencircbullet                            0xae0
#define lkvnc_rfb_DefsKeySym_enopensquarebullet                          0xae1
#define lkvnc_rfb_DefsKeySym_openrectbullet                              0xae2
#define lkvnc_rfb_DefsKeySym_opentribulletup                             0xae3
#define lkvnc_rfb_DefsKeySym_opentribulletdown                           0xae4
#define lkvnc_rfb_DefsKeySym_openstar                                    0xae5
#define lkvnc_rfb_DefsKeySym_enfilledcircbullet                          0xae6
#define lkvnc_rfb_DefsKeySym_enfilledsqbullet                            0xae7
#define lkvnc_rfb_DefsKeySym_filledtribulletup                           0xae8
#define lkvnc_rfb_DefsKeySym_filledtribulletdown                         0xae9
#define lkvnc_rfb_DefsKeySym_leftpointer                                 0xaea
#define lkvnc_rfb_DefsKeySym_rightpointer                                0xaeb
#define lkvnc_rfb_DefsKeySym_club                                        0xaec
#define lkvnc_rfb_DefsKeySym_diamond                                     0xaed
#define lkvnc_rfb_DefsKeySym_heart                                       0xaee
#define lkvnc_rfb_DefsKeySym_maltesecross                                0xaf0
#define lkvnc_rfb_DefsKeySym_dagger                                      0xaf1
#define lkvnc_rfb_DefsKeySym_doubledagger                                0xaf2
#define lkvnc_rfb_DefsKeySym_checkmark                                   0xaf3
#define lkvnc_rfb_DefsKeySym_ballotcross                                 0xaf4
#define lkvnc_rfb_DefsKeySym_musicalsharp                                0xaf5
#define lkvnc_rfb_DefsKeySym_musicalflat                                 0xaf6
#define lkvnc_rfb_DefsKeySym_malesymbol                                  0xaf7
#define lkvnc_rfb_DefsKeySym_femalesymbol                                0xaf8
#define lkvnc_rfb_DefsKeySym_telephone                                   0xaf9
#define lkvnc_rfb_DefsKeySym_telephonerecorder                           0xafa
#define lkvnc_rfb_DefsKeySym_phonographcopyright                         0xafb
#define lkvnc_rfb_DefsKeySym_caret                                       0xafc
#define lkvnc_rfb_DefsKeySym_singlelowquotemark                          0xafd
#define lkvnc_rfb_DefsKeySym_doublelowquotemark                          0xafe
#define lkvnc_rfb_DefsKeySym_cursor                                      0xaff
#endif /* lkvnc_rfb_DefsKeySym_PUBLISHING */

/*
 *  APL
 *  Byte 3 = b
 */

#ifdef lkvnc_rfb_DefsKeySym_APL
#define lkvnc_rfb_DefsKeySym_leftcaret                                   0xba3
#define lkvnc_rfb_DefsKeySym_rightcaret                                  0xba6
#define lkvnc_rfb_DefsKeySym_downcaret                                   0xba8
#define lkvnc_rfb_DefsKeySym_upcaret                                     0xba9
#define lkvnc_rfb_DefsKeySym_overbar                                     0xbc0
#define lkvnc_rfb_DefsKeySym_downtack                                    0xbc2
#define lkvnc_rfb_DefsKeySym_upshoe                                      0xbc3
#define lkvnc_rfb_DefsKeySym_downstile                                   0xbc4
#define lkvnc_rfb_DefsKeySym_underbar                                    0xbc6
#define lkvnc_rfb_DefsKeySym_jot                                         0xbca
#define lkvnc_rfb_DefsKeySym_quad                                        0xbcc
#define lkvnc_rfb_DefsKeySym_uptack                                      0xbce
#define lkvnc_rfb_DefsKeySym_circle                                      0xbcf
#define lkvnc_rfb_DefsKeySym_upstile                                     0xbd3
#define lkvnc_rfb_DefsKeySym_downshoe                                    0xbd6
#define lkvnc_rfb_DefsKeySym_rightshoe                                   0xbd8
#define lkvnc_rfb_DefsKeySym_leftshoe                                    0xbda
#define lkvnc_rfb_DefsKeySym_lefttack                                    0xbdc
#define lkvnc_rfb_DefsKeySym_righttack                                   0xbfc
#endif /* lkvnc_rfb_DefsKeySym_APL */

/*
 * Hebrew
 * Byte 3 = c
 */

#ifdef lkvnc_rfb_DefsKeySym_HEBREW
#define lkvnc_rfb_DefsKeySym_hebrew_doublelowline                        0xcdf
#define lkvnc_rfb_DefsKeySym_hebrew_aleph                                0xce0
#define lkvnc_rfb_DefsKeySym_hebrew_bet                                  0xce1
#define lkvnc_rfb_DefsKeySym_hebrew_beth                                 0xce1  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_gimel                                0xce2
#define lkvnc_rfb_DefsKeySym_hebrew_gimmel                               0xce2  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_dalet                                0xce3
#define lkvnc_rfb_DefsKeySym_hebrew_daleth                               0xce3  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_he                                   0xce4
#define lkvnc_rfb_DefsKeySym_hebrew_waw                                  0xce5
#define lkvnc_rfb_DefsKeySym_hebrew_zain                                 0xce6
#define lkvnc_rfb_DefsKeySym_hebrew_zayin                                0xce6  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_chet                                 0xce7
#define lkvnc_rfb_DefsKeySym_hebrew_het                                  0xce7  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_tet                                  0xce8
#define lkvnc_rfb_DefsKeySym_hebrew_teth                                 0xce8  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_yod                                  0xce9
#define lkvnc_rfb_DefsKeySym_hebrew_finalkaph                            0xcea
#define lkvnc_rfb_DefsKeySym_hebrew_kaph                                 0xceb
#define lkvnc_rfb_DefsKeySym_hebrew_lamed                                0xcec
#define lkvnc_rfb_DefsKeySym_hebrew_finalmem                             0xced
#define lkvnc_rfb_DefsKeySym_hebrew_mem                                  0xcee
#define lkvnc_rfb_DefsKeySym_hebrew_finalnun                             0xcef
#define lkvnc_rfb_DefsKeySym_hebrew_nun                                  0xcf0
#define lkvnc_rfb_DefsKeySym_hebrew_samech                               0xcf1
#define lkvnc_rfb_DefsKeySym_hebrew_samekh                               0xcf1  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_ayin                                 0xcf2
#define lkvnc_rfb_DefsKeySym_hebrew_finalpe                              0xcf3
#define lkvnc_rfb_DefsKeySym_hebrew_pe                                   0xcf4
#define lkvnc_rfb_DefsKeySym_hebrew_finalzade                            0xcf5
#define lkvnc_rfb_DefsKeySym_hebrew_finalzadi                            0xcf5  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_zade                                 0xcf6
#define lkvnc_rfb_DefsKeySym_hebrew_zadi                                 0xcf6  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_qoph                                 0xcf7
#define lkvnc_rfb_DefsKeySym_hebrew_kuf                                  0xcf7  /* deprecated */
#define lkvnc_rfb_DefsKeySym_hebrew_resh                                 0xcf8
#define lkvnc_rfb_DefsKeySym_hebrew_shin                                 0xcf9
#define lkvnc_rfb_DefsKeySym_hebrew_taw                                  0xcfa
#define lkvnc_rfb_DefsKeySym_hebrew_taf                                  0xcfa  /* deprecated */
#define lkvnc_rfb_DefsKeySym_Hebrew_switch        0xFF7E  /* Alias for mode_switch */
#endif /* lkvnc_rfb_DefsKeySym_HEBREW */

/*
 * Thai
 * Byte 3 = d
 */

#ifdef lkvnc_rfb_DefsKeySym_THAI
#define lkvnc_rfb_DefsKeySym_Thai_kokai					0xda1
#define lkvnc_rfb_DefsKeySym_Thai_khokhai					0xda2
#define lkvnc_rfb_DefsKeySym_Thai_khokhuat				0xda3
#define lkvnc_rfb_DefsKeySym_Thai_khokhwai				0xda4
#define lkvnc_rfb_DefsKeySym_Thai_khokhon					0xda5
#define lkvnc_rfb_DefsKeySym_Thai_khorakhang			        0xda6
#define lkvnc_rfb_DefsKeySym_Thai_ngongu					0xda7
#define lkvnc_rfb_DefsKeySym_Thai_chochan					0xda8
#define lkvnc_rfb_DefsKeySym_Thai_choching				0xda9
#define lkvnc_rfb_DefsKeySym_Thai_chochang				0xdaa
#define lkvnc_rfb_DefsKeySym_Thai_soso					0xdab
#define lkvnc_rfb_DefsKeySym_Thai_chochoe					0xdac
#define lkvnc_rfb_DefsKeySym_Thai_yoying					0xdad
#define lkvnc_rfb_DefsKeySym_Thai_dochada					0xdae
#define lkvnc_rfb_DefsKeySym_Thai_topatak					0xdaf
#define lkvnc_rfb_DefsKeySym_Thai_thothan					0xdb0
#define lkvnc_rfb_DefsKeySym_Thai_thonangmontho			        0xdb1
#define lkvnc_rfb_DefsKeySym_Thai_thophuthao			        0xdb2
#define lkvnc_rfb_DefsKeySym_Thai_nonen					0xdb3
#define lkvnc_rfb_DefsKeySym_Thai_dodek					0xdb4
#define lkvnc_rfb_DefsKeySym_Thai_totao					0xdb5
#define lkvnc_rfb_DefsKeySym_Thai_thothung				0xdb6
#define lkvnc_rfb_DefsKeySym_Thai_thothahan				0xdb7
#define lkvnc_rfb_DefsKeySym_Thai_thothong	 			0xdb8
#define lkvnc_rfb_DefsKeySym_Thai_nonu					0xdb9
#define lkvnc_rfb_DefsKeySym_Thai_bobaimai				0xdba
#define lkvnc_rfb_DefsKeySym_Thai_popla					0xdbb
#define lkvnc_rfb_DefsKeySym_Thai_phophung				0xdbc
#define lkvnc_rfb_DefsKeySym_Thai_fofa					0xdbd
#define lkvnc_rfb_DefsKeySym_Thai_phophan					0xdbe
#define lkvnc_rfb_DefsKeySym_Thai_fofan					0xdbf
#define lkvnc_rfb_DefsKeySym_Thai_phosamphao			        0xdc0
#define lkvnc_rfb_DefsKeySym_Thai_moma					0xdc1
#define lkvnc_rfb_DefsKeySym_Thai_yoyak					0xdc2
#define lkvnc_rfb_DefsKeySym_Thai_rorua					0xdc3
#define lkvnc_rfb_DefsKeySym_Thai_ru					0xdc4
#define lkvnc_rfb_DefsKeySym_Thai_loling					0xdc5
#define lkvnc_rfb_DefsKeySym_Thai_lu					0xdc6
#define lkvnc_rfb_DefsKeySym_Thai_wowaen					0xdc7
#define lkvnc_rfb_DefsKeySym_Thai_sosala					0xdc8
#define lkvnc_rfb_DefsKeySym_Thai_sorusi					0xdc9
#define lkvnc_rfb_DefsKeySym_Thai_sosua					0xdca
#define lkvnc_rfb_DefsKeySym_Thai_hohip					0xdcb
#define lkvnc_rfb_DefsKeySym_Thai_lochula					0xdcc
#define lkvnc_rfb_DefsKeySym_Thai_oang					0xdcd
#define lkvnc_rfb_DefsKeySym_Thai_honokhuk				0xdce
#define lkvnc_rfb_DefsKeySym_Thai_paiyannoi				0xdcf
#define lkvnc_rfb_DefsKeySym_Thai_saraa					0xdd0
#define lkvnc_rfb_DefsKeySym_Thai_maihanakat				0xdd1
#define lkvnc_rfb_DefsKeySym_Thai_saraaa					0xdd2
#define lkvnc_rfb_DefsKeySym_Thai_saraam					0xdd3
#define lkvnc_rfb_DefsKeySym_Thai_sarai					0xdd4
#define lkvnc_rfb_DefsKeySym_Thai_saraii					0xdd5
#define lkvnc_rfb_DefsKeySym_Thai_saraue					0xdd6
#define lkvnc_rfb_DefsKeySym_Thai_sarauee					0xdd7
#define lkvnc_rfb_DefsKeySym_Thai_sarau					0xdd8
#define lkvnc_rfb_DefsKeySym_Thai_sarauu					0xdd9
#define lkvnc_rfb_DefsKeySym_Thai_phinthu					0xdda
#define lkvnc_rfb_DefsKeySym_Thai_maihanakat_maitho   			0xdde
#define lkvnc_rfb_DefsKeySym_Thai_baht					0xddf
#define lkvnc_rfb_DefsKeySym_Thai_sarae					0xde0
#define lkvnc_rfb_DefsKeySym_Thai_saraae					0xde1
#define lkvnc_rfb_DefsKeySym_Thai_sarao					0xde2
#define lkvnc_rfb_DefsKeySym_Thai_saraaimaimuan				0xde3
#define lkvnc_rfb_DefsKeySym_Thai_saraaimaimalai				0xde4
#define lkvnc_rfb_DefsKeySym_Thai_lakkhangyao				0xde5
#define lkvnc_rfb_DefsKeySym_Thai_maiyamok				0xde6
#define lkvnc_rfb_DefsKeySym_Thai_maitaikhu				0xde7
#define lkvnc_rfb_DefsKeySym_Thai_maiek					0xde8
#define lkvnc_rfb_DefsKeySym_Thai_maitho					0xde9
#define lkvnc_rfb_DefsKeySym_Thai_maitri					0xdea
#define lkvnc_rfb_DefsKeySym_Thai_maichattawa				0xdeb
#define lkvnc_rfb_DefsKeySym_Thai_thanthakhat				0xdec
#define lkvnc_rfb_DefsKeySym_Thai_nikhahit				0xded
#define lkvnc_rfb_DefsKeySym_Thai_leksun					0xdf0
#define lkvnc_rfb_DefsKeySym_Thai_leknung					0xdf1
#define lkvnc_rfb_DefsKeySym_Thai_leksong					0xdf2
#define lkvnc_rfb_DefsKeySym_Thai_leksam					0xdf3
#define lkvnc_rfb_DefsKeySym_Thai_leksi					0xdf4
#define lkvnc_rfb_DefsKeySym_Thai_lekha					0xdf5
#define lkvnc_rfb_DefsKeySym_Thai_lekhok					0xdf6
#define lkvnc_rfb_DefsKeySym_Thai_lekchet					0xdf7
#define lkvnc_rfb_DefsKeySym_Thai_lekpaet					0xdf8
#define lkvnc_rfb_DefsKeySym_Thai_lekkao					0xdf9
#endif /* lkvnc_rfb_DefsKeySym_THAI */

/*
 *   Korean
 *   Byte 3 = e
 */

#ifdef lkvnc_rfb_DefsKeySym_KOREAN

#define lkvnc_rfb_DefsKeySym_Hangul		0xff31    /* Hangul start/stop(toggle) */
#define lkvnc_rfb_DefsKeySym_Hangul_Start		0xff32    /* Hangul start */
#define lkvnc_rfb_DefsKeySym_Hangul_End		0xff33    /* Hangul end, English start */
#define lkvnc_rfb_DefsKeySym_Hangul_Hanja		0xff34    /* Start Hangul->Hanja Conversion */
#define lkvnc_rfb_DefsKeySym_Hangul_Jamo		0xff35    /* Hangul Jamo mode */
#define lkvnc_rfb_DefsKeySym_Hangul_Romaja	0xff36    /* Hangul Romaja mode */
#define lkvnc_rfb_DefsKeySym_Hangul_Codeinput	0xff37    /* Hangul code input mode */
#define lkvnc_rfb_DefsKeySym_Hangul_Jeonja	0xff38    /* Jeonja mode */
#define lkvnc_rfb_DefsKeySym_Hangul_Banja		0xff39    /* Banja mode */
#define lkvnc_rfb_DefsKeySym_Hangul_PreHanja	0xff3a    /* Pre Hanja conversion */
#define lkvnc_rfb_DefsKeySym_Hangul_PostHanja	0xff3b    /* Post Hanja conversion */
#define lkvnc_rfb_DefsKeySym_Hangul_SingleCandidate	0xff3c    /* Single candidate */
#define lkvnc_rfb_DefsKeySym_Hangul_MultipleCandidate	0xff3d    /* Multiple candidate */
#define lkvnc_rfb_DefsKeySym_Hangul_PreviousCandidate	0xff3e    /* Previous candidate */
#define lkvnc_rfb_DefsKeySym_Hangul_Special	0xff3f    /* Special symbols */
#define lkvnc_rfb_DefsKeySym_Hangul_switch	0xFF7E    /* Alias for mode_switch */

/* Hangul Consonant Characters */
#define lkvnc_rfb_DefsKeySym_Hangul_Kiyeog				0xea1
#define lkvnc_rfb_DefsKeySym_Hangul_SsangKiyeog				0xea2
#define lkvnc_rfb_DefsKeySym_Hangul_KiyeogSios				0xea3
#define lkvnc_rfb_DefsKeySym_Hangul_Nieun					0xea4
#define lkvnc_rfb_DefsKeySym_Hangul_NieunJieuj				0xea5
#define lkvnc_rfb_DefsKeySym_Hangul_NieunHieuh				0xea6
#define lkvnc_rfb_DefsKeySym_Hangul_Dikeud				0xea7
#define lkvnc_rfb_DefsKeySym_Hangul_SsangDikeud				0xea8
#define lkvnc_rfb_DefsKeySym_Hangul_Rieul					0xea9
#define lkvnc_rfb_DefsKeySym_Hangul_RieulKiyeog				0xeaa
#define lkvnc_rfb_DefsKeySym_Hangul_RieulMieum				0xeab
#define lkvnc_rfb_DefsKeySym_Hangul_RieulPieub				0xeac
#define lkvnc_rfb_DefsKeySym_Hangul_RieulSios				0xead
#define lkvnc_rfb_DefsKeySym_Hangul_RieulTieut				0xeae
#define lkvnc_rfb_DefsKeySym_Hangul_RieulPhieuf				0xeaf
#define lkvnc_rfb_DefsKeySym_Hangul_RieulHieuh				0xeb0
#define lkvnc_rfb_DefsKeySym_Hangul_Mieum					0xeb1
#define lkvnc_rfb_DefsKeySym_Hangul_Pieub					0xeb2
#define lkvnc_rfb_DefsKeySym_Hangul_SsangPieub				0xeb3
#define lkvnc_rfb_DefsKeySym_Hangul_PieubSios				0xeb4
#define lkvnc_rfb_DefsKeySym_Hangul_Sios					0xeb5
#define lkvnc_rfb_DefsKeySym_Hangul_SsangSios				0xeb6
#define lkvnc_rfb_DefsKeySym_Hangul_Ieung					0xeb7
#define lkvnc_rfb_DefsKeySym_Hangul_Jieuj					0xeb8
#define lkvnc_rfb_DefsKeySym_Hangul_SsangJieuj				0xeb9
#define lkvnc_rfb_DefsKeySym_Hangul_Cieuc					0xeba
#define lkvnc_rfb_DefsKeySym_Hangul_Khieuq				0xebb
#define lkvnc_rfb_DefsKeySym_Hangul_Tieut					0xebc
#define lkvnc_rfb_DefsKeySym_Hangul_Phieuf				0xebd
#define lkvnc_rfb_DefsKeySym_Hangul_Hieuh					0xebe

/* Hangul Vowel Characters */
#define lkvnc_rfb_DefsKeySym_Hangul_A					0xebf
#define lkvnc_rfb_DefsKeySym_Hangul_AE					0xec0
#define lkvnc_rfb_DefsKeySym_Hangul_YA					0xec1
#define lkvnc_rfb_DefsKeySym_Hangul_YAE					0xec2
#define lkvnc_rfb_DefsKeySym_Hangul_EO					0xec3
#define lkvnc_rfb_DefsKeySym_Hangul_E					0xec4
#define lkvnc_rfb_DefsKeySym_Hangul_YEO					0xec5
#define lkvnc_rfb_DefsKeySym_Hangul_YE					0xec6
#define lkvnc_rfb_DefsKeySym_Hangul_O					0xec7
#define lkvnc_rfb_DefsKeySym_Hangul_WA					0xec8
#define lkvnc_rfb_DefsKeySym_Hangul_WAE					0xec9
#define lkvnc_rfb_DefsKeySym_Hangul_OE					0xeca
#define lkvnc_rfb_DefsKeySym_Hangul_YO					0xecb
#define lkvnc_rfb_DefsKeySym_Hangul_U					0xecc
#define lkvnc_rfb_DefsKeySym_Hangul_WEO					0xecd
#define lkvnc_rfb_DefsKeySym_Hangul_WE					0xece
#define lkvnc_rfb_DefsKeySym_Hangul_WI					0xecf
#define lkvnc_rfb_DefsKeySym_Hangul_YU					0xed0
#define lkvnc_rfb_DefsKeySym_Hangul_EU					0xed1
#define lkvnc_rfb_DefsKeySym_Hangul_YI					0xed2
#define lkvnc_rfb_DefsKeySym_Hangul_I					0xed3

/* Hangul syllable-final (JongSeong) Characters */
#define lkvnc_rfb_DefsKeySym_Hangul_J_Kiyeog				0xed4
#define lkvnc_rfb_DefsKeySym_Hangul_J_SsangKiyeog				0xed5
#define lkvnc_rfb_DefsKeySym_Hangul_J_KiyeogSios				0xed6
#define lkvnc_rfb_DefsKeySym_Hangul_J_Nieun				0xed7
#define lkvnc_rfb_DefsKeySym_Hangul_J_NieunJieuj				0xed8
#define lkvnc_rfb_DefsKeySym_Hangul_J_NieunHieuh				0xed9
#define lkvnc_rfb_DefsKeySym_Hangul_J_Dikeud				0xeda
#define lkvnc_rfb_DefsKeySym_Hangul_J_Rieul				0xedb
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulKiyeog				0xedc
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulMieum				0xedd
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulPieub				0xede
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulSios				0xedf
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulTieut				0xee0
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulPhieuf				0xee1
#define lkvnc_rfb_DefsKeySym_Hangul_J_RieulHieuh				0xee2
#define lkvnc_rfb_DefsKeySym_Hangul_J_Mieum				0xee3
#define lkvnc_rfb_DefsKeySym_Hangul_J_Pieub				0xee4
#define lkvnc_rfb_DefsKeySym_Hangul_J_PieubSios				0xee5
#define lkvnc_rfb_DefsKeySym_Hangul_J_Sios				0xee6
#define lkvnc_rfb_DefsKeySym_Hangul_J_SsangSios				0xee7
#define lkvnc_rfb_DefsKeySym_Hangul_J_Ieung				0xee8
#define lkvnc_rfb_DefsKeySym_Hangul_J_Jieuj				0xee9
#define lkvnc_rfb_DefsKeySym_Hangul_J_Cieuc				0xeea
#define lkvnc_rfb_DefsKeySym_Hangul_J_Khieuq				0xeeb
#define lkvnc_rfb_DefsKeySym_Hangul_J_Tieut				0xeec
#define lkvnc_rfb_DefsKeySym_Hangul_J_Phieuf				0xeed
#define lkvnc_rfb_DefsKeySym_Hangul_J_Hieuh				0xeee

/* Ancient Hangul Consonant Characters */
#define lkvnc_rfb_DefsKeySym_Hangul_RieulYeorinHieuh			0xeef
#define lkvnc_rfb_DefsKeySym_Hangul_SunkyeongeumMieum			0xef0
#define lkvnc_rfb_DefsKeySym_Hangul_SunkyeongeumPieub			0xef1
#define lkvnc_rfb_DefsKeySym_Hangul_PanSios				0xef2
#define lkvnc_rfb_DefsKeySym_Hangul_KkogjiDalrinIeung			0xef3
#define lkvnc_rfb_DefsKeySym_Hangul_SunkyeongeumPhieuf			0xef4
#define lkvnc_rfb_DefsKeySym_Hangul_YeorinHieuh				0xef5

/* Ancient Hangul Vowel Characters */
#define lkvnc_rfb_DefsKeySym_Hangul_AraeA					0xef6
#define lkvnc_rfb_DefsKeySym_Hangul_AraeAE				0xef7

/* Ancient Hangul syllable-final (JongSeong) Characters */
#define lkvnc_rfb_DefsKeySym_Hangul_J_PanSios				0xef8
#define lkvnc_rfb_DefsKeySym_Hangul_J_KkogjiDalrinIeung			0xef9
#define lkvnc_rfb_DefsKeySym_Hangul_J_YeorinHieuh				0xefa

/* Korean currency symbol */
#define lkvnc_rfb_DefsKeySym_Korean_Won					0xeff

#endif /* lkvnc_rfb_DefsKeySym_KOREAN */

#ifdef lkvnc_rfb_DefsKeySym_CURRENCY
#define lkvnc_rfb_DefsKeySym_EcuSign					0x20a0
#define lkvnc_rfb_DefsKeySym_ColonSign					0x20a1
#define lkvnc_rfb_DefsKeySym_CruzeiroSign					0x20a2
#define lkvnc_rfb_DefsKeySym_FFrancSign					0x20a3
#define lkvnc_rfb_DefsKeySym_LiraSign					0x20a4
#define lkvnc_rfb_DefsKeySym_MillSign					0x20a5
#define lkvnc_rfb_DefsKeySym_NairaSign					0x20a6
#define lkvnc_rfb_DefsKeySym_PesetaSign					0x20a7
#define lkvnc_rfb_DefsKeySym_RupeeSign					0x20a8
#define lkvnc_rfb_DefsKeySym_WonSign					0x20a9
#define lkvnc_rfb_DefsKeySym_NewSheqelSign				0x20aa
#define lkvnc_rfb_DefsKeySym_DongSign					0x20ab
#define lkvnc_rfb_DefsKeySym_EuroSign					0x20ac
#endif
