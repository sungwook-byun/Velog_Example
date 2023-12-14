#include <iostream>

struct object
{
	const int id;
	int hp;
	int mp;

};


int main()
{
	//문자
	// 문자 == 정수
	// 문자타입에 숫자를 넣으면 아스키코드표에 있는 숫자에 매칭하는 문자를 가져와서 보여줌
	short s = 49;
	wchar_t wc = 50; // wchar_t wc = '2';
	char c = 61;

	// 문자 배열
	char cname[10] = "Hello"; // 문자 하나하나가 1바이트 라는 의미
//	wchar_t name[10] = { L'1',L'2',L'3',};
	wchar_t name[10] = L"Hello"; // 문자 하나하나가 2바이트 라는 의미, wchar_t만 가능한 방식


	// 문자열
	


	// const 포인터
	const char* pString = "abcdef";

	// const * 타입
	// 주소를 저장하고, 접근(읽기) 까지만 가능
	// 원본 변수를 수정 할 수 없음
	int data = 0;
	int data2 = 2;

	const int* pData = &data;

	int i = *pData; // 접근은 가능
	// *pData = 100;  다만 수정은 불가능

	pData = &data2;
	// &pData = 200;
	
	// * const 타입
	int* const pConst = &data;
	*pConst = 500; // 값 구정은 가능
	// pConst = &data2; 다만 접근은 불가능


	// const 키워드
	int value = 100;

	// 변수를 상수화
	const int cvalue = 100;

	// 강제 캐스팅으로 const가 붙은 값을 포인터로 바꿀수 있음
	int* pForce =(int*) & cvalue;
	*pForce = 200;


	{
		object a = {10};
		object b = {11};
		object c = {12};

		a.hp = 10;
	}


	{
		int a = 0;
		int b = 0;

		// 포인터 변수 자체가 상수화됨
		int* const pInt = &a;
		*pInt = 100;

		int b = 0;
		// pInt = &b;

		// 포인터로 원본을 수정하는 기능이 막힘
		const int* pInt2 = &a;
		pInt2 = &b;
		// *pInt2 = 200;

		// 한번 가르킨 대상을 다른 대상으로 변경할 수도 없고
		// 가르키고 있는 원본을 수정할수도 없음
		const int* const pInt3 = &a;

		

	}




	return 0;
}