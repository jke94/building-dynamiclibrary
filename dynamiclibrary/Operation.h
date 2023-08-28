#pragma once
#include "pch.h"

namespace OperationsApi
{
	class Operation : public IOperation
	{
		private:

		public:

			Operation();
			~Operation();

			int AddNumbers(int a, int b);
			double AddNumbers(double a, double b);
			int SubtractNumbers(int a, int b);
			double SubtractNumbers(double a, double b);
			int MultiplyNumbers(int a, int b);
			double MultiplyNumbers(double a, double b);
			double DivideNumbers(int a, int b);
			double DivideNumbers(double a, double b);
	};
}