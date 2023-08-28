#include <iostream>

#ifdef __linux__ 
    #include <dlfcn.h>
#elif _WIN32
    #include <windows.h>
#else

#endif

#include "LibrayTypeDefinitions.h"
#include "DynamicLibraryManager.h"

int main()
{

#ifdef __linux__ 

    DynamicLibraryManager dynamic_library_manager("libdynamiclibrary.so");
    void* dll_handle = dynamic_library_manager.load_library();

    if (dll_handle == NULL)
    {
        std::cout << "Impossible load library 'libdynamiclibrary.so'" << std::endl;

        return -1;
    }

#elif _WIN32

    DynamicLibraryManager dynamic_library_manager(L"dynamiclibrary.dll");

    HINSTANCE dll_handle = dynamic_library_manager.load_library();

    if (dll_handle == NULL)
    {
        std::cout << "Impossible load library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

#else

#endif

    OPERATION create_operation = dynamic_library_manager.create_opearation();

    if (create_operation == NULL)
    {
        std::cout << "Impossible load function 'CreateOperation' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    IOperation* operation = create_operation();

    int resultA = operation->AddNumbers(3, 64);
    double resultB = operation->AddNumbers(7.6, 8.6);
    int resultC = operation->SubtractNumbers(20, 13);
    double resultD = operation->MultiplyNumbers(2.5, 3.0);
    double resultE = operation->DivideNumbers(32, 4);

    std::cout << "ResultA: " << resultA << std::endl;
    std::cout << "resultB: " << resultB << std::endl;
    std::cout << "ResultC: " << resultC << std::endl;
    std::cout << "resultD: " << resultD << std::endl;
    std::cout << "ResultE: " << resultE << std::endl;

    //// Consuming dynamic library: Using ObserverApi classes.

    // SUBJECT create_subject = dynamic_library_manager.get_create_subject_function();
    // OBSERVER create_observer = dynamic_library_manager.get_create_observer_function();
    // CREATE_MESSAGE create_message = dynamic_library_manager.get_create_message_function();
    // REMOVEME_FROM_THE_LIST removeme_from_the_list = dynamic_library_manager.get_removeme_from_the_list_function();

    // ObserverApi::Subject* subject = create_subject();
   
    // ObserverApi::Observer* observer1 = create_observer(1, *subject);
    // ObserverApi::Observer* observer2 = create_observer(2, *subject);
    // ObserverApi::Observer* observer3 = create_observer(3, *subject);
    // ObserverApi::Observer* observer4 = nullptr;
    // ObserverApi::Observer* observer5 = nullptr;

    // create_message(*subject, "Hello World! :D");
    // create_message(*subject, "Hello World! :D again!!");

    // removeme_from_the_list(*observer3);

    // create_message(*subject, "The weather is hot today! :p");
    // observer4 = create_observer(4, *subject);
    
    // removeme_from_the_list(*observer2);
    // observer5 = create_observer(5, *subject);

    // create_message(*subject, "My new car is great! ;)");
    // removeme_from_the_list(*observer5);

    // removeme_from_the_list(*observer4);
    // removeme_from_the_list(*observer1);

    // delete observer5;
    // delete observer4;
    // delete observer3;
    // delete observer2;
    // delete observer1;
    // delete subject;

    return 0;
}