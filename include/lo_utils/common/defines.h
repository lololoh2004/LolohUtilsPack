#pragma once


#ifdef LOUTILS_SHARED
    #ifdef _WIN32
        #ifdef LOUTILS_EXPORTS
            #define LOUTILS_API __declspec(dllexport)
        #else
            #define LOUTILS_API __declspec(dllimport)
        #endif
    #else
        #define LOUTILS_API __attribute__((visibility("default")))
    #endif
#else
    #define LOUTILS_API
#endif


#ifdef __cplusplus
    #include <cstddef>

    #define EXTERN_C_START extern "C" {
    #define EXTERN_C_END   }
#else
    #include <stddef.h>
    #include <stdbool.h>

    #define EXTERN_C_START
    #define EXTERN_C_END
#endif


#define RETURN_FAILURE (-1)
#define RETURN_SUCCESS (0)


#ifndef EXPORT_MACRO
    #ifdef _WIN32
        #define EXPORT_MACRO __declspec(dllexport)
    #else
        #define EXPORT_MACRO __attribute__((visibility("default")))
    #endif
#endif

#ifndef C_EXPORT_MACRO
    #if defined(_WIN32)
        #define GAME_API extern "C" __declspec(dllexport)
    #else
        #define GAME_API extern "C" __attribute__((visibility("default")))
    #endif
#endif