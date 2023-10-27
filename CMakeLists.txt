cmake_minimum_required(VERSION 3.10.2)
project(worms)

set (CMAKE_CXX_STANDARD 17)

set(SDL2PP_WITH_IMAGE ON)
set(SDL2PP_WITH_MIXER ON)
set(SDL2PP_WITH_TTF ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")

file(GLOB_RECURSE COMMON_SRCS ./common_libs/src/*.cpp)
file(GLOB_RECURSE CLIENT_SRCS ./client/src/*.cpp)
file(GLOB_RECURSE SERVER_SRCS ./server/src/*.cpp)
list(FILTER CLIENT_SRCS EXCLUDE REGEX "main.cpp")
list(FILTER SERVER_SRCS EXCLUDE REGEX "main.cpp")

add_subdirectory(SDL2pp)

add_library(libcommon STATIC ${COMMON_SRCS})
add_library(libserver STATIC ${SERVER_SRCS})
add_library(libclient STATIC ${CLIENT_SRCS})
target_link_libraries(libcommon SDL2pp)
TARGET_LINK_LIBRARIES(libserver libcommon)
target_link_libraries(libclient libcommon)

add_executable(worms-client "client/src/main.cpp")
TARGET_LINK_LIBRARIES(worms-client libclient)

add_executable(worms-server "server/src/main.cpp")
TARGET_LINK_LIBRARIES(worms-server libserver)

install(TARGETS worms-server worms-client libclient libserver libcommon
        ARCHIVE DESTINATION "lib"
        RUNTIME DESTINATION "bin"
        INCLUDES DESTINATION "include")
