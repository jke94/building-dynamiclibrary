#include "DynamicLibraryManager.h"

#ifdef __linux__

DynamicLibraryManager::DynamicLibraryManager(const char *filename)
{
    _dynamic_library_name = filename;
}

DynamicLibraryManager::~DynamicLibraryManager()
{
    if (_handle_dll)
    {
        int fFreeDLL = dlclose(_handle_dll);

        std::wcout << "[DynamicLibraryManager] Free so library '" << _dynamic_library_name <<
            "' operation result : " << fFreeDLL << std::endl;

        _handle_dll = NULL;
    }
}

void* DynamicLibraryManager::load_library()
{
    if (_dynamic_library_name == nullptr)
    {
        return NULL;
    }

    if (_handle_dll != NULL)
    {
        return _handle_dll;
    }

    _handle_dll = dlopen(_dynamic_library_name, RTLD_LAZY);

    if (!_handle_dll)
    {
        std::cout << "[DynamicLibraryManager] Could not open the library '"<< _handle_dll <<"'" << std::endl;

        return nullptr;
    }

    std::cout << "[DynamicLibraryManager] Loaded library '" << _dynamic_library_name << "'" << std::endl;

    return _handle_dll;
}

void* DynamicLibraryManager::get_dll_handle()
{
    return _handle_dll;
}

const char* DynamicLibraryManager::get_dynamic_library_name()
{
    if (_dynamic_library_name == NULL)
    {
        return NULL;
    }

    return _dynamic_library_name;
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
        std::wcout << "[DYNAMIC_LIBRARY_MANAGER] Impossible load library '"<< _dynamic_library_name << "'" << std::endl;

        return NULL;
    }
    std::wcout << "[DYNAMIC_LIBRARY_MANAGER] Loaded library '" << _dynamic_library_name << "'" << std::endl;

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

DynamicLibraryManager::~DynamicLibraryManager()
{

    if (_handle_dll != NULL)
    {
        BOOL fFreeDLL = FreeLibrary(_handle_dll);

        std::wcout << "[DYNAMIC_LIBRARY_MANAGER] Free dll library '" << _dynamic_library_name <<
            "' operation result : " << fFreeDLL << std::endl;

        _handle_dll = NULL;
    }
}

#endif

OPERATION DynamicLibraryManager::create_opearation()
{
    if (_handle_dll == NULL)
    {
        throw std::logic_error("[DYNAMIC_LIBRARY_MANAGER] '_handle_dll' is empty. Call 'load_library' function and check output.");
    }

#ifdef __linux__ 

    OPERATION operation = reinterpret_cast<OPERATION>(dlsym(_handle_dll, "CreateOperation"));

#elif _WIN32

    OPERATION operation = reinterpret_cast<OPERATION>(GetProcAddress(_handle_dll, "CreateOperation"));

#endif

    return operation;
}

 SUBJECT DynamicLibraryManager::get_create_subject_function()
 {
     if (_handle_dll == NULL)
     {
         throw std::logic_error("[DYNAMIC_LIBRARY_MANAGER] '_handle_dll' is empty. Call 'load_library' function and check output.");
     }

#ifdef __linux__ 

     SUBJECT subject = reinterpret_cast<SUBJECT>(dlsym(_handle_dll, "Create_subject"));

#elif _WIN32

     SUBJECT subject = reinterpret_cast<SUBJECT>(GetProcAddress(_handle_dll, "Create_subject"));

#endif

     return subject;
 }

 OBSERVER DynamicLibraryManager::get_create_observer_function()
 {
     if (_handle_dll == NULL)
     {
         throw std::logic_error("[DYNAMIC_LIBRARY_MANAGER] '_handle_dll' is empty. Call 'load_library' function and check output.");
     }

#ifdef __linux__ 

     OBSERVER observer = reinterpret_cast<OBSERVER>(dlsym(_handle_dll, "Create_observer"));

#elif _WIN32

     OBSERVER observer = reinterpret_cast<OBSERVER>(GetProcAddress(_handle_dll, "Create_observer"));

#endif

     return observer;
 }

 CREATE_MESSAGE DynamicLibraryManager::get_create_message_function()
 {
     if (_handle_dll == NULL)
     {
         throw std::logic_error("[DYNAMIC_LIBRARY_MANAGER] '_handle_dll' is empty. Call 'load_library' function and check output.");
     }

#ifdef __linux__ 

     CREATE_MESSAGE create_message = reinterpret_cast<CREATE_MESSAGE>(dlsym(_handle_dll, "Create_message"));

#elif _WIN32

     CREATE_MESSAGE create_message = reinterpret_cast<CREATE_MESSAGE>(GetProcAddress(_handle_dll, "Create_message"));

#endif

     return create_message;
 }

 REMOVEME_FROM_THE_LIST DynamicLibraryManager::get_removeme_from_the_list_function()
 {

     if (_handle_dll == NULL)
     {
         throw std::logic_error("[DYNAMIC_LIBRARY_MANAGER] '_handle_dll' is empty. Call 'load_library' function and check output.");
     }

#ifdef __linux__ 

     REMOVEME_FROM_THE_LIST remove_from_the_list = reinterpret_cast<REMOVEME_FROM_THE_LIST>(dlsym(_handle_dll, "Removeme_from_the_list"));

#elif _WIN32

     REMOVEME_FROM_THE_LIST remove_from_the_list = reinterpret_cast<REMOVEME_FROM_THE_LIST>(GetProcAddress(_handle_dll, "Removeme_from_the_list"));

#endif

     return remove_from_the_list;
 }
