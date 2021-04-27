// Copyright (C) 2010,2011,2012 GlavSoft LLC.
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

#include <windows.h>
#include <Dbghelp.h>
#include "CrashHook.h"
#include "../libkvnc_all_winSystem/DynamicLibrary.h"
#include "../libkvnc_all_winSystem/Environment.h"
#include "../libkvnc_all_winSystem/RegistryKey.h"
#include "../libkvnc_all_thread/AutoLock.h"
#include "../libkvnc_server_app/NamingDefs.h"

//typedef BOOL (WINAPI *MINIDUMPWRITEDUMP)(__in  HANDLE hProcess,
//                                       __in  DWORD ProcessId,
//                                       __in  HANDLE hFile,
//                                       __in  MINIDUMP_TYPE DumpType,
//                                       __in  PMINIDUMP_EXCEPTION_INFORMATION ExceptionParam,
//                                       __in  PMINIDUMP_USER_STREAM_INFORMATION UserStreamParam,
//                                       __in  PMINIDUMP_CALLBACK_INFORMATION CallbackParam);

#include <windows.h>
#include <Dbghelp.h>
extern "C" {

typedef BOOL (WINAPI * MINIDUMPWRITEDUMP)
    (HANDLE,
    DWORD,
    HANDLE,
    MINIDUMP_TYPE,
    PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION,
    PMINIDUMP_CALLBACK_INFORMATION);

/*!
 * \brief Application top level exception handler that creates (if it's possible) core dump
 * @param pExceptionInfo pointer to exception information
 */
LONG WINAPI TopLevelFilter(struct _EXCEPTION_POINTERS* pExceptionInfo);

}


bool CrashHook::m_guiEnabled = false;
HKEY CrashHook::m_rootHkey = HKEY_CURRENT_USER;
LocalMutex CrashHook::m_guiEnabledMutex;
ApplicationCrashEvents *CrashHook::m_notifier = 0;

CrashHook::CrashHook(ApplicationCrashEvents *notifier)
{
  m_notifier = notifier;
  ::SetUnhandledExceptionFilter(topLevelExceptionFilter);
}

CrashHook::~CrashHook()
{
}

LONG WINAPI CrashHook::topLevelExceptionFilter(_EXCEPTION_POINTERS *pExceptionInfo)
{
  bool guiEnabled;
  {
    AutoLock al(&m_guiEnabledMutex);
    guiEnabled = m_guiEnabled;
  }

  LONG retValue = EXCEPTION_CONTINUE_SEARCH;

  DynamicLibrary dbgLib;
  MINIDUMPWRITEDUMP miniDumpWriteDump = 0;
  try {
    // Try load the library from this exe mofule folder
    StringStorage libName, moduleFolder;
    Environment::getCurrentModuleFolderPath(&moduleFolder);
    libName.format(_T("%s\\DbgHelp.dll"), moduleFolder.getString());

    dbgLib.init(libName.getString());
    miniDumpWriteDump = (MINIDUMPWRITEDUMP)
                          dbgLib.getProcAddress("MiniDumpWriteDump");
  } catch (...) {
    try {
      // Try load the library by default path
      dbgLib.init(_T("DbgHelp.dll"));
      miniDumpWriteDump = (MINIDUMPWRITEDUMP)
                            dbgLib.getProcAddress("MiniDumpWriteDump");
    } catch (...) {
      return retValue;
    }
  }
  if (miniDumpWriteDump == 0) {
    return retValue;
  }

  StringStorage specFolder, dumpPath;
  if (!Environment::getSpecialFolderPath(
         Environment::APPLICATION_DATA_SPECIAL_FOLDER, &specFolder)) {
    return retValue;
  }
  dumpPath.format(_T("%s\\%s\\crash.dmp"), specFolder.getString(),
                                           ProductNames::PRODUCT_NAME);

  if (guiEnabled && MessageBox(0,
                               _T("��������� ���������. ������ ��������� ����������, �������� ��� ������������� ���������?"),
                               ProductNames::PRODUCT_NAME,
                               MB_YESNO)
                               != IDYES)
  {
    return retValue;
  }
  HANDLE hFile = 0;
  try {
    // Store path to the registry.
    try {
      HKEY root;
      {
        AutoLock al(&m_guiEnabledMutex);
        root = m_rootHkey;
      }
      RegistryKey regKey(root, RegistryPaths::SERVER_PATH);
      regKey.setValueAsString(_T("CrashDumpPath"), dumpPath.getString());
    } catch (Exception &) {
    }

    // FIXME: use the "file-lib" project from the trunk hive.
    hFile = ::CreateFile(dumpPath.getString(),
                         GENERIC_WRITE,
                         FILE_SHARE_WRITE,
                         0,
                         CREATE_ALWAYS,
                         FILE_ATTRIBUTE_NORMAL,
                         0);
    if (hFile == INVALID_HANDLE_VALUE) {
      throw Exception(_T("�� ������� ������� ���� ��� ���������� ���������� ����������"));
    }

    _MINIDUMP_EXCEPTION_INFORMATION exInfo;

    exInfo.ThreadId = ::GetCurrentThreadId();
    exInfo.ExceptionPointers = pExceptionInfo;
    exInfo.ClientPointers = 0;

    BOOL result = miniDumpWriteDump(GetCurrentProcess(),
                                    GetCurrentProcessId(),
                                    hFile,
                                    MiniDumpNormal,
                                    &exInfo,
                                    0,
                                    0);
    if (result == 0) {
      throw Exception(_T("�� ������� ������� ���� � ���������� �����������"));
    }
    if (guiEnabled) {
      StringStorage succMess;
      succMess.format(_T("���������� ���������� ������� ��������� � ����� %s"), dumpPath.getString());
      MessageBox(0, succMess.getString(), ProductNames::PRODUCT_NAME, MB_OK);
    }
    m_notifier->onCrash(&dumpPath);

    retValue = EXCEPTION_EXECUTE_HANDLER;
  } catch (Exception &e) {
    if (guiEnabled) {
      MessageBox(NULL, e.getMessage(), ProductNames::PRODUCT_NAME, MB_OK);
    }
  }
  if (hFile != 0) {
    CloseHandle(hFile);
  }

  return retValue;
}

void CrashHook::setGuiEnabled()
{
  AutoLock al(&m_guiEnabledMutex);
  m_guiEnabled = true;
}

void CrashHook::setHklmRoot()
{
  AutoLock al(&m_guiEnabledMutex);
  m_rootHkey = HKEY_LOCAL_MACHINE;
}
