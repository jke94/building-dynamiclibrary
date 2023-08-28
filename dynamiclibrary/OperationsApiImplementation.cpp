#include "pch.h"

#ifdef DYNAMICLIBRARY_EXPORTS

#ifdef __linux__ 

    #define DYNAMICLIBRARY_API

#elif _WIN32

    #define DYNAMICLIBRARY_API __declspec(dllexport)

    #else

    #define DYNAMICLIBRARY_API __declspec(dllimport)

#endif

#else

#endif

extern "C" DYNAMICLIBRARY_API IOperation* CreateOperation()
{
    return new OperationsApi::Operation();
}
