#include<stdio.h>	


int main()
{
	// volatile을 쓰지 않으면 cpu가 이미 cint값을 상수로 취급한다는 시점에서
	// 바뀌지 않을 것을 알기때문에 포인터주소로 접근해서 값을 변경했어도
	// 확인 절차를 거지치 않고 상수값으로 저장했을때의 값을 다른곳에
	// 저장해둔걸 끌어다 출력하기 때문에 100이 출력됨
	// volatile의 의미는 휘발성일수 있으니 저장한 값이 아닌 직접 변수값을
	// 확인하라는 의미이다.
	volatile const int cint = 100;

	int *Pointer_int = nullptr;

	Pointer_int = (int*)&cint;
	*Pointer_int = 300;

	printf("cint 출력 : %d \n\n", cint);

	int a = 1;
	int b = 2;
	int* pInt = &a;

	// 1번 예시
	// const 포인터
	// a의 주소가 상수화가 된거라 변수는 값이 변경 가능함
	//	*pIntConst = 400;  하지만 주소 값을 바꿀수가 없음
	const int* pConstInt = &a;
	pConstInt = &b;

	printf("*pConstInt의 값은 : %d \n", *pConstInt);


	// 2번 예시
	// 포인터 const
	// 변수 자체가 상수화가 됨
	//	pIntConst = &b;  대신 이게 불가능함
	int* const pIntConst = &a;
	*pIntConst = 400;
	printf("a의 값은 : %d \n", a);

	return 0;
}