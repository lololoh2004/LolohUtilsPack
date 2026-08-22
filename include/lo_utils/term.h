#pragma once

#include "common.h"

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

LOUTILS_API void termClear(modePriority mode);
LOUTILS_API void termSetColor(rgb term_color);
LOUTILS_API void termMsg(const char* text, const char* entry);
LOUTILS_API void termMsgC(const char* text, const char* entry, rgb term_color);
LOUTILS_API void termWait(const char* text);
LOUTILS_API int  termGetKey(void);

LOUTILS_API void termProgBar(void);