#include "DArr.h"
#include <iostream>
#include <assert.h>

void InitDArr(DArr* _pArr)
{
	_pArr->CurCount = 0;
	_pArr->MaxCount = 4;
	_pArr->pData = (int*)malloc(sizeof(int) * _pArr->MaxCount);
}

void Realloc(DArr* _pArr)
{
	// 1. 더 큰 메모리 공간을 할당 받는다.	
	_pArr->MaxCount *= 2;
	int* pNew = (int*)malloc(_pArr->MaxCount * sizeof(int));

	// 2. 기존에 가지고 있던 데이터를 새로운 곳으로 옮겨둔다.
	for (int i = 0; i < _pArr->CurCount; ++i)
	{
		pNew[i] = _pArr->pData[i];
	}

	// 3. 기존 메모리 할당받은 공간을 해제
	free(_pArr->pData);

	// 4. 새로운 공간을, 데이터를 저장하는 곳으로 갱신
	_pArr->pData = pNew;
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

int GetData(DArr* _pArr, int _Idx)
{
	// 동적배열에 입력된 데이터 숫자를 초과하는 인덱스에 접근하려는 경우 경고
	assert(!(_pArr->CurCount <= _Idx));

	return _pArr->pData[_Idx];
}