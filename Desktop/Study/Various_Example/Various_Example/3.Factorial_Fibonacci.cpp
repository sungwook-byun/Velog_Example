#include<stdio.h>

// 5! = 5 * 4 * 3 * 2 * 1
int Factorial(int Num)
{
	int result = 1;
	for (int i = 0; i < Num; ++i)
	{
		result = result * (i + 1);
	}
	return result;
}

// 5! = 5 * 4 * 3 * 2 * 1
int Factorial_recursive(int Num)
{
	if (Num == 1)
	{
		return 1;
	}

	return Num * Factorial_recursive(Num - 1);
}

// 1 1 2 3 5 8 13 21 ...
int Fibonacci(int Num)
{
	int First_Num = 1;
	int Last_Num = 1;
	int Result = 1;
	if (Num == 1 || Num == 2)
	{
		return 1;
	}
	for (int i = 0; i < Num - 2; ++i)
	{
		Result = First_Num + Last_Num;
		First_Num = Last_Num;
		Last_Num = Result;
	}
	return Result;
}

// 1 1 2 3 5 8 13 21 ...
int Fibonacci_recursive(int Num)
{
	if (Num == 1 || Num == 2)
	{
		return 1;
	}
	return Fibonacci_recursive(Num - 2) + Fibonacci_recursive(Num - 1);
}




int main()
{

	int data = 0;
	data = Factorial(5);
	printf("5!의 값은 : %d\n\n", data);

	data = Factorial_recursive(6);
	printf("6!의 값은 : %d\n\n", data);

	data = Fibonacci(70);
	printf("Fibonacci 8번째 값은 : %d\n\n", data);

	data = Fibonacci_recursive(40);
	printf("Fibonacci 9번째 값은 : %d\n\n", data);

	return 0;
}