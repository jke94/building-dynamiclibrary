#pragma once

#ifdef _WIN32

#include <windows.h>

#elif __linux__

#include <dlfcn.h>

#elif __APPLE__
	// Mac OS
#endif

#include <iostream>

class IDynamicLibraryManager
{
#ifdef __linux__ 

public:

	virtual void* load_library() = 0;
	virtual void* get_dll_handle() = 0;
	virtual const char* get_dynamic_library_name() = 0;

#elif _WIN32

public:

	virtual HINSTANCE load_library() = 0;
	virtual HINSTANCE get_dll_handle() = 0;
	virtual LPCWSTR get_dynamic_library_name() = 0;

#endif

	virtual ~IDynamicLibraryManager() {};

	virtual OPERATION create_opearation() = 0;

	virtual SUBJECT get_create_subject_function() = 0;
	virtual OBSERVER get_create_observer_function() = 0;
	virtual CREATE_MESSAGE get_create_message_function() = 0;
	virtual REMOVEME_FROM_THE_LIST get_removeme_from_the_list_function() = 0;

};