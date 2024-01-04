#include <iostream>
#include "List.h"

struct CharInfo
{
	wchar_t szname[20];
	int HP;
	int MP;
	int SP;

	int MaxHP;
	int MaxMP;
	int MaxSP;
		
public:
	void SetInfo(const wchar_t* _szname, int _HP, int _MP, int _SP)
	{
		wcscpy_s(szname, _szname);
		HP = _HP;
		MaxHP = 500;

		MP = _MP;
		MaxMP = 500;

		SP = _SP;
		MaxSP = 500;
	}

	CharInfo()
		: HP(0), MP(0), SP(0)
		, MaxHP(0), MaxMP(0), MaxSP(0)
	{}
	CharInfo(const wchar_t* _szname, int _HP, int _MP, int _SP)
		: HP(0), MP(0), SP(0)
		, MaxHP(0), MaxMP(0), MaxSP(0)
	{
		SetInfo(_szname, _HP, _MP, _SP);
	}

	~CharInfo()
	{}

};

List<CharInfo> Charlist;

int main()
{
	Charlist.Push(CharInfo(L"Cat", 100, 100, 100));
	Charlist.Push(CharInfo(L"Dog", 80, 90, 50));
	Charlist.Push(CharInfo(L"Bird", 200, 100, 150));





	return 0;
}