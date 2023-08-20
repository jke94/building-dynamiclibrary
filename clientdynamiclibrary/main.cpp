#include <iostream>
#include <windows.h>

#include "OperationsApi.h"
#include "ObserverApi.h"

// Functions definition.
typedef int     (*ADD_INT_NUMBERS)(int, int);
typedef double  (*ADD_DOUBLE_NUMBERS)(double, double);
typedef int     (*SUBTRACT_INT_NUMBERS)(int, int);
typedef double  (*SUBTRACT_DOUBLE_NUMBERS)(double, double);
typedef int     (*MULTIPLY_INT_NUMBERS)(int, int);
typedef double  (*MULTIPLY_DOUBLE_NUMBERS)(double, double);
typedef int     (*DIVIDE_INT_NUMBERS)(int, int);
typedef double  (*DIVIDE_DOUBLE_NUMBERS)(double, double);

int main()
{
    HINSTANCE hinstDLL = LoadLibrary(L"dynamiclibrary.dll");
    BOOL fFreeDLL = false;

    if (hinstDLL == NULL)
    {
        std::cout << "Impossible load library 'dynamiclibrary.dll'" << std::endl;

        return -1;
    }

    ADD_INT_NUMBERS add_int_numbers = (ADD_INT_NUMBERS)GetProcAddress(hinstDLL, "AddIntNumbers");
    ADD_DOUBLE_NUMBERS add_double_numbers = (ADD_DOUBLE_NUMBERS)GetProcAddress(hinstDLL, "AddDoubleNumbers");

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

    int resultA = add_int_numbers(3, 64);
    double resultB = add_double_numbers(7.6, 8.6);

    std::cout << "ResultA: " << resultA << std::endl;
    std::cout << "resultB: " << resultB << std::endl;

    fFreeDLL = FreeLibrary(hinstDLL);

    std::cout << "Free dll library operation result: " << fFreeDLL << std::endl;

    return 0;

    // Code refactor to use loading DLL library.
    
    // Consuming dynamic library: Using OperationsApi classes.

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