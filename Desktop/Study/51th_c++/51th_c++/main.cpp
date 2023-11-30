

#include<stdio.h>

// main이라는 함수
// main 함수 : 프로그램의 시작, 진입 점 함수
int main(void)
{

	// C++ 언어
	// C 언어 -> C++ (객체지향)

	// 자료형(Data Type)
	// 데이터 크기의 단위는 Byte == 8 Bit
	// 정수 타입 - char(1), short(2), wchar_t(2), int(4), long(4), long long(8), __int64(8)
	// 실수 타입 - float(4), double(8)


	// 1바이트 == 8비트
	// 1비트

	// char : 자료형  /  number : 변수 이름, 변수 /    = : 대입 연산자 
	// char : -128 ~ 0 ~ 127
	char number = 0;

	//unsigned char : 0 ~ 255
	unsigned char unsigned_number = 0;

	// 데이터의 다름이 문제가 아니라
	// 같은 데이터도 값을 어떻게 분석, 해석 하느냐에 따라서 달라질 수 있다.
	// 데이터 자체는 값이 같지만 해석에 따라 -1이 될수도 +128이 될수도 있다.
	// 음수를 찾는 방법은 양수를 반전시킨 후에 맨 뒤에 숫자에 +1을 함 (2의 보수법)
	
	//255와 비트값은 같지만 해석관점에 따라 다르기 때문에 값으로 따지면 255가 출력됨
	unsigned number2 = 1;

	// 크기 2바이트(16비트), 정수타입(signed) 변수 선언sd
	// -32768 ~ 0 ~ 32767
	short shortNum = 0;

	// 0~ 65536
	unsigned short unsigned_short = 0;

	// 크기 4바이트(32 비트), 정수타입
	// -21억 ~ 21억
	// 0 ~ 43억


	{
		char data = 44;
		int iData = 56;
		int i = data + (int)iData;
	}

	// 정수 타입 자료형
	// char(1), short(2), int(4), long(4)

	// 실수 자료형 - 소수 점까지 표현
	// float(4), double(8)
	// 0 ~ 0.1 사이에는 무수히 많은 수가 존재함
	// 특정 비트값을 하나의 실수 숫자에 대응하기에는, 실수의 개수는 무한대이다.
	// 부동 소수점 표현 방식
	// 실수는 정확한 값이 아니다. 정밀도를 고려해야 한다.

	float f = 0.315f; // 값을 보면 근사값으로 설정됨
	float d = 10.f / 3.f;
	float fSum = f * 7.f;

	// 실수 타입의 변수의 값을 조건으로 활용할 때 주의 해야 함
	if (fSum == 10.f)
	{
		//오차를 어느정도는 허용 해 주어야 함
	}

	f = -118.625;

	// 실수타입 변수 f 안에 들어있는 값을 정수로 해석한 경우의 값을 확인
	int* pInt = (int*)&f;
	int i = *pInt;

	// float 타입 데이터를 int 타입으로 암시적 형변환이 이루어지기 때문에 명시적으로 형변환을 해주어야함
	i = (int)f;

	// 실수 타입과 정수 타입 변수가 섞여서 문제가 발생하는 경우
	int a = 0, b = 0, c = 0;

	a = 1000;
	b = 1;
	c = b / a;
	float div = (float)b / (float)a;
	
	// 연산자

	/* 
	증감 연산자
	++, --
	*/
	{
		int i = 0;
		// 전위(전치)
		++i;
		--i;

		// 후위(후치)
		i++;
		i--;

		// 전위와 후위에 따른 연산자 우선순위 변경
		// 전위는 우선순위가 가장 빠르고 후위는 가장 느리다.
		int a = 0;
		int b = 10;
		int c = 12;

		a = b + ++c; // 23이 들어감
		a = b + c++; // 대입 연산자보다도 후위가 느리기 때문에 22가 들어감

		// 단순히 증감연산자 하나만 사용하는 경우 전위건 후위건 별 상관이 없다.
		++c;

	}
	i = 0; // F12를 누르면 위에 선언한 곳으로 이동


	// 사칙 연산자
	{
		// +, -, *, /, %(모듈러스)

		int a = 30, b = 4, c = 0;

		c = a + b;
		c = a - b;
		c = a * b;
		c = a / b;

		// 정수끼리의 나눗셈은 소수점을 버리고 몫만 계산한다.
		// 따라서 나머지가 존재한다.
		c = a % b;

		// 실수의 나눗셈
		// 실수의 나눗셈에너는 나머지 개념이 없다.
		// 따라서 %는 정수끼리의 연산에서만 쓸 수 있다.
		float f1 = 0.f, f2 = 10.f, f3 = 3.f;
		f1 = f2 / f3;
		// f1 = f2 % f3;   컴파일 에러남

	}

	// 비교 연산자
	{
		// 참, 거짓
		// 0은 거짓으로 본다.
		// 0이 아니면 모두 참, 대표격 숫자가 1


		// 참, 거짓을 다루는 자료형 bool(1)
		// 표현 체계는 정수타입에 해당하지만, 0이 아닌 모든 수를 1(참) 으로 바꾸어서 저장한다.
		bool b = 45; // 0이 아니기 때문에 true로 받아들임 숫자로 따지면 1이 저장됨

		int i = 4 == 5; // 같은지 비교해보고 거짓이니 i에는 0이 저장됨
		i = 4 != 5;     // 같지 않은지 비교해보고 같지 않으니 참이므로 1을 저장

	}
	// 논리 연산자
	// &&(and), ||(or)
	{
		// && - 둘다 참인 경우에만 참
		if (100 < 200 && 400 > 300)
		{
			
		}

		// || - 둘 중 하나만 참이라도 참을 반환
		// 모두 거짓이어야 거짓
		if (1 || 0)
		{
	}
	// 비트 연산자
	// 비트 쉬프트
	// 비트 연산자

	int k = 0;

	int HP = 100;

	HP -= 10;  //	HP = HP - 10;
	// if 구문
	// if 와 else if가 연결되어 있는 경우, 하나의 조건만 성공 할 수 있다.
	// else - 어떤 조건에도 해당하지 않을때를 잡아내고 싶은 경우
	if (HP <= 0)
	{
		printf("캐릭터 사망");
	}
	// 1 ~ 30
	else if(HP <= 30)
	{
		printf("캐릭터 체력 적음");
	}
	// 31 ~
	else
	{
		printf("캐릭터 체력 많음");
	}

	// switch case
	// 각 case 의 마지막에 break 를 이용해서 switch 구문을 종료한다.
	// 여러 case 의 조건을 묶고 싶은 경우 case 를 모아서 한번에 break 처리를 한다.
	// 각 case 를 break 로 별개 처리하려고 했지만, 실수로 break 를 작성하지 않으면 오류로 체크되지 않아 찾기가 힘들다.
	switch (HP)
	{
	case 100:
		printf("캐릭터 풀피");
		break;
	case 80:
		printf("캐릭터 체력 많음");
		break;
	case 50:
		printf("캐릭터 체력 절반");
		break;
	default :
		printf("케릭터 사망");
	}
	return 0;
}

// F9 : 커서에 해당하는 구문에 중단점 생성
// F5 : 디버깅 시작, 중단점이 있으면 해당 중단점 구문을 실행하기 전에 중단
//    : 디버깅중에 중단점에 멈추었을때 다시 F5를 누르면 다음 중단점까지 한번에 실행
// F10: 한 단계씩 구문을 실행함(중단점부터 시작)
// Shift + F5 : 디버그 모드 중지
