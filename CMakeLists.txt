cmake_minimum_required(VERSION 4.1)
project(LolohUtilsPack C CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}")

set(CMAKE_C_STANDARD  11)
set(CMAKE_C_STANDARD_REQUIRED  ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# === My Lib Components ===

# Terminal Utils
add_library(utils_term STATIC
        include/LoUtils/term.h
        include/LoUtils/common.h
        src/term/base_funcs.c
        src/term/additions.c
        src/term/setup_env.c
)
target_include_directories(utils_term PUBLIC
        src
        include
)
# DLib Utils
add_library(utils_dynlibs STATIC
        src/dynamic_libs/reg_logic.c
        include/LoUtils/dyn_libs.h
)
target_include_directories(utils_dynlibs PUBLIC
        src
        include
)


add_library(LolohUtilsPack INTERFACE)


# Target Link
target_link_libraries(LolohUtilsPack INTERFACE
        utils_term
        utils_dynlibs
)


# === Example ===
add_executable(app_example
        example/main.cpp)
target_link_libraries(app_example PRIVATE
        LolohUtilsPack
)