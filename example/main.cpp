#include "lo_utils.h"
#include "lo_utils/cxx_wrap/term.hpp"

int main(int argc, char** argv){
    termSetupEnv();

    term::msg();
    term::msg("Hello World !!", "MAIN_CXX", COLOR_WHITE);
    term::msg("ERROR ERROR !!", "MAIN_CXX", COLOR_RED);
    term::msg("INFOO INFOO !!", "MAIN_CXX", COLOR_BLUE);

    int key_int = termGetKey();
    term::msg(key_int, "MAIN_CXX");


    return 0;
}