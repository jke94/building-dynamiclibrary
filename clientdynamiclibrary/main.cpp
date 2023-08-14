#include <iostream>
#include "OperationsApi.h"
#include "ObserverApi.h"

int main()
{
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

    ObserverApi::Subject *subject = new ObserverApi::Subject;

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

    return 0;
}