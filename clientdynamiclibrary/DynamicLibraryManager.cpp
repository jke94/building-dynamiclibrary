#include "DynamicLibraryManager.h"

DynamicLibraryManager::DynamicLibraryManager(
    LPCWSTR dynamic_library_name)
{
	_dynamic_library_name = dynamic_library_name;
}

DynamicLibraryManager::~DynamicLibraryManager()
{
    if (_handle_dll != NULL)
    {
        BOOL fFreeDLL = FreeLibrary(_handle_dll);

        std::wcout << "Free dll library '" << _dynamic_library_name <<
            "' operation result : " << fFreeDLL << std::endl;

        _handle_dll = NULL;
    }
}

HINSTANCE DynamicLibraryManager::load_library()
{
    if (_dynamic_library_name == NULL)
    {
        return NULL;
    }

    if (_handle_dll != NULL)
    {
        return _handle_dll;
    }

    _handle_dll = LoadLibrary(_dynamic_library_name);

    if (_handle_dll == NULL)
    {
        std::wcout << "Impossible load library '"<< _dynamic_library_name << "'" << std::endl;

        return NULL;
    }
    std::wcout << "Loaded library '" << _dynamic_library_name << "'" << std::endl;

	return _handle_dll;
}

HINSTANCE DynamicLibraryManager::get_dll_handle()
{
    return _handle_dll;
}

LPCWSTR DynamicLibraryManager::get_dynamic_library_name()
{
    if (_dynamic_library_name == NULL)
    {
        return NULL;
    }

    return _dynamic_library_name;
}

ADD_INT_NUMBERS DynamicLibraryManager::get_add_int_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (ADD_INT_NUMBERS)GetProcAddress(_handle_dll, "AddIntNumbers");
}

ADD_DOUBLE_NUMBERS DynamicLibraryManager::get_add_double_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (ADD_DOUBLE_NUMBERS)GetProcAddress(_handle_dll, "AddDoubleNumbers");
}

SUBTRACT_INT_NUMBERS DynamicLibraryManager::get_subtract_int_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (SUBTRACT_INT_NUMBERS)GetProcAddress(_handle_dll, "SubtractIntNumbers");
}

SUBTRACT_DOUBLE_NUMBERS DynamicLibraryManager::get_subtract_double_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (SUBTRACT_DOUBLE_NUMBERS)GetProcAddress(_handle_dll, "SubtractDoubleNumbers");
}

MULTIPLY_INT_NUMBERS DynamicLibraryManager::get_multiply_int_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (MULTIPLY_INT_NUMBERS)GetProcAddress(_handle_dll, "MultiplyIntNumbers");
}

MULTIPLY_DOUBLE_NUMBERS DynamicLibraryManager::get_multiply_double_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (MULTIPLY_DOUBLE_NUMBERS)GetProcAddress(_handle_dll, "MultiplyDoubleNumbers");
}

DIVIDE_INT_NUMBERS DynamicLibraryManager::get_divide_int_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (DIVIDE_INT_NUMBERS)GetProcAddress(_handle_dll, "DivideIntNumbers");
}

DIVIDE_DOUBLE_NUMBERS DynamicLibraryManager::get_divide_double_numbers_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (DIVIDE_DOUBLE_NUMBERS)GetProcAddress(_handle_dll, "DivideDoubleNumbers");
}
