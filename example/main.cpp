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
[Graphics]
width = 1920                # COMMENT
fullscreen = true
adapter = "NVIDIA GTX 4060"
# COMMENT

[User.Profile]
name = "Ivan"
roles = ["admin", "user", "guest"]
    [Space_before_table]

    )";
    auto var = getTableCount_toml(tomlData);
    termMsg(var);

    return 0;
}