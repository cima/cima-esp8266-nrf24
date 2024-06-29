set(srcs
)

idf_component_register(SRCS "Nrf24ControlMain.cpp" "${srcs}"
                    REQUIRES freertos spiffs nvs_flash json pthread
) 

enable_language(CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

component_compile_definitions(CORE_DEBUG_LEVEL=4)

# Boost
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

# spiffs_create_partition_image(storage ../filesystem FLASH_IN_PROJECT)
