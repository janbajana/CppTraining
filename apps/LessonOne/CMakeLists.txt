cmake_minimum_required(VERSION 3.10)

project(LessonOne VERSION 2.1.0 LANGUAGES C CXX)

# Add your application-specific source files here
add_executable( LessonOne
    "${CMAKE_CURRENT_LIST_DIR}/../common/Macros.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/TemplateClass.hpp"      
    "${CMAKE_CURRENT_LIST_DIR}/ClassOne.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/ClassOne.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp")

target_include_directories(LessonOne PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/../common")

# Define a decent level of warnings
target_compile_options(LessonOne PRIVATE
    # Clang / AppleClang / GCC
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall$<SEMICOLON>-Wextra>
    # MSVC
    $<$<CXX_COMPILER_ID:MSVC>:/W3>)

target_link_libraries(LessonOne PRIVATE 
    -pthread
)

target_compile_options(LessonOne PRIVATE ${TRAINING_WARNINGS})

install(TARGETS LessonOne DESTINATION ${CPP_TRAINGING_INSTALL_BIN_DIR})