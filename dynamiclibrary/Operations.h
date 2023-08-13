#pragma once

#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

extern "C" DYNAMICLIBRARY_API double suma(double a, double b);

extern "C" DYNAMICLIBRARY_API double resta(double a, double b);

extern "C" DYNAMICLIBRARY_API double multiplicar(double a, double b);

extern "C" DYNAMICLIBRARY_API double dividir(double a, double b);