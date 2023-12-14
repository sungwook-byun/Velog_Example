#include <iostream>


int main()
{
	int num = 0;

	int* pNum = &num;

	*pNum = 100;

	
	float* pFloat = (float*) & num;
	int data = *pFloat;


	// 주소 연산
	// 주소의 최소 단위는 바이트
	// 주소값의 표현체계는 정수타입
	// 포인터 변수의 크기는 운영체제 플랫폼에 따라 최대 크기로 지정된다.
	// 32비트 기준 포인터변수 크기는 4바이트, 4GB 이상의 메모리 주소를 가질 수 없는 문제가 있다.
	// void 포인터는 가리키고 있는 주소값의 원형을 해석할 수 없기 때문에 접근 및  주소 이동이 불가능하다.

	{
		// 배열은 메모리가 연속적인 구조이다.
		// 배열의 이름은 배열의 시작 주소값이다.

		int iArr[10] = {};
		int* pInt = iArr;

		*pInt = 100;
		*(pInt + 1) = 200;   // pInt[1] = 200; 이랑 같은 표현임
		pInt[2] = 300;





	}




	return 0;
}