#pragma once

#include <iostream>
#include <windows.h>

#include "LibrayTypeDefinitions.h"

class DynamicLibraryManager
{
	public:

		DynamicLibraryManager(LPCWSTR dynamic_library_name);
		~DynamicLibraryManager();

		HINSTANCE load_library();
		HINSTANCE get_dll_handle();
		LPCWSTR get_dynamic_library_name();

		ADD_INT_NUMBERS get_add_int_numbers_function();
		ADD_DOUBLE_NUMBERS get_add_double_numbers_function();

	private:
		LPCWSTR _dynamic_library_name = {};
		HINSTANCE _handle_dll;
};