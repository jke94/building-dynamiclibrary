#pragma once

#include <string>

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
};

class IObserver
{
	public:

		virtual ~IObserver() {};
		virtual void Update(const std::string& message_from_subject) = 0;
};

class ISubject
{
	public:

		virtual ~ISubject() {};
		virtual void Attach(IObserver* observer) = 0;
		virtual void Detach(IObserver* observer) = 0;
		virtual void Notify() = 0;
};