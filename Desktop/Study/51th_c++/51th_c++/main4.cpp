#include <iostream>

// 함수가 호출되면 사용하는 메모리 영역
// 스택 메모리 영역

// 재귀 함수
// 함수가 호출되고, 자기 자신을 다시 호출하는 구조의 함수
// 종료 조건이 없으면 무한 반복호출로 인한 스택 오버플로우가 발생한다.

// 간단(간결)하게 문제 해결이 가능한 경우(ex 계층구조[트리] 형태 순회)

// 재귀함수의 장점
// 1. 코드가 간결해지고, 코드의 직관성이 더 높다.

// 재귀함수의 단점
// 1. 느리다.


// 계속 재호출 하기 때문에 무한루프가 돔
void Recursivefuunction()
{
	Recursivefuunction();
}

// 팩토리얼, 피보나치 수열
// 5! = 5 * 4 * 3 * 2 * 1;




int Factorial(int _Num)
{
	int Result = 1;

	for (int i = 0; i < _Num; ++i)
	{
		Result *= i + 1;
	}
	return Result;
}

// 팩토리얼 재귀버전
int Factorial2(int _Num)
{
	// 10! == 10 * 9!;
	// 9! == 9 * 8!;
	// _Num! = _Num * ( _Num - 1 )!
	if (1 == _Num)
	{
		return 1;
	}
	else
	{
		// 숫자를 쌓아서 누적시키고 1이 들어오면 역으로 곱하면서 선입 후출식으로 계산해서 출력함
		return _Num * Factorial2(_Num - 1);
	}
}


// 피보나치 수열
// 1 1 2 3 5 8 13 21 ...
int Fibonacci(int _Num)
{
	if (1 == _Num || 2 == _Num)
	{
		return 1;
	}

	// 3항 이상인 경우 처음 두항(1, 1) 부터 누적해서 해당 항을 구해준다.

	int iResult = 0;

	int Prev1 = 1;
	int Prev2 = 1;

	for (int i = 0; i < _Num - 2; ++i)
	{
		iResult = Prev1 + Prev2;

		Prev1 = Prev2;
		Prev2 = iResult;
	}
	return iResult;
}

// 피보나치 재귀함수 버전

int Fibonacci_Re(int _Num)
{
	if (1 == _Num || 2 == _Num)
	{
		return 1;
	}

	return Fibonacci_Re(_Num - 1) + Fibonacci_Re(_Num - 2);
}




// ctrl 누른채로 k, f 누르면 됨 (드래그하고)

// 스택 방식 main -> A호출 -> B호출 -> C호출 -> C종료 -> B종료 -> A종료 -> main종료
// 함수가 너무 많이 쌓이면 스택 영역안에 있는 함량을 초과하면서 스택 over flow가 발생함
void CFunc()
{

}

void BFunc()
{
	CFunc();
}


void AFunc()
{
	BFunc();
}

int main() 
{
	// 호출스택으로 확인
	AFunc();

	// 무한루프 확인
	Recursivefuunction();

	int i = Factorial(3);

	int j = Factorial2(3);

	int iReturn = 0;
	iReturn = Fibonacci(1);
	iReturn = Fibonacci(2);
	iReturn = Fibonacci(3);
	iReturn = Fibonacci(4);

	// 재귀함수방식으로 구현하면 높은 항을 구하려면 너무 많은 함수를 호출횟수가 발생한다.
	iReturn = Fibonacci(48);

	return 0;
}