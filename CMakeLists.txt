cmake_minimum_required(VERSION 3.21.3)

include(cmake/glob.cmake)

set(CONFIG_FILE cmake_config.cmake)
if(NOT EXISTS ${CONFIG_FILE})
    file(WRITE ${CONFIG_FILE} 
        "set(CMAKE_CURRENT_SOURCE_DIR ~/vcpkg)\n"
        "set(TASK all)\n"
    )
endif()
include(${CONFIG_FILE})

set(TARGET_SWITCH cmake_target_switch.cmake)
if(NOT EXISTS ${TARGET_SWITCH})
    get_subdirectory_list(SUBDIRS /sources)
    foreach(DIR ${SUBDIRS})
        file(APPEND ${TARGET_SWITCH} 
            "set(CMAKE_CURRENT_SOURCE_DIR ~/vcpkg)\n"
            "set(TASK all)\n"
        )
    endforeach()



endif()
include(${CONFIG_FILE})

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(KusSysteam)
