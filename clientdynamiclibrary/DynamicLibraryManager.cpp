#include "DynamicLibraryManager.h"

#ifdef __linux__

DynamicLibraryManager::DynamicLibraryManager(const char *filename)
{
    _dynamic_library_name = filename;
}

void* DynamicLibraryManager::load_library()
{
    if (_dynamic_library_name == nullptr)
    {
        return NULL;
    }

    if (!_handle_dll)
    {
        return _handle_dll;
    }

    _handle_dll = dlopen(_dynamic_library_name, RTLD_LAZY);

    if (!_handle_dll)
    {
        std::cout << "Could not open the library '"<< _handle_dll <<"'" << std::endl;

        return nullptr;
    }

    std::cout << "Loaded library '" << _dynamic_library_name << "'" << std::endl;

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

    if (_handle_dll)
    {
        int fFreeDLL = dlclose(_handle_dll);

        std::wcout << "Free so library '" << _dynamic_library_name <<
            "' operation result : " << fFreeDLL << std::endl;

        _handle_dll = NULL;
}

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

OPERATION DynamicLibraryManager::create_opearation()
{
    if (_handle_dll == NULL)
    {
        throw std::logic_error("'_handle_dll' is empty. Call 'load_library' function and check output.");
    }

#ifdef __linux__ 

    OPERATION operation = reinterpret_cast<OPERATION>(dlsym(_handle_dll, "CreateOperation"));

#elif _WIN32

    OPERATION operation = reinterpret_cast<OPERATION>(GetProcAddress(_handle_dll, "CreateOperation"));

#endif

    return operation;
}

// SUBJECT DynamicLibraryManager::get_create_subject_function()
// {
//     if (_handle_dll == NULL)
//     {
//         return NULL;
//     }

//     return (SUBJECT)GetProcAddress(_handle_dll, "Create_subject");
// }

// OBSERVER DynamicLibraryManager::get_create_observer_function()
// {
//     if (_handle_dll == NULL)
//     {
//         return NULL;
//     }

//     return (OBSERVER)GetProcAddress(_handle_dll, "Create_observer");
// }

// CREATE_MESSAGE DynamicLibraryManager::get_create_message_function()
// {
//     if (_handle_dll == NULL)
//     {
//         return NULL;
//     }

//     return (CREATE_MESSAGE)GetProcAddress(_handle_dll, "Create_message");
// }

// REMOVEME_FROM_THE_LIST DynamicLibraryManager::get_removeme_from_the_list_function()
// {
//     if (_handle_dll == NULL)
//     {
//         return NULL;
//     }

//     return (REMOVEME_FROM_THE_LIST)GetProcAddress(_handle_dll, "Removeme_from_the_list");
// }
