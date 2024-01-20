#--------------------------------------------------------------------------------

macro(get_sources SOURCE_LIST DIR)

    set(FOLDER_NAMES 

    base_module
    code 
    core 
    database 
    domain 
    get 
    module 
    multitool 
    post 
    process 
    router 
    server 
    string_data
    tester 
    tex_manager
    
    )

    add_sources(${SOURCE_LIST} "${DIR}/sources" "${FOLDER_NAMES}")
endmacro()

#--------------------------------------------------------------------------------
