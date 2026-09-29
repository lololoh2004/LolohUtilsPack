#pragma once

#include "lo_utils/common/defines.h"

EXTERN_C_START
LOUTILS_API void termMsgChar(const char* text, const char* entry);
LOUTILS_API void termMsgInt(int num, const char* entry);
LOUTILS_API void termMsgFloat(float num, const char* entry);
LOUTILS_API void termMsgPtr(float ptr, const char* entry);

LOUTILS_API void termWait(const char* text);
EXTERN_C_END