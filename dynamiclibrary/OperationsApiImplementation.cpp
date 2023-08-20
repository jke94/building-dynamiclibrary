#include "pch.h"

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