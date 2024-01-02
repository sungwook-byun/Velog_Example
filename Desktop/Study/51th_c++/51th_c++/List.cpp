#include <iostream>

#include <vector>
using std::vector;

#include <list>
using std::list;

#include "List.h"

struct CharInfo
{
	wchar_t szName[20];
	int		HP;
	int		MP;
	int		SP;

	int		MaxHP;
	int		MaxMP;
	int		MaxSP;

public:
	void SetInfo(const wchar_t* _strName, int _HP, int _MP, int _SP)
	{
		wcscpy_s(szName, _strName);
		HP = MaxHP = _HP;
		MP = MaxMP = _MP;
		SP = MaxSP = _SP;
	}

	CharInfo()
		: HP(0), MP(0), SP(0)
		, MaxHP(0), MaxMP(0), MaxSP(0)
	{}

	CharInfo(const wchar_t* _strName, int _HP, int _MP, int _SP)
		: HP(0), MP(0), SP(0)
		, MaxHP(0), MaxMP(0), MaxSP(0)
	{
		SetInfo(_strName, _HP, _MP, _SP);
	}

	~CharInfo()
	{}

};


List<CharInfo> charlist;

int main()
{
	int a = 10;
	++(++(++a));

	//CharInfo(L"Warrior", 100, 30, 50) - 임시객체, 이름없는 지역변수
	charlist.push_back(CharInfo(L"Warrior", 100, 30, 50));
	charlist.push_back(CharInfo(L"Archer", 80, 50, 40));
	charlist.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	List<CharInfo>::iterator listiter;

	listiter = charlist.begin();
	const CharInfo& info = *listiter;

	// 자기자신을 반환하게 만들었기 때문에, 다시 ++ 함수를 재 호출 가능
	++(++(++listiter));

	// 후위 연산자
	int i = 0;
	int i2 = ++i;

	List<CharInfo>::iterator listiter2;
	listiter = charlist.begin();
	listiter2 = listiter++;


	// insert 함수 테스트
	List<CharInfo> CharList;
	CharList.push_back(CharInfo(L"Warrior", 100, 30, 50));
	CharList.push_back(CharInfo(L"Archer", 80, 50, 40));
	CharList.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	// Warrior 를 가리킴
	List<CharInfo>::iterator iter = CharList.begin();

	// Warrior 에 Theif 를 insert 함( 카운트 4, iter 는 theif 를 가리킴)
	// iter = CharList.insert(iter, CharInfo(L"Theif", 60, 30, 100));

	// Archer 가리킴
	// 카운트 4, iter 는 theif 를 가리킴, W -> T -> A -> Wi
	++iter;
	iter = CharList.insert(iter, CharInfo(L"Theif", 60, 30, 100));


	// erase 테스트



	return 0;
}



// 1. DArr::iterator ++, -- 연산자 함수 마무리하기
//  - 예외처리
//  - 반환타입 처리
//  - 후위 연산자 버전 구현
//  - 함수 별로 이미지 캡처, 제목