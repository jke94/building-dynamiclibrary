// clientconsumingnuget.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OperationsApi.h"
#include "ObserverApi.h"

int main()
{
    std::cout << "Hello World!\n";

    // Consuming dynamic library: Using OperationsApi classes.

    std::cout << OperationsApi::Add::numbers(22.4, 3.6) << std::endl;
    std::cout << OperationsApi::Add::numbers(22, 3) << std::endl;

    std::cout << OperationsApi::Subtract::numbers(22.4, 3.6) << std::endl;
    std::cout << OperationsApi::Subtract::numbers(22, 3) << std::endl;

    std::cout << OperationsApi::Multiply::numbers(22.4, 3.6) << std::endl;
    std::cout << OperationsApi::Multiply::numbers(22, 3) << std::endl;

    std::cout << OperationsApi::Divide::numbers(22.4, 3.6) << std::endl;
    std::cout << OperationsApi::Divide::numbers(22, 3) << std::endl;

    // Consuming dynamic library: Using ObserverApi classes.

    ObserverApi::Subject* subject = new ObserverApi::Subject;

    ObserverApi::Observer* observer1 = new ObserverApi::Observer(1, *subject);
    ObserverApi::Observer* observer2 = new ObserverApi::Observer(2, *subject);
    ObserverApi::Observer* observer3 = new ObserverApi::Observer(3, *subject);
    ObserverApi::Observer* observer4;
    ObserverApi::Observer* observer5;

    subject->CreateMessage("Hello World! :D");
    observer3->RemoveMeFromTheList();

    subject->CreateMessage("The weather is hot today! :p");
    observer4 = new ObserverApi::Observer(4, *subject);

    observer2->RemoveMeFromTheList();
    observer5 = new ObserverApi::Observer(5, *subject);

    subject->CreateMessage("My new car is great! ;)");
    observer5->RemoveMeFromTheList();

    observer4->RemoveMeFromTheList();
    observer1->RemoveMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
    delete subject;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
