cmake_minimum_required(VERSION 4.1)
project(LolohUtilsPack C CXX)

set(CMAKE_C_STANDARD  11)
set(CMAKE_C_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PRIVATE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")


# === My Lib Components ===

# Term Utils
add_library(utils_term SHARED
        src/term/base_funcs.c
        src/term/setup_env.c
)
target_include_directories(utils_term
        PRIVATE src
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(utils_term PUBLIC LOUTILS_SHARED)
target_compile_definitions(utils_term PRIVATE LOUTILS_EXPORTS)

# DLib Utils
add_library(utils_dynlibs SHARED
        src/dynamic_libs/reg_logic.c
)
target_link_libraries(utils_dynlibs PRIVATE utils_term)
target_include_directories(utils_dynlibs
        PRIVATE src
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(utils_term PUBLIC LOUTILS_SHARED)
target_compile_definitions(utils_term PRIVATE LOUTILS_EXPORTS)

# Math Utils
add_library(utils_math SHARED
        src/math/math.c
        src/math/rand.c
)
target_include_directories(utils_math
        PRIVATE src
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_compile_definitions(utils_math PUBLIC LOUTILS_SHARED)
target_compile_definitions(utils_math PRIVATE LOUTILS_EXPORTS)

# Main Pack
add_library(LolohUtilsPack INTERFACE)

# Target Link
target_link_libraries(LolohUtilsPack INTERFACE
        utils_term
        utils_dynlibs
        utils_math
)


# === Example ===
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(app_example example/main.cpp
            include/lo_utils/cxx_wrap/term.hpp)
    target_link_libraries(app_example PRIVATE LolohUtilsPack)
endif()