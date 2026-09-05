#include "lo_utils.h"

int main(int argc, char** argv){
    termSetupEnv();

    termMsg();
    // termMsg("Hello World !!", "MAIN_CXX", COLOR_WHITE);
    // termMsg("ERROR ERROR !!", "MAIN_CXX", COLOR_RED);
    // termMsg("INFOO INFOO !!", "MAIN_CXX", COLOR_BLUE);

    // int key_int = termGetKey();
    // termMsg(key_int, "MAIN_CXX");

    const char* tomlData = R"(
        [General]
    )";
    auto fieldSize= getTomlTableSize(tomlData, "General");
    termMsg(fieldSize);
    auto fakeFieldSize = getTomlTableSize(tomlData, "__+Fake");
    termMsg(fakeFieldSize);

    return 0;
}