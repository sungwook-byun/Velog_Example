#include <iostream>

#include "BST.h"
#include "Str.h"
#include <map>
using std::map;
using std::make_pair;

#include <string.h>

int main()
{
	// ���ڿ� Ű�� ���
	// ���ڿ��� Ÿ���� const char* Ÿ��
	const wchar_t* pChar = L"asdasd";

	map<const wchar_t*, int> mapData;
	mapData.insert(make_pair(L"Father", 0));
	mapData.insert(make_pair(L"Mother", 1));
	mapData.insert(make_pair(L"Brother", 2));
	mapData.insert(make_pair(L"Sister", 3));

	map<const wchar_t*, int>::iterator iter = mapData.find(L"Father");
	iter->first;
	iter->second;
	wchar_t szName[20] = L"Father";
	mapData.find(szName);

	map<Str, int> mapString;
	mapString.insert(make_pair(L"Father", 0));
	mapString.insert(make_pair(L"Mother", 1));
	mapString.insert(make_pair(L"Brother", 2));
	mapString.insert(make_pair(L"Sister", 3));

	Str str1(L"Father");
	Str str2(L"Father");

	bool b = str1 < str2;



	// ����Ž��Ʈ���� Ű���� Str �� ����
	BST<Str, int> mybst;

	Str mystr(L"Test");

	//BSTPair<Str, int> pair;
	//mybst.insert();
	//make_bstpair(L"Test", 0);

	BSTPair<wchar_t[5], int> pair;
	Str s = pair.first;


	// map
	std::string;
	std::wstring;

	return 0;
}