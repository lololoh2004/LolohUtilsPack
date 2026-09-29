#pragma once

#include "lo_utils/common/defines.h"
#include "lo_utils/common/types.h"

EXTERN_C_START
LOUTILS_API void termSetupEnv(void);
LOUTILS_API void termSetTextClr(rgb term_color);
LOUTILS_API void termResetTextClr(void);

LOUTILS_API int  termGetKey(void);

LOUTILS_API void termProgBar(void);

LOUTILS_API void termClear(modePriority mode);
EXTERN_C_END