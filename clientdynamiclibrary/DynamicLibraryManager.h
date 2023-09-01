#pragma once

#include <iostream>
#include "LibrayTypeDefinitions.h"
#include "IDynamicLibraryManager.h"

#ifdef _WIN32

    #include <windows.h>

#elif __linux__
    
    #include <dlfcn.h>
    
#elif __APPLE__
    // Mac OS
#endif

class DynamicLibraryManager : public IDynamicLibraryManager
{

#ifdef __linux__ 
    
    private:

        void* _handle_dll;
        const char* _dynamic_library_name;

    public:

        DynamicLibraryManager(const char *filename);
        void* load_library();
        void* get_dll_handle();
	    const char* get_dynamic_library_name();
         
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

        OPERATION create_opearation();

        SUBJECT get_create_subject_function();
        OBSERVER get_create_observer_function();
        CREATE_MESSAGE get_create_message_function();
        REMOVEME_FROM_THE_LIST get_removeme_from_the_list_function();
};