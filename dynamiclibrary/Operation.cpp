#include "pch.h"

namespace OperationsApi
{
	Operation::Operation()
	{
	}
	Operation::~Operation()
	{
	}

	int Operation::AddNumbers(int a, int b)
	{
		return a + b;
	}
	double Operation::AddNumbers(double a, double b)
	{
		return a + b;
	}
	int Operation::SubtractNumbers(int a, int b)
	{
		return a - b;
	}
	double Operation::SubtractNumbers(double a, double b)
	{
		return a - b;
	}
	int Operation::MultiplyNumbers(int a, int b)
	{
		return a * b;
	}
	double Operation::MultiplyNumbers(double a, double b)
	{
		return a * b;
	}
	double Operation::DivideNumbers(int a, int b)
	{
		return a / b;
	}
	double Operation::DivideNumbers(double a, double b)
	{
		return a / b;
	}
}