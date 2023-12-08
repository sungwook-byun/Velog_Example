#include<iostream>

typedef int MYINT;
typedef int* MYINTP;



// 구조체 크기 확장 규칙을 1바이트로 제한
#pragma pack(1)

// ==================
// 사용자 정의 자료형(User Define Datatype)
// 구조체(struct), 클래스(class)
// ==================
// 구조체 크기 계산하는 방법
// 기본적으로 구조체를 구성하는  가장 큰 요소의 크기를 배수로 확장해 나감
// 따라서 가장 큰 맴버부터 순차적으로 나열하는게 자료형의 크기를 가장 효율적으로 작게 만들 수 있다.


// 안에를 계산해 보면 8바이트 라는것을 알 수 있음
// 안에 있는 가장 큰 자료형을 기준으로 배수로 늘어남. short를 지워도 안에 공간은 6이 아닌 8임
// 큰 자료형을 기준으로 순차적으로 자료를 배치하는게 좋음


struct MyDataType
{
	int i;
	char c1;
	char c2;
	short s;
};

// 4바이트씩 끊어서 공간이 생기는데 맨 앞에 char가 채우고 3바이트가 남아서 다음 공간으로 넘어가고
// short가 들어갈 자리가 두번째에 없으니 세번째 칸에 들어가기 때문에 낭비가 심함.
// 순서만 바꿔도 8바이트로 해결 가능하지만 순서로 인해 12바이트의 공간을 쓰게 됨.
struct MyDataType2
{
	char c1;
	int i;
	short s;
};

int main()
{
	// {} 를 써주면 구조체 안에 있는 자료들이 다 0으로 초기화가 됨
	MyDataType a = {};		   //MyDataType에 아무것도 선언하지 않으면
	int size = sizeof(a); //더미로 자료형을 넣어주는데 1바이트로 들어가있음을 확인 할 수 있음
				
	// 구조체 변수의 맴버에 접근해서 값을 입력
	a.i = 10;
	a.s = 0;
	a.c1 = 100;

	// 포인터
	// 주소를 저장하기 위한 변수
	// nullptr 키워드는 0을 의미하지만, 포인터타입 변수에만 대입이 가능
	int* p = nullptr;  // 0을 넣은것과 같은 의미, null , 즉 아무것도 가르키지 않고 있다 라는 의미이다.
/*	int i = NULL;
//	int i = nullptr; 포인터 변수에만 넣을수 있기때문에 오류가 남
	MYINT i3 = 0; // 청록색은 재정의했거나 따로 만든 자료형인것을 알 수 있음 F12를 누르면 선언한 곳으로 이동함
	MYINTP k = nullptr;
*/
	
	int test = 0;

	// 주소 값이기 때문에 포인터변수 안에만 넣을 수 있고 그냥 변수에 넣으면 오류남
	p = &test; // test의 주소값을 p에 넣음
	*p = 100; // 본인 안에 들어있는 주소를 참조하겠다.

	int test1 = *p; // 100이 test1에 들어감

	// 포인터 특징
	// 포인터 변수의 크기, 타겟 플랫폼에 따라 다름, 64비트 기반 운영체제는 8바이트 / 32비트는 4바이트
	// 포인터 변수의 크기 8바이트
	{
		int* pInt = nullptr;
		char c = 0;
//		pInt = (int*)&c;


		void* pVoid = nullptr;

		int i = 0;
		short s = 0;

		pVoid = &i;
		pVoid = &s;
	}

	// 포인터 선언시 자료형의 의미
	{
		char c;
		int i = 0;
		long long ll = 0;


		char*		pChar	 =		&c;
		int*		pInt	 =		&i;
		long long*	 pLL	 =		&ll;

		// void는 가리지 않음
		void* pVoid = nullptr;
		pVoid = &c;
		pVoid = &i;
		pVoid = &ll;

		// 역참조
		// 포인터변수가 저장하고 있는 주소값 만으로는 해당 주소의 실제 정체(타입)을 정확하게 알 수가 없다.
		// 따라서 포인터를 선언할 때 포인터가 가리킬 자료형을 미리 정해놓고 선언한다.
		*pChar;
		*pInt;
		*pLL;


		// 값이 동일해도 해석 방식에 따라서 값을 다르게 해석할 수 있다.
		char ca = 255;

		char* pC = &ca;
		unsigned char* pUC = (unsigned char*)&ca;

		int data = *pC;
		data = *pUC;

		float fTest = 4.f;
//		int* pData = &fTest; // 4바이트로 크기는 문제가 없지만 타입이 다르기 때문에 오류가 남
	}


	{
		// void 포인터는 주소연산(접근 및 이동) 이 불가능하다.
		// 어떠한 타입의 변수의 주소라도 받을 수 있다.
		void* pVoid = nullptr;

		int i = 0;

		pVoid = &i;
//		*pVoid; // 보이드 포인터는 접근 자체가 아예 불가능함. 단위를 아예 알 수 없어서 아무 타입이나 받을 수 있는것임
	}


	{
		MyDataType t = {};
		t.i = 10;
		t.s = 10;
		t.c1 = 10;

		MyDataType* pMyData = nullptr;
		pMyData = &t;

		// 괄호는 연산자 우선순위 때문에 먼저 수행을 해야 하기 때문에 해주는것임.
		// 아래 두 문단은 결과적으로는 똑같다는 소리임
		(*pMyData).i = 10;
		(*pMyData).s = 10;
		(*pMyData).c1 = 10;

		pMyData->i = 10;
		pMyData->s = 10;
		pMyData->c1 = 10;
	}
	`








	return 0;
}