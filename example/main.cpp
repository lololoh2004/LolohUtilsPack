#include "lo_utils.h"

int main(){
    termSetupEnv();

    termMsgC("Hello World !!\n", "MAIN_C", COLOR_WHITE);
    termMsgC("ERROR ERROR !!\n", "MAIN_C", COLOR_RED);
    termMsgC("INFOO INFOO !!\n", "MAIN_C", COLOR_BLUE);

    //int key_int = termGetKey();
    //printf("%d", key_int);
    return 0;
}