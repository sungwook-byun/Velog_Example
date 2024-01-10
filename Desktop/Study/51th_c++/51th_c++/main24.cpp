#include <iostream>

#include "Str.h"

#include <map>
using std::map;
using std::make_pair;

int main()
{
	// 문자열 키값 사용
	// 문자열의 타입은 const char* 타입
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

	Str str(L"Father");


	return 0;
}