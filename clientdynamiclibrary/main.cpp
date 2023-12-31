
#ifdef __linux__ 
    
    #include <dlfcn.h>

#elif _WIN32

    #include <windows.h>

#else

#endif

#include <iostream>
#include <vector>
#include "LibrayTypeDefinitions.h"
#include "DynamicLibraryManager.h"

int main()
{

    IDynamicLibraryManager* dynamic_library_manager;

#ifdef __linux__ 

    const char *dynamicLibName = "libdynamiclibrary.so";
    dynamic_library_manager = new DynamicLibraryManager(dynamicLibName);

    std::cout << "[CLIENT][INFO] dll_handle: " << dynamic_library_manager->get_dynamic_library_name() << std::endl;

    void* dll_handle = dynamic_library_manager->load_library();

    std::cout << "[CLIENT][INFO] dll_handle: " << dll_handle << std::endl; 

    if (dll_handle == NULL)
    {
        std::cout << "Impossible load library 'libdynamiclibrary.so'" << std::endl;

        return -1;
    }

#elif _WIN32

    LPCWSTR dynamicLibName = L"dynamiclibrary.dll";
    dynamic_library_manager = new DynamicLibraryManager(dynamicLibName);

    HINSTANCE dll_handle = dynamic_library_manager->load_library();

    std::cout << "[CLIENT][INFO] dll_handle: " << dll_handle << std::endl;

    if (dll_handle == NULL)
    {
        std::cout << "Impossible load library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

#else

#endif

    //  ******************************************************************************
    //  EXAMPLE A: Calling to operation class that allows do basic maths operations.
    //  ******************************************************************************

    OPERATION create_operation = dynamic_library_manager->create_opearation();

    if (create_operation == NULL)
    {
        std::cout << "[CLIENT] Impossible load function 'CreateOperation' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    IOperation* operation = create_operation();

    int resultA = operation->AddNumbers(3, 64);
    double resultB = operation->AddNumbers(7.6, 8.6);
    int resultC = operation->SubtractNumbers(20, 13);
    double resultD = operation->MultiplyNumbers(2.5, 3.0);
    double resultE = operation->DivideNumbers(32, 4);

    std::cout << "[CLIENT] ResultA: " << resultA << std::endl;
    std::cout << "[CLIENT] resultB: " << resultB << std::endl;
    std::cout << "[CLIENT] ResultC: " << resultC << std::endl;
    std::cout << "[CLIENT] resultD: " << resultD << std::endl;
    std::cout << "[CLIENT] ResultE: " << resultE << std::endl;

    delete operation;

    //  ******************************************************************************
    //  EXAMPLE B: Consuming dynamic library that expose logic with observable pattern.
    //  ******************************************************************************

     SUBJECT create_subject = dynamic_library_manager->get_create_subject_function();
     OBSERVER create_observer = dynamic_library_manager->get_create_observer_function();
     CREATE_MESSAGE create_message = dynamic_library_manager->get_create_message_function();
     REMOVEME_FROM_THE_LIST removeme_from_the_list = dynamic_library_manager->get_removeme_from_the_list_function();

     ISubject* subject = create_subject();
   
     IObserver* observer1 = create_observer(1, *subject);
     IObserver* observer2 = create_observer(2, *subject);
     IObserver* observer3 = create_observer(3, *subject);
     IObserver* observer4 = nullptr;
     IObserver* observer5 = nullptr;

     const int n_observers = 8;
     std::vector<IObserver*> observers = {};

     create_message(*subject, "Hello World! :D");
     create_message(*subject, "Hello World! :D again!!");

     for (int i = 0; i < n_observers; i++)
     {
         observers.push_back(create_observer(i + n_observers, *subject));
     }

     removeme_from_the_list(*observer3);

     create_message(*subject, "The weather is hot today! :p");
     observer4 = create_observer(4, *subject);
    
     removeme_from_the_list(*observer2);
     observer5 = create_observer(5, *subject);

     create_message(*subject, "My new car is great! ;)");
     removeme_from_the_list(*observer5);

     removeme_from_the_list(*observer4);
     removeme_from_the_list(*observer1);

     for (int i = 0; i < n_observers; i++)
     {
         removeme_from_the_list(*observers.at(i));
     }

     // Delete pointers.

     delete observer5;
     delete observer4;
     delete observer3;
     delete observer2;
     delete observer1;

     for (int i = 0; i < n_observers; i++)
     {
         delete observers.at(i);
     }

     delete subject;
     delete dynamic_library_manager;

    return 0;
}