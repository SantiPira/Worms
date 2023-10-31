cmake_minimum_required(VERSION 3.10.2)
project(worms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")

add_subdirectory(SDL2pp)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

file(GLOB_RECURSE COMMON_SRCS ./common_libs/src/*.cpp)
add_library(libcommon STATIC ${COMMON_SRCS})

include_directories(${CMAKE_SOURCE_DIR}/client/include)
include_directories(${CMAKE_SOURCE_DIR}/server/include)
include_directories(${CMAKE_SOURCE_DIR}/common_libs/include)

target_link_libraries(libcommon SDL2pp Qt5::Widgets)

file(GLOB_RECURSE SERVER_SRCS ./server/src/*.cpp)
list(FILTER SERVER_SRCS EXCLUDE REGEX "main.cpp")

add_library(libserver STATIC ${SERVER_SRCS})
target_link_libraries(libserver libcommon)

file(GLOB_RECURSE CLIENT_SRCS ./client/src/*.cpp)
list(FILTER CLIENT_SRCS EXCLUDE REGEX "main.cpp")

add_library(libclient STATIC ${CLIENT_SRCS})
target_link_libraries(libclient libcommon)

add_executable(worms-client "client/src/main.cpp")
target_link_libraries(worms-client libclient)

add_executable(worms-server "server/src/main.cpp")
target_link_libraries(worms-server libserver)

install(TARGETS worms-server worms-client libclient libserver libcommon
        ARCHIVE DESTINATION "lib"
        RUNTIME DESTINATION "bin"
        INCLUDES DESTINATION "include")
