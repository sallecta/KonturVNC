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



#include "Environment.h"
#include "CtrlAltDelSimulator.h"

#include <shlobj.h>
#include <crtdbg.h>
#include "AutoImpersonator.h"
#include "WTS.h"
#include "ProcessHandle.h"
#include "CurrentConsoleProcess.h"

#include "RegistryKey.h"


#include "Shell.h"
#include "DynamicLibrary.h"
#include <vector>

OSVERSIONINFO Environment::m_osVerInfo = { 0 };
typedef VOID (WINAPI *SendSas)(BOOL asUser);
typedef HRESULT (WINAPI *DwmIsCompositionEnabled)(BOOL *pfEnabled);
typedef HRESULT (WINAPI *DwmEnableComposition)(UINT pfEnabled);

Environment::Environment()
{
}

Environment::~Environment()
{
}






void Environment::getErrStr(StringStorage *out)
{
  DWORD errCode = GetLastError();
  TCHAR buffer[1024];

  // FIXME: Remove "new line" character from buffer.
  if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                    NULL, errCode,
                    MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
                    (LPTSTR)&buffer[0],
                    sizeof(buffer), NULL) == 0) {
    out->format(_T("<<Cannot get text error describing>> (%u)"), errCode);
  } else {
    out->format(_T("%s (%u)"), buffer, errCode);
  }
}

void Environment::getErrStr(const TCHAR *specification, StringStorage *out)
{
  StringStorage sysErrText;
  getErrStr(&sysErrText);
  out->format(_T("%s (%s)"), specification, sysErrText.getString());
}

bool Environment::getSpecialFolderPath(int specialFolderId, StringStorage *out)
{
  _ASSERT(out != NULL);

  int csidl = 0;

  switch (specialFolderId) {
  case APPLICATION_DATA_SPECIAL_FOLDER:
    csidl = CSIDL_APPDATA;
    break;
  case COMMON_APPLICATION_DATA_SPECIAL_FOLDER:
    csidl = CSIDL_COMMON_APPDATA;
    break;
  case USERDESKTOP_DATA_SPECIAL_FOLDER:
	 csidl = CSIDL_DESKTOPDIRECTORY;
	 break;
  case USERDOCS_DATA_SPECIAL_FOLDER:
	 csidl = CSIDL_MYDOCUMENTS;
	 break;

  default:
    _ASSERT(FALSE);
    return false;
  } // switch

  bool returnVal = false;

  TCHAR path[MAX_PATH + 1];




  if (SHGetSpecialFolderPath(NULL, &path[0], csidl, TRUE) == TRUE) {
    out->setString(&path[0]);
    returnVal = true;
  }

  return returnVal;
}

bool Environment::getCurrentModulePath(StringStorage *out)
{
  std::vector<TCHAR> buffer;
  DWORD size = MAX_PATH;

  while (true) {
    // Allocate buffer
    buffer.resize(size + 1);
    // Try to get file name
    DWORD ret = GetModuleFileName(NULL, &buffer[0], size);

    if (ret == 0) {
      return false;
    } else if (GetLastError() == ERROR_INSUFFICIENT_BUFFER) {
      size += 128;
    } else {
      break;
    }
  } // while

  out->setString(&buffer[0]);

  return true;
} // void

bool Environment::isItTheSamePathAsCurrent(unsigned int pId)
{
  StringStorage currModulePath, testedModulePath;
  ProcessHandle pHandle;

  pHandle.openProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
                      0, pId);
  pHandle.getProcessModulePath(&testedModulePath);
  getCurrentModulePath(&currModulePath);

  return currModulePath.isEqualTo(&testedModulePath);
}

bool Environment::getCurrentModuleFolderPath(StringStorage *out)
{
  if (!getCurrentModulePath(out)) {
    return false;
  }

  size_t lastPos = out->findLast(_T('\\'));

  if (lastPos != (size_t)-1) {
    out->getSubstring(out, 0, std::max(static_cast<int>(lastPos -1), 0));
  }

  return true;
}

bool Environment::getCurrentUserName(StringStorage *out, LogWriter *log)
{
  return WTS::getCurrentUserName(out, log);
}

bool Environment::getComputerName(StringStorage *out)
{
  TCHAR compName[MAX_COMPUTERNAME_LENGTH + 1];
  DWORD length = MAX_COMPUTERNAME_LENGTH + 1;
  if (GetComputerName(compName, &length) == 0) {
    return false;
  }
  out->setString(compName);
  out->toLowerCase();
  return true;
}

void Environment::restoreWallpaper(LogWriter *log)
{

  //DisableAero(log,true);
  // FIXME: Remove log from here. Log only from caller.
  log->info(_T("Try to restore wallpaper"));
  Impersonator imp(log);
  AutoImpersonator ai(&imp, log);

  if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, 0, 0) == 0) {
      throw SystemException(_T("Cannot restore desktop wallpaper"));
  }

  int ret = 1;

SystemParametersInfo(SPI_SETMENUANIMATION, 1,&ret, 0);
SystemParametersInfo(SPI_SETSELECTIONFADE, 1, &ret, 0);
SystemParametersInfo(SPI_SETTOOLTIPANIMATION, 1, &ret, 0);
SystemParametersInfo(0x1043, 1, &ret, 0);
SystemParametersInfo(SPI_SETDROPSHADOW, 1, &ret, 0);
SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, 1, &ret, 0);



// enable animation

ANIMATIONINFO animinf;
//UINT prevAnim;

animinf.cbSize = sizeof(ANIMATIONINFO);
SystemParametersInfo(SPI_GETANIMATION,sizeof(ANIMATIONINFO),&animinf,0);
animinf.iMinAnimate = 1;
SystemParametersInfo(SPI_SETANIMATION,sizeof(ANIMATIONINFO),&animinf,0);

}

void Environment::disableWallpaper(LogWriter *log)
{


  log->info(_T("Try to disable wallpaper"));
  Impersonator imp(log);
  AutoImpersonator ai(&imp, log);

  Sleep(300); // dirty hack, wait for mirage driver

  if (SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, _T(""), 0) == 0) {
    throw SystemException(_T("Cannot disable desktop wallpaper"));
  }

  // disable visual effects

  if (SystemParametersInfo(SPI_SETMENUANIMATION, 0, NULL, 0) == 0) {
    throw SystemException(_T("Cannot disable menu animation"));
  }
  if (SystemParametersInfo(SPI_SETSELECTIONFADE, 0, NULL, 0) == 0) {
    throw SystemException(_T("Cannot disable selection fade"));
  }
  if (SystemParametersInfo(SPI_SETTOOLTIPANIMATION, 0, NULL, 0) == 0) {
    throw SystemException(_T("Cannot disable tooltip animation"));
  }
  if (SystemParametersInfo(0x1043, 0, NULL, 0) == 0) { // SPI_SETCLIENTAREAANIMATION
    throw SystemException(_T("Cannot disable client area animation"));
  }
  if (SystemParametersInfo(SPI_SETDROPSHADOW, 0, NULL, 0) == 0) {
    throw SystemException(_T("Cannot disable drop shadow"));
  }
  if (SystemParametersInfo(SPI_SETDRAGFULLWINDOWS, 0, NULL, 0) == 0) {
    throw SystemException(_T("Cannot disable drag fullwindow"));
  }


// disable animation


ANIMATIONINFO animinf;
UINT prevAnim;

animinf.cbSize = sizeof(ANIMATIONINFO);
SystemParametersInfo(SPI_GETANIMATION,sizeof(ANIMATIONINFO),&animinf,0);
prevAnim = animinf.iMinAnimate;

if(prevAnim)
{
animinf.iMinAnimate = 0;
SystemParametersInfo(SPI_SETANIMATION,sizeof(ANIMATIONINFO),&animinf,0);
}

//////


}

void Environment::init()
{
  if (m_osVerInfo.dwOSVersionInfoSize == 0) {
    m_osVerInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

    if (!GetVersionEx(&m_osVerInfo)) {
      m_osVerInfo.dwOSVersionInfoSize = 0;
    }
  }
}

bool Environment::isWinNTFamily()
{
  init();
  return m_osVerInfo.dwPlatformId == VER_PLATFORM_WIN32_NT;
}

bool Environment::isWin2000()
{
  init();
  return m_osVerInfo.dwMajorVersion == 5 && m_osVerInfo.dwMinorVersion == 0;
}

bool Environment::isWinXP()
{
  init();
  return ((m_osVerInfo.dwMajorVersion == 5) && (m_osVerInfo.dwMinorVersion == 1) && isWinNTFamily());
}

bool Environment::isWin2003Server()
{
  init();
  return ((m_osVerInfo.dwMajorVersion == 5) && (m_osVerInfo.dwMinorVersion == 2) && isWinNTFamily());
}

bool Environment::isVistaOrLater()
{
  init();
  return m_osVerInfo.dwMajorVersion >= 6;
}

void Environment::simulateCtrlAltDel(LogWriter *log)
{
  // FIXME: Do not use log here.
  log->info(_T("Requested Ctrl+Alt+Del simulation"));



  // Are we running on Windows NT OS family?
  if (!isVistaOrLater() && isWinNTFamily()) {
    CtrlAltDelSimulator cadSim;
    cadSim.wait();
  }else{
	simulateCtrlAltDelUnderVista(log);
  }

}

void Environment::startControlPanel(LogWriter *log)
{

}

void Environment::simulateCtrlAltDelUnderVista(LogWriter *log)
{
  // FIXME: Do not use log here.
  log->info(_T("Requested Ctrl+Alt+Del simulation under Vista or later"));

  Process *m_process;
  StringStorage currentModulePath;
  Environment::getCurrentModulePath(&currentModulePath);
  StringStorage path;
  path.format(_T("\"%s\""), currentModulePath.getString());

  m_process = new CurrentConsoleProcess(log,path.getString(),_T(""),0);
  m_process->start();


  /*

  try {
    DynamicLibrary sasLib(_T("sas.dll"));
    SendSas sendSas = (SendSas)sasLib.getProcAddress("SendSAS");
    if (sendSas == 0) {
      throw Exception(_T("The SendSAS function has not been found"));
    }
    sendSas(FALSE); // Try only under service
  } catch (Exception &e) {
    log->error(_T("The simulateCtrlAltDelUnderVista() function failed: %s"),
               e.getMessage());
  }
  */
}



bool Environment::isAeroOn(LogWriter *log)
{
  try {
    DynamicLibrary dwmLib(_T("Dwmapi.dll"));
    DwmIsCompositionEnabled dwmIsEnabled =
      (DwmIsCompositionEnabled)dwmLib.getProcAddress("DwmIsCompositionEnabled");
    if (dwmIsEnabled == 0) {
      throw Exception(_T("The DwmIsCompositionEnabled() has not been found in the Dwmapi.dll"));
    }
    BOOL result = FALSE;
    HRESULT dwmIsEnabledResult = dwmIsEnabled(&result);
    if (dwmIsEnabledResult != S_OK) {
      StringStorage errMess;
      errMess.format(_T("The DwmIsCompositionEnabled() error code is %d"),
                     (int)dwmIsEnabledResult);
      throw Exception(_T(""));
    }
    return result != FALSE;
  } catch (Exception &e) {
    log->error(_T("The DwmIsCompositionEnabled() function failed: %s"),
               e.getMessage());
    throw;
  }
}

bool Environment::initReboot()
{
    HANDLE hToken;
   TOKEN_PRIVILEGES tkp;

   // Get a token for this process.

   if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
      return( FALSE );

   // Get the LUID for the shutdown privilege.

   LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
        &tkp.Privileges[0].Luid);

   tkp.PrivilegeCount = 1;  // one privilege to set
   tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

   // Get the shutdown privilege for this process.

   AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
        (PTOKEN_PRIVILEGES)NULL, 0);

   if (GetLastError() != ERROR_SUCCESS)
      return FALSE;

   // Shut down the system and force all applications to close.

   if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE,
               SHTDN_REASON_MAJOR_OPERATINGSYSTEM |
               SHTDN_REASON_MINOR_UPGRADE |
               SHTDN_REASON_FLAG_PLANNED))
      return FALSE;

   //shutdown was successful
   return TRUE;
}


void Environment::RemoteReboot()
{

StringStorage folder,path;

if (Environment::getCurrentModuleFolderPath(&path)) {
    StringStorage entry(_T("Software\\Microsoft\\")
                        _T("Windows\\CurrentVersion\\RunOnce\\"));
	folder.format(_T("%s\\konturvnc.exe"),path.getString());
	folder.quoteSelf();
	RegistryKey regKey(HKEY_CURRENT_USER, entry.getString());
	regKey.setValueAsString(_T("konturVNC"), folder.getString());
}

Environment::initReboot();

}
