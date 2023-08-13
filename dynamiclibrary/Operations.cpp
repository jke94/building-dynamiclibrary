#include "pch.h"

extern "C" DYNAMICLIBRARY_API double suma(double a, double b) {
	return a + b;
}

extern "C" DYNAMICLIBRARY_API double resta(double a, double b) {
	return a - b;
}

extern "C" DYNAMICLIBRARY_API double multiplicar(double a, double b) {
	return a * b;
}

extern "C" DYNAMICLIBRARY_API double dividir(double a, double b) {
	return a / b;
}