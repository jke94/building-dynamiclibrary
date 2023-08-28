#include "pch.h"

#ifdef __linux__ 

    extern "C"
    {
        int AddIntNumbers(int a, int b)
        {
            OperationsApi::Add add;

            return add.numbers(a, b);
        }
    }

#elif _WIN32

int DYNAMICLIBRARY_API AddIntNumbers(int a, int b)
{
    OperationsApi::Add add;

    return add.numbers(a, b);
}

double DYNAMICLIBRARY_API AddDoubleNumbers(double a, double b)
{
    OperationsApi::Add add;

    return add.numbers(a, b);
}

int DYNAMICLIBRARY_API SubtractIntNumbers(int a, int b)
{
    OperationsApi::Subtract subtract;

    return subtract.numbers(a, b);
}

double DYNAMICLIBRARY_API SubtractDoubleNumbers(double a, double b)
{
    OperationsApi::Subtract subtract;

    return subtract.numbers(a, b);
}

int DYNAMICLIBRARY_API MultiplyIntNumbers(int a, int b)
{
    OperationsApi::Multiply multiply;

    return multiply.numbers(a, b);
}

double DYNAMICLIBRARY_API MultiplyDoubleNumbers(double a, double b)
{
    OperationsApi::Multiply multiply;

    return multiply.numbers(a, b);
}

int DYNAMICLIBRARY_API DivideIntNumbers(int a, int b)
{
    OperationsApi::Divide divide;

    return divide.numbers(a, b);
}

double DYNAMICLIBRARY_API DivideDoubleNumbers(double a, double b)
{
    OperationsApi::Divide divide;

    return divide.numbers(a, b);
}

#endif