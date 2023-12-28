#include <iostream>

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
	//CharInfo(L"Warrior", 100, 30, 50) - 임시객체, 이름없는 지역변수
	charlist.push_back(CharInfo(L"Warrior", 100, 30, 50));
	charlist.push_back(CharInfo(L"Archer", 80, 50, 40));
	charlist.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	return 0;
}