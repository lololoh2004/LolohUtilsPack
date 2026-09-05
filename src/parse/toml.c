#include "lo_utils/parse.h"
#include <string.h>
#include <stdio.h>


size_t getTomlTableSize(const char* tomlContent, const char* name){
    const char* result = tomlContent;
    size_t size=0;

    size_t buffSize = strlen(name) + 2 + 1;
    char searchName[buffSize];
    snprintf(searchName, buffSize, "[%s]", name);

    result = strstr(result, searchName);
    if (result == NULL){ return 0; }

    while (1){
        result = strchr(result, '\n');
        if (result == NULL)
            break;

        result++;
        while (*result == ' ' || *result == '\t')
            result++;

        if (*result == '[' || *result == '\0')
            break;
        if (*result != '\n' && *result != '\r' && *result != '\t' && *result != '#')
            size++;
    }
    return size;
}