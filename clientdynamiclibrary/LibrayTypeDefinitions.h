#pragma once
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

typedef ObserverApi::Subject* (*SUBJECT)();
typedef ObserverApi::Observer* (*OBSERVER)(int id, ObserverApi::Subject& subject);
typedef void (*CREATE_MESSAGE)(ObserverApi::Subject& subject, std::string message);
// TODO: RemoveMeFrom from the list.
// TODO: Investigate //observer5 = new ObserverApi::Observer(5, *subject);