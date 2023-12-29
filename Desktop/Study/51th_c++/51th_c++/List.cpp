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
list<CharInfo> stdcharlist;

int main()
{
	//CharInfo(L"Warrior", 100, 30, 50) - 임시객체, 이름없는 지역변수
	charlist.push_back(CharInfo(L"Warrior", 100, 30, 50));
	charlist.push_back(CharInfo(L"Archer", 80, 50, 40));
	charlist.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	stdcharlist.push_back(CharInfo(L"Warrior", 100, 30, 50));
	stdcharlist.push_back(CharInfo(L"Archer", 80, 50, 40));
	stdcharlist.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	list<CharInfo>::iterator listiter;

	listiter = stdcharlist.begin();
	--listiter;

	for (listiter = stdcharlist.begin(); listiter != stdcharlist.end(); ++listiter)
	{
		std::wcout << (*listiter).szName << std::endl;
	}

	listiter = stdcharlist.begin();
	++listiter;

	// list 의 insert 함수 테스트
	stdcharlist.insert(listiter, CharInfo(L"Berserker", 80, 10, 80));
	const CharInfo& info = (*listiter);

	// list 의 erase 함수 테스트
	// Warrior - Berserker - (Archer) - Wizzard
	listiter = stdcharlist.begin();
	++listiter;
	++listiter;

	listiter = stdcharlist.erase(listiter);
	const CharInfo& charinfo = *listiter;


	// erase 문제
	vector<int> vecInt;
	for (int i = 0; i < 100; ++i)
	{
		// 1 ~ 100 까지 입력
		vecInt.push_back(i + 1);
	}

	// erase 사용하는 경우 iterator 가 문제가 되지 않게, 삭제된 다음 iterator 를 돌려받는 구조
	// 따라서 반복문에서 iterator 를 매번 ++ 하는 경우 erase 함수와 중복되어서 
	// 가리키는 요소를 두번 증가하게 될 수 있다.
	vector<int>::iterator veciter = vecInt.begin();
	for (; veciter != vecInt.end(); )
	{
		if ((*veciter) <= 50)
		{
			veciter = vecInt.erase(veciter);
		}
		else
		{
			++veciter;
		}
	}




	return 0;
}