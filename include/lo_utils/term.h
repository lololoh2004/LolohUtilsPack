#pragma once

#include "common/defines.h"
#include "common/types.h"

EXTERN_C_START
typedef enum {
    LOG_INFO    = 1 << 0,
    LOG_WARNING = 1 << 1,
    LOG_ERROR   = 1 << 2,
} logStatus;
typedef enum {
    TERM_SUPPORT_RGB = 0,
    TERM_SUPPORT_ANSI,
    TERM_DOESNT_SUPPORT_COLOR
} termColorType;
extern termColorType systemType;

LOUTILS_API void termSetupEnv(void);
LOUTILS_API void termSetTextClr(rgb term_color);
LOUTILS_API void termResetTextClr(void);

LOUTILS_API void termMsgChar(const char* text, const char* entry);
LOUTILS_API void termMsgInt(int num, const char* entry);
LOUTILS_API void termMsgFloat(float num, const char* entry);
LOUTILS_API void termMsgPtr(float ptr, const char* entry);
LOUTILS_API int  termGetKey(void);

LOUTILS_API void termProgBar(void);

LOUTILS_API void termClear(modePriority mode);
LOUTILS_API void termWait(const char* text);
EXTERN_C_END