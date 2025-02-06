macro(flag_setup)
    if (${MSVC})
        set(OS "BILL_WINDOWS")
    else()
        set(OS "LINUS_LINUX")
    endif()
endmacro()

macro(os_flag TARGET)
    if     (${OS} MATCHES "LINUS_LINUX")
        target_compile_definitions(${EXE_NAME} PRIVATE
            LINUS_LINUX
        )
    elseif (${OS} MATCHES "BILL_WINDOWS")
        target_compile_definitions(${EXE_NAME} PRIVATE
            BILL_WINDOWS
            _WIN32_WINNT=0x0601
        )
    endif()
endmacro()
