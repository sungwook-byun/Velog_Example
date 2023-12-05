#include <stdio.h>
#include <iostream>

// 변수의 종류
// 1. 지역변수 - 특정 지역(함수) 안에 선언된 변수
// 2. 전역변수 - 전역변수, 정적변수(static), 외부변수(extern)

// 메모리 영역
// 1. 스택   -  함수, 지역변수
// 2. 데이터 -  전역변수	
// 3. 힙     -  동적 할당
// 4. ROM(Read Only Memory)    -  코드 및 초기화 데이터	


// 함수
// 반환 타입, 함수 이름, 입력 인자 타입

//int Add(int, int) // 
//{
//
//}

int Add2(int, int); //  전방 선언, Linking

int Add2(int a, int b) // 
{
//	int result = a + b;
//	return result;

	return a + b;
}

int Pow(int Num, int Exponent)
{
	int Result = 1;
	for (int i = 0; i < Exponent; ++i)
	{
		Result *= Num;
	}
	return Result;
}



// 진입점 함수
int main()
{
	// 변수
	// 자료형(Data Type)
	// 정수형, 실수형
	int a = 0; // 지역변수

	// 함수 호출
	int i = Add2(100, 200);

	i = Pow(2, 3);

	return 0;


}