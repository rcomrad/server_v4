# REQUIERS:
#   TARGET - name of target for sources inclusion

macro(collect_src)
    file(GLOB_RECURSE
        project_sources
        ${CMAKE_CURRENT_LIST_DIR}/*.cpp
        ${CMAKE_CURRENT_LIST_DIR}/*.hpp
    )

    target_include_directories(${EXE_NAME} PUBLIC "sources/")
    target_sources(${TARGET} PRIVATE ${project_sources})
endmacro()

macro(get_subdirectory_list RESULT_VAR DIR)
    file(GLOB OBJ_LIST LIST_DIRECTORIES true ${DIR}/*)

    set(RESULT "")
    foreach(OBJ ${OBJ_LIST})
        if(IS_DIRECTORY ${curdir}/${OBJ})
            list(APPEND RESULT ${OBJ})
        endif()
    endforeach()

    set(${RESULT_VAR} ${RESULT})
endmacro()
