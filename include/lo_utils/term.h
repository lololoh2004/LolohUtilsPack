#pragma once

#include "common/defines.h"
#include "common/presets.h"
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

LOUTILS_API int  termGetKey(void);

LOUTILS_API void termProgBar(void);

#ifdef __cplusplus
LOUTILS_API void termClear(modePriority mode = TYPE_OPTI);
LOUTILS_API void termMsg(const char* text = "Debug MSG\n", const char* entry = "???", rgb textColor = COLOR_DEFLT){
    termSetTextClr(textColor);
    termMsgChar(text, entry);
    termResetTextClr();
}
LOUTILS_API void termWait(const char* text = "Press ENTER to continue..\n");
#else
LOUTILS_API void termClear(modePriority mode);
LOUTILS_API void termWait(const char* text);

#endif

EXTERN_C_END