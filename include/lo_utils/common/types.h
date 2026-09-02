#pragma once

typedef enum{
    TYPE_FULL    = 1 << 0,
    TYPE_BALANCE = 1 << 1,
    TYPE_OPTI    = 1 << 2
} modePriority;

typedef struct{
    unsigned char r,g,b;
} rgb;
