#pragma once

#ifdef DYNAMICLIBRARY_EXPORTS
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

namespace OperationsApi
{
	class DYNAMICLIBRARY_API Add
	{
		public:

			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};

	class DYNAMICLIBRARY_API Subtract
	{
		public:
			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};

	class DYNAMICLIBRARY_API Multiply
	{
		public:
			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};

	class DYNAMICLIBRARY_API Divide
	{
		public:
			static int numbers(int a, int b);
			static double numbers(double a, double b);
	};
}