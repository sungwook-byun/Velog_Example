#include<iostream>


void Set(int* _pInt)
{
	*_pInt = 10;
}

void Set(int& _Ref)
{
	_Ref = 100;
}


int main()
{
	int input = 0;
	scanf_s("%d", &input);

	// 래퍼런스 == 포인터
	int i = 0;

	Set(&i);

	Set(i);


	// c++에서 추가된 Reference는 포인터와 동작원리가 같다.
	// 실제 내부 동작은 주소를 받아서 원본에 접근 후 수정
	// c++ 문법 상으로는 참조 변수에 원본변수는 &를 붙여서 주소를 전달할 필요가 없고
	// 레퍼런스 변수는 *를 붙여서 원본에 접근하는 연산을 할 필요가 없다.
	int iData = 0, iData2 = 0;
	// 원래 주소를 넘기는 방식
	int* p = &iData;
	*p = 10;

	// 이게 가능
	p = &iData2;
	*p = 10;

	// 레퍼런스 방식
	// 차이를 보면 주소를 받지 않아도 가능하다는 차이가 매우 큼
	// 동작원리는 똑같지만 문법의 차이가 있기 때문에 쓰임
	int& ref = iData;
	ref = 20;

	// 이렇게 하더라도 결국 ref에 0이 들어가는 결과가 나옴
	// 한번 참조 받으면 그 이후로는 참조가 아니라 대입이 되는것임
	ref = iData2;


	// 레퍼런스의 기능은 포인터 const 타입 포인터와 유사하다(처음 초기화 당시 받은 대상을 다른 대상으로 바꿀수 없는 부분)
	int* const pointer = &iData;
//	pointer = &iData2;
	*pointer = 200;

	// const & 타입은 const * const 와 유사하다. 처음 초기화 당시 받은 원본 참조를 다른 대상으로 변경 불가능하고
	// 참조받은 대상 원본을 수정하는 것도 불가능
	const int& const_ref = iData;
	// 원본변수는 수정이 가능함
	iData = 200;
//	const_ref = 100;

	// 규모가 큰 데이터를 읽어들일때 사용
	int d = const_ref;
	

	return 0;
}