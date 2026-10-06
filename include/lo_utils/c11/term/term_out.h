#pragma once

#include "lo_utils/common/defines.h"
#include "lo_utils/common/types.h"

EXTERN_C_START
LOUTILS_API void termMsgChar(const char* text, const char* entry);
LOUTILS_API void termMsgCharLen(const char* text, int size, const char* entry);
LOUTILS_API void termMsgInt(int num, const char* entry);
LOUTILS_API void termMsgFloat(float num, const char* entry);
LOUTILS_API void termMsgPtr(const void* ptr, const char* entry);

LOUTILS_API void termMvLine();

LOUTILS_API void termSetTextClr(rgb term_color);
LOUTILS_API void termResetTextClr(void);

LOUTILS_API void termWait(const char* text);
EXTERN_C_END