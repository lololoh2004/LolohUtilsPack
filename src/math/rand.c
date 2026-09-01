#include "lo_utils/math.h"

#include <stdint.h>

static uint32_t seed = 123456789;

void setRngSeed(unsigned int inSeed){
    seed = (inSeed == 0) ? seed : inSeed;
}
int getRandInt(int min, int max){
    if (min == max) return min;
    if (min > max){
        int temp = min;
        min = max;
        max = temp;
    }
    uint32_t x = seed;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    seed = x;

    uint32_t range = (uint32_t)max - (uint32_t)min + 1;
    return min + (int)(x % range);
}