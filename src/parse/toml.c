#include "lo_utils/parse.h"
#include <string.h>
#include <stdio.h>

typedef enum{
    TOML_STRING_T,
    TOML_NUMBER_T,
    TOML_BOOLEAN_T,
    TOML_NULL_T,
} tomlType;

typedef struct{
    const char* startChar;
    int length;
} tomlToken;

typedef struct{
    tomlToken table;
    tomlToken valName;
    tomlType  valType;
    tomlToken valContent;
} tomlValue;

int LEGACY_getTomlTableCount(const char* content){
    int result = 0;
    const char* tempPoint = content;

    while (1){
        // Attempt to find the '[' symbol
        tempPoint = strchr(tempPoint, '[');
        if (tempPoint == NULL)
            break;

        // Check if its the beginning of the file
        if (tempPoint == content){
            result++;
            tempPoint++;
            continue;
        }
        // Check symbol before '['
        const char* prevChar = tempPoint - 1;
        while (prevChar >= content && (*prevChar == ' ' || *prevChar == '\t'))
            prevChar--;
        // Check if its '\n'
        if (prevChar < content || *prevChar == '\n') {
            result++;
        }

        tempPoint++;
    }

    return result;
}

size_t getTableCount_toml(const char* content){
    return 6l;
}

void parseToml(const char* content){

}