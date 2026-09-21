cmake_minimum_required(VERSION 4.1)
project(LolohUtilsPack C CXX)

set(CMAKE_C_STANDARD  11)
set(CMAKE_C_STANDARD_REQUIRED  ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# === My Lib Components ===
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# === C Part ===
add_library(LolohUtilsPack
        "${SRC_DIR}/c11/dynamic_libs/reg_logic.c"
        "${SRC_DIR}/c11/math/math.c"
        "${SRC_DIR}/c11/math/rand.c"
        "${SRC_DIR}/c11/term/base_funcs.c"
        "${SRC_DIR}/c11/term/setup_env.c"
)

target_include_directories(LolohUtilsPack
        PRIVATE "${SRC_DIR}/c11"
        PUBLIC "${INCLUDE_DIR}"
)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(LolohUtilsPack PUBLIC LOUTILS_SHARED)
    target_compile_definitions(LolohUtilsPack PRIVATE LOUTILS_EXPORTS)
endif()


# === CXX Part ===
add_library(LolohUtilsPack_cxx
        "${SRC_DIR}/cxx20/parse/split.cpp"
)

target_link_libraries(LolohUtilsPack_cxx PUBLIC LolohUtilsPack)

target_include_directories(LolohUtilsPack_cxx
        PRIVATE "${SRC_DIR}/cxx20"
        PUBLIC "${INCLUDE_DIR}"
)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(LolohUtilsPack_cxx PUBLIC LOUTILS_CXX_SHARED)
    target_compile_definitions(LolohUtilsPack_cxx PRIVATE LOUTILS_CXX_EXPORTS)
endif()


# === Example ===
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(app_example example/main.cpp)
    target_link_libraries(app_example PRIVATE LolohUtilsPack_cxx)

    if(BUILD_SHARED_LIBS AND WIN32)
        add_custom_command(TARGET app_example POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:LolohUtilsPack>
                $<TARGET_FILE:LolohUtilsPack_cxx>
                $<TARGET_FILE_DIR:app_example>
        )
    endif()
endif()