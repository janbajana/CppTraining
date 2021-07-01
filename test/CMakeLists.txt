cmake_minimum_required(VERSION 3.10)

project(test VERSION 1.0.0 LANGUAGES C CXX)

# macros
macro(test_compile_options name)
    # Define a decent level of warnings
    target_compile_options(${name} PRIVATE
        # Clang / AppleClang / GCC
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall$<SEMICOLON>-Wextra>
        # MSVC
        $<$<CXX_COMPILER_ID:MSVC>:/W3>)

    add_test(
        NAME ${name}
        COMMAND ${name}
    )

    target_compile_options(${name} PRIVATE ${TRAINING_WARNINGS})
endmacro(test_compile_options)

macro(add_benchmark_test name source)
    add_executable(${name} "${source}")
    target_link_libraries(${name} PRIVATE benchmark::benchmark GTest::gtest -pthread)

    test_compile_options(${name})
endmacro(add_benchmark_test)

macro(add_gtest name source)
    add_executable(${name} "${source}")
    target_link_libraries(${name} PRIVATE GTest::gtest GTest::gtest_main -pthread)

    test_compile_options(${name})
endmacro(add_gtest)
# end macros

if (NOT GTest_DIR)
    set(GTest_DIR "${CMAKE_CURRENT_LIST_DIR}/../thirdparty/googletest/build/install/lib/cmake/GTest")
endif()

if (NOT benchmark_DIR)
    set(benchmark_DIR "${CMAKE_CURRENT_LIST_DIR}/../thirdparty/benchmark/build/install/lib/cmake/benchmark")
endif()

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

add_benchmark_test(stl_algorithms "${CMAKE_CURRENT_LIST_DIR}/Pluralsight/stl_algorithms.cpp")

add_gtest(going_native "${CMAKE_CURRENT_LIST_DIR}/YouTube/going_native.cpp")
add_gtest(back_to_the_basics "${CMAKE_CURRENT_LIST_DIR}/YouTube/back_to_the_basics.cpp")
