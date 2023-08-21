#include <iostream>
#include <windows.h>

//#include "ObserverApi.h"
#include "LibrayTypeDefinitions.h"
#include "DynamicLibraryManager.h"

// Functions definition.

int main()
{
    DynamicLibraryManager dynamic_library_manager(L"dynamiclibrary.dll");

    HINSTANCE dll_handle = dynamic_library_manager.load_library();

    if (dll_handle == NULL)
    {
        std::cout << "Impossible load library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    ADD_INT_NUMBERS add_int_numbers = dynamic_library_manager.get_add_int_numbers_function();
    ADD_DOUBLE_NUMBERS add_double_numbers = dynamic_library_manager.get_add_double_numbers_function();
    SUBTRACT_INT_NUMBERS subtract_int_numbers = dynamic_library_manager.get_subtract_int_numbers_function();
    MULTIPLY_DOUBLE_NUMBERS multiply_double_numbers = dynamic_library_manager.get_multiply_double_numbers_function();
    DIVIDE_INT_NUMBERS divide_int_numbers = dynamic_library_manager.get_divide_int_numbers_function();

    if (add_int_numbers == NULL)
    {
        std::cout << "Impossible load function 'AddIntNumbers' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    if (add_double_numbers == NULL)
    {
        std::cout << "Impossible load function 'AddDoubleNumbers' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    if (subtract_int_numbers == NULL)
    {
        std::cout << "Impossible load function 'SubtractIntNumbers' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    if (multiply_double_numbers == NULL)
    {
        std::cout << "Impossible load function 'MultiplyDoubleNumbers' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    if (divide_int_numbers == NULL)
    {
        std::cout << "Impossible load function 'DivideIntNumbers' in library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    int resultA = add_int_numbers(3, 64);
    double resultB = add_double_numbers(7.6, 8.6);
    int resultC = subtract_int_numbers(20, 13);
    double resultD = multiply_double_numbers(2.5, 3);
    int resultE = divide_int_numbers(32, 4);

    std::cout << "ResultA: " << resultA << std::endl;
    std::cout << "resultB: " << resultB << std::endl;
    std::cout << "ResultC: " << resultC << std::endl;
    std::cout << "resultD: " << resultD << std::endl;
    std::cout << "ResultE: " << resultE << std::endl;

    return 0;

     //Code refactor to use loading DLL library.
    
     //Consuming dynamic library: Using OperationsApi classes.

    //std::cout << OperationsApi::Add::numbers(22.4, 3.6) << std::endl;
    //std::cout << OperationsApi::Add::numbers(22, 3) << std::endl;

    //std::cout << OperationsApi::Subtract::numbers(22.4, 3.6) << std::endl;
    //std::cout << OperationsApi::Subtract::numbers(22, 3) << std::endl;

    //std::cout << OperationsApi::Multiply::numbers(22.4, 3.6) << std::endl;
    //std::cout << OperationsApi::Multiply::numbers(22, 3) << std::endl;

    //std::cout << OperationsApi::Divide::numbers(22.4, 3.6) << std::endl;
    //std::cout << OperationsApi::Divide::numbers(22, 3) << std::endl;

    //// Consuming dynamic library: Using ObserverApi classes.

    //ObserverApi::Subject *subject = new ObserverApi::Subject;

    //ObserverApi::Observer* observer1 = new ObserverApi::Observer(1, *subject);
    //ObserverApi::Observer* observer2 = new ObserverApi::Observer(2, *subject);
    //ObserverApi::Observer* observer3 = new ObserverApi::Observer(3, *subject);
    //ObserverApi::Observer* observer4;
    //ObserverApi::Observer* observer5;

    //subject->CreateMessage("Hello World! :D");
    //observer3->RemoveMeFromTheList();

    //subject->CreateMessage("The weather is hot today! :p");
    //observer4 = new ObserverApi::Observer(4, *subject);

    //observer2->RemoveMeFromTheList();
    //observer5 = new ObserverApi::Observer(5, *subject);

    //subject->CreateMessage("My new car is great! ;)");
    //observer5->RemoveMeFromTheList();

    //observer4->RemoveMeFromTheList();
    //observer1->RemoveMeFromTheList();

    //delete observer5;
    //delete observer4;
    //delete observer3;
    //delete observer2;
    //delete observer1;
    //delete subject;

    return 0;
}