#include <stdio.h>

// 메모리

// 스택
// 데이터
// ROM (코드, 문자열 등) 



struct PlayerInfo
{
	int CurHp;
	int MaxHp;
	int CurMp;
	int MaxMp;
	int Att;
	int Def;
};



void Add(int a, int b, int* _Out)
{
	*_Out = a + b;


}


// 전체를 복사해오는게 아닌 주소만 받는 방식을 사용하는 포인터가 훨씬 효율적이라고 할 수 있음
void OutputPlayerInfo(const PlayerInfo* _pinfo)
{	
	printf("플레이어 체력 %d / %d \n", _pinfo->CurHp, _pinfo->MaxHp);
	printf("플레이어 마나 %d / %d \n", _pinfo->CurMp, _pinfo->MaxMp);

	printf("플레이어 공격력 %d / %d \n", _pinfo->Att, _pinfo->Att);
	printf("플레이어 방어력 %d / %d \n", _pinfo->Def, _pinfo->Def);
}


void TestFunc(const int*)
{




}

int main()
{
	int Result = 0;

	// 반환값은 void이지만 주소값을 넘겨서 받았기 때문에 값이 변경됨
	Add(100, 200, &Result); 

	PlayerInfo info = {};

	info.CurHp = 40;
	info.MaxHp = 100;

	info.CurMp = 40;
	info.MaxMp = 50;

	info.Att = 1000;
	info.Def = 500;

	// 주소만 받아감
	OutputPlayerInfo(&info);

	


	// 문자열
	char szString[10] = "abcdef";

	// 문자열은 주소값이다.
	// 코드상에 존재하는 문자열의 정보는 ROM에 저장된다.
	// 문자열은 ROM에 있는 문자열 데이터의 주소를 의미한다.
	// char, Wchar_t 타입 배열을 초기화 시 문자열을 대입하는경우
	// 배열의 각 요소를 문자열의 각 문자로 초기화 하겠다는 의미 

	// 포인터에 넣어도 문제가 없다는건 주소만 받는 포인터이므로 결국 문자열은 주소값이라는 결론이 나온다.
	const char* pString = "abcdef";

	// a가 들어옴
//	char c = *pString;


	char c = 0;

	// 문자열로 초기화 받은 배열의 두번째 문자를 읽어서 변수 c에 저장하는 경우
	c = szString [1];  //	c = *(szString + 1);
	szString[1] = 'a';

	// 직접 문자열로 접근해서 두번째 문자를 읽어서 변수 c에 저장하는 경우
	c = pString[1];		//	c = *(pString + 1);
	// 강제캐스팅으로 해도 당장은 오류가 안나지만 포인터로 ROM영역은 읽기전용메모리인데 접근했다 한들 제대로 실행이 될리가 없음
	// ROM 에 있는 초기화용 문자열 원본을 수정하려고 하기 때문
	((char*)pString)[1] = 'a'; // 컴파일,링크, -> 런타임에러(실행도중에 문제 발생)


	// 같은 구조의 문자열은 동일한 곳의 주소를 나타낸다.
	// 코드상에서 동일한 문자열이 여러번 나오더라도, 해당 문자열은 메모리상에 딱 1개만 존재한다.
	const char* pString2 = "abcdef";


	const int value = 100;
	
	const int* pValue = &value;
	 
//	int* pValue1 = pValue;  // const타입이니까 const만 가능함

	// 문자열의 끝 NULL문자 (문자열의 끝을 알리는 널문자가 반드시 존재해야 한다.)
	// 문자열 중간에 0(널문자)를 넣으면 문자열이 끊긴다. 

	// char data[6] = "abcdef"; 마지막 0까지 7칸이 있어야 하는데 6칸만 주니 오류가 남
	char data[7] = "abcdef";

	char character = '\0';





	
	return 0;
}