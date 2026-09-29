#include <stdio.h>
#include "lo_utils/c11/term/term_out.h"
#include "lo_utils/common/presets.h"


void termMsgChar(const char* text, const char* entry){
    printf("[%s] : %s\n", entry, text);
}
void termMsgInt(int num, const char* entry){
    printf("[%s] : %d\n", entry, num);
}
void termMsgFloat(float num, const char* entry){
    printf("[%s] : %F\n", entry, num);
}
void termMsgPtr(float ptr, const char* entry){
    printf("[%s] : %f\n", entry, ptr);
}

void termSetTextClr(rgb term_color){
    printf("\033[38;2;%d;%d;%dm",
        term_color.r,
        term_color.g,
        term_color.b);
}
void termResetTextClr(void){
    termSetTextClr(COLOR_DEFLT);
}

void termWait(const char* text){
    printf("%s", text);
    while (getchar() != '\n');
}