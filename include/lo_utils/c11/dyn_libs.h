#pragma once

#include "lo_utils/common/defines.h"

#define DL_HANDLE void*

LOUTILS_API DL_HANDLE getDLHandle(const char* path);
LOUTILS_API void* getDLFuncPtr(DL_HANDLE handle, const char* func_name);
LOUTILS_API void freeDLHandle(DL_HANDLE handle);