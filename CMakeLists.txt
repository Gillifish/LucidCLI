cmake_minimum_required(VERSION 3.16)
project(LucidCLI LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(LucidCLI src/main.cpp
                        src/Control.cpp
                        src/LucidDB.cpp)

if(WIN32)
    add_custom_command(
        TARGET LucidCLI
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

