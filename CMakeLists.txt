cmake_minimum_required(VERSION 3.10)

project(LDPCpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    src/algebra/matrix.cpp
    src/decoders/BitFlipDecoder
    src/decoders/MajorityDecoder
    src/utils/Channel.cpp
    src/utils/Context.cpp
    example/main.cpp
)

add_executable(LDPCpp ${SOURCES})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -O2")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)