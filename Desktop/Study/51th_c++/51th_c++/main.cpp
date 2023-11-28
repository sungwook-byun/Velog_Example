

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
	unsigned number = -1;

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

	return 0;
}