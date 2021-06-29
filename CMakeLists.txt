cmake_minimum_required(VERSION 3.10)

project(CppTraining LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

option(CPPTRAINING_WARNINGS_AS_ERRORS          "If enabled, warnings are treated as errors." ON)
option(CPPTRAINING_ENABLE_TEST     "If enabled, unit tests are built." ON)

if(CPPTRAINING_ENABLE_TEST)
    enable_testing()
endif()

if(MSVC)
    # enable parallel builds
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /D_CRT_SECURE_NO_WARNINGS /D_USE_MATH_DEFINES /DNOMINMAX")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
endif()

if (NOT DEFINED TRAINING_WARNINGS)
    if (MSVC)
        set(TRAINING_WARNINGS "/W3")
    else()
        set(TRAINING_WARNINGS "-Wall$<SEMICOLON>-Wextra")
    endif()
endif()

if (CPPTRAINING_WARNINGS_AS_ERRORS)
    if (MSVC)
        set(TRAINING_WARNINGS "/WX$<SEMICOLON>${TRAINING_WARNINGS}")
    else()
        set(TRAINING_WARNINGS "-Werror$<SEMICOLON>${TRAINING_WARNINGS}")
    endif()
endif()

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# OS Specific flags
if(WIN32)
    set(TARGET_PLATFORM_WINDOWS ON)
elseif(APPLE)
    set(TARGET_PLATFORM_MAC ON)
elseif(UNIX AND NOT APPLE)
    set(TARGET_PLATFORM_LINUX ON)
else()
    message(FATAL_ERROR "ERROR: Could not detect a target platform.")
endif()

set(CPP_TRAINGING_INSTALL_INCLUDE_DIR ${CMAKE_BINARY_DIR}/include)
set(CPP_TRAINGING_INSTALL_BIN_DIR ${CMAKE_BINARY_DIR}/bin)
set(CPP_TRAINGING_INSTALL_LIB_DIR ${CMAKE_BINARY_DIR}/lib)

# add_subdirectory(modules)
add_subdirectory(apps)

if(CPPTRAINING_ENABLE_TEST)
    add_subdirectory(test)
endif()