#include <stdio.h>

// 팩토리얼 for문으로 구현
int Factorial1(int num)
{
	int result = 1;
	for (int i = 0; i < num; ++i)
	{
		//	result = result * (i + 1);
		result = result * (i + 1);
		// 0일때 1가 저장됨
		// 1일때 2가 저장됨
		// 2일때 3이 저장됨
	}
	return result;
}

// 팩토리얼 재귀함수로 구현
int Factorial2(int num)
{
	if (num == 1)
	{
		return 1;
	}
	return (num * Factorial2(num-1));
}

int Fibonacci(int num)
{
	int result = 0;
	int a = 1;
	int b = 1;

	if (num == 1 || num == 2)
	{
		return 1;
	}
	// else를 굳이 쓸 필요가 없음
	// if문이라는건 원하는 조건을 고르기 위해 쓰는것이기 때문에 그 조건에 부합하면 
	// else 없이 그냥 따로 아래서 새롭게 시작하는 for문을 쓰는게 더 간결하고 깔끔함.
	else
	{
		for (int i = 0; i < num - 2; ++i)
		{
			result = a + b;

			a = b;
			b = result;
			// i = 0 이면 result = 2
			// i = 1 이면 result = 2
			// i = 2 이면 result = 2
			// i = 3 이면 result = 2
		}
	}
	return result;
}


// 피보나치수열 재귀함수 버전
// // 1 1 2 3 5 8 13 ...
int Fibonacci2(int num)
{
	int result = 0;
	int a = 1;
	int b = 1;

	if (num == 1 || num == 2)
	{
		return 1;
	}

	return Fibonacci2(num-2) + Fibonacci2(num-1);
}


int main()
{
	// 팩토리얼을 for문으로 구현
//	int data = Factorial1(2);

	// 팩토리얼을 재귀함수로 구현
//	int data = Factorial2(5);
	int data2 = Fibonacci(7);


	return 0;
}