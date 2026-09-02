#pragma once

#ifdef LOUTILS_SHARED
    #ifdef _WIN32
        #define LOUTILS_API __declspec(dllexport)
    #else
        #define LOUTILS_API __attribute__((visibility("default")))
    #endif
#else
    #define LOUTILS_API
#endif

#ifdef __cplusplus
    #define EXTERN_C_START extern "C" {
    #define EXTERN_C_END   }
#else
    #define EXTERN_C_START
    #define EXTERN_C_END
#endif

#define RETURN_FAILURE (-1)
#define RETURN_SUCCESS (0)