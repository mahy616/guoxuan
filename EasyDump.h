#pragma once
#include <windows.h>
#include <DbgHelp.h>

LONG WINAPI ExceptionFilter(LPEXCEPTION_POINTERS lpExceptionInfo);
