cmake_minimum_required(VERSION 3.20)

set(AZURE_SDK_C_PATH $ENV{AZURE_SDK_C_PATH})

set(CMAKE_SYSTEM_NAME Generic)

# ESP8266 imports
# ------------- 
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_C_FLAGS -mlongcalls ${CMAKE_C_FLAGS})
set(CMAKE_CXX_FLAGS -mlongcalls ${CMAKE_CXX_FLAGS})
#set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-mlongcalls")
#string(REPLACE "-nostdlib" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
#set(CMAKE_EXE_LINKER_FLAGS "-lstdc++ -static-libstdc++ --disable-shared" ${CMAKE_EXE_LINKER_FLAGS})

cmake_policy(SET CMP0074 NEW)
find_package(Boost)


# Main code
# ---------

project(CIMA-ESP8266-NRF24)
