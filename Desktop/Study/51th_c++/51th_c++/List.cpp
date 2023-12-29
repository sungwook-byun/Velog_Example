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
	//CharInfo(L"Warrior", 100, 30, 50) - �ӽð�ü, �̸����� ��������
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

	// list �� insert �Լ� �׽�Ʈ
	stdcharlist.insert(listiter, CharInfo(L"Berserker", 80, 10, 80));
	const CharInfo& info = (*listiter);

	// list �� erase �Լ� �׽�Ʈ
	// Warrior - Berserker - (Archer) - Wizzard
	listiter = stdcharlist.begin();
	++listiter;
	++listiter;

	listiter = stdcharlist.erase(listiter);
	const CharInfo& charinfo = *listiter;


	// erase ����
	vector<int> vecInt;
	for (int i = 0; i < 100; ++i)
	{
		// 1 ~ 100 ���� �Է�
		vecInt.push_back(i + 1);
	}

	// erase ����ϴ� ��� iterator �� ������ ���� �ʰ�, ������ ���� iterator �� �����޴� ����
	// ���� �ݺ������� iterator �� �Ź� ++ �ϴ� ��� erase �Լ��� �ߺ��Ǿ 
	// ����Ű�� ��Ҹ� �ι� �����ϰ� �� �� �ִ�.
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