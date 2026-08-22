#pragma once

#include "common.h"

#define DL_HANDLE void*

LOUTILS_API DL_HANDLE getDLHandle(const char* path);
LOUTILS_API void* getDLFuncPtr(DL_HANDLE handle, const char* func_name);