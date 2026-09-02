#include "lo_utils/term.h"
#include "lo_utils/common/types.h"
#include "lo_utils/common/presets.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

void termClear(modePriority mode){
    switch (mode){
    case TYPE_FULL:
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        break;
    case TYPE_OPTI:
    case TYPE_BALANCE:
        printf("\033[H\033[2J");
        break;
    }
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

void termMsgChar(const char* text, const char* entry){
    printf("[%s] : %s", entry, text);
}

void termWait(const char* text){
    printf("%s", text);
    while (getchar() != '\n');
}

int termGetKey(void){
#ifdef _WIN32
    int c = _getch();
    return (c == 0 || c == 224) ? _getch() + 256 : ((c == 13) ? 10 : c);
#else
    struct termios oldt, newt;
    tcgetattr(0, &oldt); newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &newt);

    unsigned char buf[4] = {0};
    int n = (int)read(0, buf, 3);

    tcsetattr(0, TCSANOW, &oldt);
    return (n == 3) ? buf[2] + 256 : buf[0];
#endif
}