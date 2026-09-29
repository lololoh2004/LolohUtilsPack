#pragma once

#include "lo_utils/common/defines.h"

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
EXTERN_C_END