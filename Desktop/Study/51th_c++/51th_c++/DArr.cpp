#include "DArr.h"
#include <iostream>

void InitDArr(DArr* _pArr)
{
	_pArr->CurCount = 0;
	_pArr->MaxCount = 4;
	_pArr->pData = (int*)malloc(sizeof(int) * _pArr->MaxCount);
}

void PushData(DArr* _pArr, int _Data)
{
	if (_pArr->MaxCount <= _pArr->CurCount)
	{
		// 공간 확장
		Realloc(_pArr);
	}

	_pArr->pData[_pArr->CurCount++] = _Data;
}

void Realloc(DArr* _pArr)
{

}