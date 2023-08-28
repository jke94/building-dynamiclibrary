#pragma once

class IOperation
{
	public:
		virtual int AddNumbers(int a, int b) = 0;
		virtual double AddNumbers(double a, double b) = 0;
		virtual int SubtractNumbers(int a, int b) = 0;
		virtual double SubtractNumbers(double a, double b) = 0;
		virtual int MultiplyNumbers(int a, int b) = 0;
		virtual double MultiplyNumbers(double a, double b) = 0;
		virtual double DivideNumbers(int a, int b) = 0;
		virtual double DivideNumbers(double a, double b) = 0;

	private:

};