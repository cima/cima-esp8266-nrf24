
file(GLOB_RECURSE CPPs *.cpp)
file(GLOB_RECURSE Cs *.c)
file(GLOB_RECURSE ARC_Cs arch/*.c)

set(COMPONENT_SOURCES ${CPPs} ${Cs} ${ARC_Cs} ${COMPONENT_SOURCES})

# Boost
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(CMAKE_C_STANDARD_LIBRARIES -latomic -lstdc++ -lboost_system ${CMAKE_C_STANDARD_LIBRARIES})
set(CMAKE_CXX_STANDARD_LIBRARIES -latomic -lstdc++ -lboost_system ${CMAKE_CXX_STANDARD_LIBRARIES})

idf_component_register(
    SRCS ${COMPONENT_SOURCES}
    INCLUDE_DIRS ${COMPONENT_DIR}/include
    REQUIRES freertos log mbedtls lwip pthread newlib)
