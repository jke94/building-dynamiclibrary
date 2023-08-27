#pragma once

#include <iostream>
#include "LibrayTypeDefinitions.h"

#ifdef _WIN32

    #include <windows.h>

#elif __linux__
    
    #include <dlfcn.h>
    
#elif __APPLE__
    // Mac OS
#endif

class DynamicLibraryManager
{

#ifdef __linux__ 
    
    private:

        void* _handle_dll;
        char* _dynamic_library_name;

    public:
        DynamicLibraryManager(const char *filename);
        void* load_library();
         
#elif _WIN32

    private:

        LPCWSTR _dynamic_library_name = {};
        HINSTANCE _handle_dll;

    public:

        DynamicLibraryManager(LPCWSTR dynamic_library_name);
        HINSTANCE load_library();
        HINSTANCE get_dll_handle();
        LPCWSTR get_dynamic_library_name();
#endif

        ~DynamicLibraryManager();

        ADD_INT_NUMBERS get_add_int_numbers_function();
        ADD_DOUBLE_NUMBERS get_add_double_numbers_function();
        SUBTRACT_INT_NUMBERS get_subtract_int_numbers_function();
        SUBTRACT_DOUBLE_NUMBERS get_subtract_double_numbers_function();
        MULTIPLY_INT_NUMBERS get_multiply_int_numbers_function();
        MULTIPLY_DOUBLE_NUMBERS get_multiply_double_numbers_function();
        DIVIDE_INT_NUMBERS get_divide_int_numbers_function();
        DIVIDE_DOUBLE_NUMBERS get_divide_double_numbers_function();

        SUBJECT get_create_subject_function();
        OBSERVER get_create_observer_function();
        CREATE_MESSAGE get_create_message_function();
        REMOVEME_FROM_THE_LIST get_removeme_from_the_list_function();

    private:
};