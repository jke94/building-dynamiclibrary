#include <iostream>
#include "OperationsApi.h"

int main()
{
    std::cout << "Hello World!\n";

    std::cout << OperationsApi::suma(2.4, 3.6) << std::endl;
    std::cout << OperationsApi::resta(2.4, 3.6) << std::endl;
    std::cout << OperationsApi::multiplicar(2.4, 3.6) << std::endl;
    std::cout << OperationsApi::dividir(2.4, 3.6) << std::endl;
}