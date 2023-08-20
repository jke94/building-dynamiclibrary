#pragma once

#ifdef DYNAMICLIBRARY_EXPORTS
	#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
	#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif
namespace OperationsApi
{
	class Add
	{
		public:

			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};

	class Subtract
	{
		public:
			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};

	class Multiply
	{
		public:
			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};

	class Divide
	{
		public:
			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};
}