include(glob.cmake)

#-------------------------------------------------------------------------------
# Set output extension and path
#-------------------------------------------------------------------------------

# PRODUSES:
#   TARGET

macro(set_output_folder)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
    set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY 
        ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
endmacro()

macro(set_output_folder_and_exe)
    set_output_folder()
    set_target_properties(${TARGET} PROPERTIES SUFFIX .exe)
endmacro()

#-------------------------------------------------------------------------------
# Create target
#-------------------------------------------------------------------------------

# REQUIERS:
#   TARGET_BASE_NAME - name of target for sources inclusion
#   IS_EXECUTABLE - 
#   IS_TESTS - 

# PRODUSES:
#   TARGET

macro(create_target)
    set(TARGET "${TARGET_BASE_NAME}") 
    if (${IS_TESTS}) # tests cannot be library
        set(TARGET "${TARGET}_test") # for tests we have '_test' postfix

        add_executable(${TARGET} "sources/_tester/main.cpp")

        # add test files to its target
        target_compile_definitions(${TARGET} PRIVATE TESTING)
        target_sources(${TARGET} PRIVATE ${project_sources}/_tests)
        set_output_folder_and_exe()
    else (${IS_EXECUTABLE})
        add_executable(${TARGET} "sources/main.cpp")
        set_output_folder_and_exe()
    else  ()
        add_library(${TARGET})
        set_output_folder()
    endif()
endmacro()

#-------------------------------------------------------------------------------

# REQUIERS:
#   DEPENDANTS - 
#   LIBRARIES - 
#   IS_EXECUTABLE - 
#   IS_TESTS - 

# INHERENTS? IS_EXECUTABLE

# PRODUSES:
#   TARGET_BASE_NAME
#   IS_TEST

macro(create_module)
    set(SOURCES_PATH ${CMAKE_CURRENT_LIST_DIR})
    set(TARGET_BASE_NAME ${CMAKE_CURRENT_LIST_DIR})
    
    foreach(IS_TEST [ TRUE, FALSE ])
        create_target(NAME TYPE IS_TEST)
        collect_src()
        
    endforeach()

    all_files = find_all_files(SOURCES_PATH)

    create_target(NAME false)
    if (SOURCES_PATH_tests exist ) create_target(NAME true)

    add_executable(${TEST_NAME} "sources_main/main.cpp")



macro(create_executable NAME PATH)
    target_include_directories(${EXE_NAME} PUBLIC $(SOURSEC))

endmacro()

macro(create_exe NAME SOURSEC)

endmacro()


macro(create_exe NAME SOURSEC)

endmacro()
