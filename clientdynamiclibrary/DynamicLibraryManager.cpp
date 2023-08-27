#include "DynamicLibraryManager.h"

#ifdef __linux__ 

DynamicLibraryManager::DynamicLibraryManager(const char *filename)
{
    _handle_dll = dlopen(filename, RTLD_LAZY);
}

void* load_library()
{
    if (!_handle_dll) 
    {
        std::cout << "Could not open the library '"<< _handle_dll <<"'" << std::endl;

        return nullptr;
    }

    return _handle_dll;
}

#elif _WIN32

DynamicLibraryManager::DynamicLibraryManager(
    LPCWSTR dynamic_library_name)
{
	_dynamic_library_name = dynamic_library_name;
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

#endif

DynamicLibraryManager::~DynamicLibraryManager()
{

#ifdef __linux__ 

    // TODO:

#elif _WIN32

    if (_handle_dll != NULL)
    {
        BOOL fFreeDLL = FreeLibrary(_handle_dll);

        std::wcout << "Free dll library '" << _dynamic_library_name <<
            "' operation result : " << fFreeDLL << std::endl;

        _handle_dll = NULL;
    }

#endif

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

SUBJECT DynamicLibraryManager::get_create_subject_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (SUBJECT)GetProcAddress(_handle_dll, "Create_subject");
}

OBSERVER DynamicLibraryManager::get_create_observer_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (OBSERVER)GetProcAddress(_handle_dll, "Create_observer");
}

CREATE_MESSAGE DynamicLibraryManager::get_create_message_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (CREATE_MESSAGE)GetProcAddress(_handle_dll, "Create_message");
}

REMOVEME_FROM_THE_LIST DynamicLibraryManager::get_removeme_from_the_list_function()
{
    if (_handle_dll == NULL)
    {
        return NULL;
    }

    return (REMOVEME_FROM_THE_LIST)GetProcAddress(_handle_dll, "Removeme_from_the_list");
}
