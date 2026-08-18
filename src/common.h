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

#include <stddef.h>

typedef enum{
    TYPE_FULL    = 1 << 0,
    TYPE_BALANCE = 1 << 1,
    TYPE_OPTI    = 1 << 2
} modePriority;

// typedef enum{
//     SYSTEM_WIN32   = 1 << 0,
//     SYSTEM_UNIX    = 1 << 1,
//     SYSTEM_UNKNOWN = 1 << 2
// } systemType;

typedef struct{
    unsigned char r,g,b;
} rgb;
static const rgb COLOR_BLACK   = {0,   0,   0};
static const rgb COLOR_RED     = {255, 0,   0};
static const rgb COLOR_GREEN   = {0,   255, 0};
static const rgb COLOR_YELLOW  = {255, 255, 0};
static const rgb COLOR_BLUE    = {0,   0,   255};
static const rgb COLOR_MAGENTA = {255, 0,   255};
static const rgb COLOR_CYAN    = {0,   255, 255};
static const rgb COLOR_WHITE   = {255, 255, 255};
static const rgb COLOR_GRAY    = {128, 128, 128};