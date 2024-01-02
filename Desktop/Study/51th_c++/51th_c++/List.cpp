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

	//CharInfo(L"Warrior", 100, 30, 50) - �ӽð�ü, �̸����� ��������
	charlist.push_back(CharInfo(L"Warrior", 100, 30, 50));
	charlist.push_back(CharInfo(L"Archer", 80, 50, 40));
	charlist.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	List<CharInfo>::iterator listiter;

	listiter = charlist.begin();
	const CharInfo& info = *listiter;

	// �ڱ��ڽ��� ��ȯ�ϰ� ������� ������, �ٽ� ++ �Լ��� �� ȣ�� ����
	++(++(++listiter));

	// ���� ������
	int i = 0;
	int i2 = ++i;

	List<CharInfo>::iterator listiter2;
	listiter = charlist.begin();
	listiter2 = listiter++;


	// insert �Լ� �׽�Ʈ
	List<CharInfo> CharList;
	CharList.push_back(CharInfo(L"Warrior", 100, 30, 50));
	CharList.push_back(CharInfo(L"Archer", 80, 50, 40));
	CharList.push_back(CharInfo(L"Wizzard", 50, 100, 20));

	// Warrior �� ����Ŵ
	List<CharInfo>::iterator iter = CharList.begin();

	// Warrior �� Theif �� insert ��( ī��Ʈ 4, iter �� theif �� ����Ŵ)
	// iter = CharList.insert(iter, CharInfo(L"Theif", 60, 30, 100));

	// Archer ����Ŵ
	// ī��Ʈ 4, iter �� theif �� ����Ŵ, W -> T -> A -> Wi
	++iter;
	iter = CharList.insert(iter, CharInfo(L"Theif", 60, 30, 100));


	// erase �׽�Ʈ



	return 0;
}



// 1. DArr::iterator ++, -- ������ �Լ� �������ϱ�
//  - ����ó��
//  - ��ȯŸ�� ó��
//  - ���� ������ ���� ����
//  - �Լ� ���� �̹��� ĸó, ����