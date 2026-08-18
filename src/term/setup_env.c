#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #include <io.h>
#else
    #include <unistd.h>
#endif

#include "term.h"


termColorType sysTermType = TERM_DOESNT_SUPPORT_COLOR;


/*====================
   VALIDATION HELPERS
  ====================*/

int checkHandle(void* val) {
#ifdef _WIN32
    if (!val || val == INVALID_HANDLE_VALUE) {
#else
    if (!val) {
#endif
        termMsg("Error in term setup (Invalid Handle)\n", "TERM");
        return 0;
    }
    return 1;
}

#ifdef _WIN32
int checkBool(BOOL result) {
    if (!result) {
        termMsg("Error in term setup (API Failed)\n", "TERM");
        return 0;
    }
    return 1;
}
#endif

/*=====================
   BASE SETUP FUNCTION
  =====================*/

void termSetupEnv(void){
    printf("[TERM] Enter terminal init..\n - Your term : ");

#ifdef _WIN32
    if (getenv("WT_SESSION") != NULL) {
        sysTermType = TERM_SUPPORT_RGB;
        printf("\033[1;32mWindows Terminal\033[0m\n");
        return;
    }

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!checkHandle(hOut)) return;

    DWORD dwMode = 0;
    if (!checkBool(GetConsoleMode(hOut, &dwMode))) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!checkBool(SetConsoleMode(hOut, dwMode))) return;

    printf("\033[1;32mWindows Legacy CMD\033[0m\n");
    sysTermType = TERM_SUPPORT_RGB;
    return;
#else
    const char* colorTermVar = getenv("COLORTERM");
    const char* termVar = getenv("TERM");

    if (colorTermVar){
        if (strcmp(colorTermVar, "truecolor") == 0 || strcmp(colorTermVar, "24bit") == 0) {
            printf("\033[1;32mLinux Term ( TrueColor RGB )\033[0m\n");
            sysTermType = TERM_SUPPORT_RGB;
            return;
        }
    }

    if (termVar && (strstr(termVar, "256color") != NULL || strcmp(termVar, "xterm") == 0)) {
        sysTermType = TERM_SUPPORT_RGB;
        printf("\033[1;32mLinux Terminal ( Modern xterm via RGB )\033[0m\n");
        return;
    }

    if (isatty(STDOUT_FILENO)) {
        sysTermType = TERM_SUPPORT_ANSI;
        printf("\033[1;32mLinux Terminal ( Basic ANSI Only )\033[0m\n");
        return;
    }

    sysTermType = TERM_DOESNT_SUPPORT_COLOR;
    printf("\033[1;31mShit without Color Support\033[0m\n");
    return;
#endif
    printf("I Dont Know\n");
}