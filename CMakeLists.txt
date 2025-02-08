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
# if(NOT EXISTS ${TARGET_SWITCH})
    get_subdirectory_list(SUBDIRS sources)

    file(WRITE ${TARGET_SWITCH} 
        "if(FALSE)\n"
    )

    foreach(DIR ${SUBDIRS})
        get_filename_component(DIR_NAME ${DIR} NAME) 
        file(APPEND ${TARGET_SWITCH} 
            "elseif (\$\{TASK\} MATCHES \"${DIR_NAME}\" OR \$\{TASK\} MATCHES \"all\")\n"
            "    include(${DIR}/_setup.cmake)\n"
        )
    endforeach()
    file(APPEND ${TARGET_SWITCH} 
        "endif()\n"
    )
# endif()
include(${CONFIG_FILE})

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(KusSysteam)
