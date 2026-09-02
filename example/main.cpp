#include "lo_utils.h"

int main(){
    termSetupEnv();

    // termSetTextClr(COLOR_WHITE);
    termMsg();
    termMsg("Hello World !!", "MAIN_C", COLOR_WHITE);
    termMsg("ERROR ERROR !!", "MAIN_C", COLOR_RED);
    termMsg("INFOO INFOO !!", "MAIN_C", COLOR_BLUE);

    //int key_int = termGetKey();
    //printf("%d", key_int);
    return 0;
}