#pragma once

#ifdef __cplusplus
#include <type_traits>
#endif

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
LOUTILS_API void termMsgFloat(float num, const char* entry);
LOUTILS_API void termMsgPtr(float ptr, const char* entry);

LOUTILS_API int  termGetKey(void);

LOUTILS_API void termProgBar(void);

EXTERN_C_END

#ifdef __cplusplus
LOUTILS_API void termClear(modePriority mode = TYPE_OPTI);
template <typename T>
LOUTILS_API void termMsg(T val, const char* entry = "???", rgb textColor = COLOR_DEFLT){
    termSetTextClr(textColor);
    if constexpr (std::is_integral_v<T>)            termMsgInt(static_cast<int>(val), entry);
    else if constexpr (std::is_floating_point_v<T>) termMsgFloat(static_cast<float>(val), entry);
    else if constexpr (std::is_pointer_v<T>)        termMsgPtr(val, entry);
    else                                            static_assert(sizeof(T) == 0, "This type isnt supported in termMsg!");
    termResetTextClr();
}
EXTERN_C_START
LOUTILS_API void termMsg(const char* text = "DEBUG TEXT", const char* entry = "???", rgb textColor = COLOR_DEFLT);
LOUTILS_API void termWait(const char* text = "Press ENTER to continue..\n");
EXTERN_C_END

#else
EXTERN_C_START
LOUTILS_API void termClear(modePriority mode);
LOUTILS_API void termWait(const char* text);

EXTERN_C_END

#endif

