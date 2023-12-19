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
	// 1. �� ū �޸� ������ �Ҵ� �޴´�.	
	_pArr->MaxCount *= 2;
	int* pNew = (int*)malloc(_pArr->MaxCount * sizeof(int));

	// 2. ������ ������ �ִ� �����͸� ���ο� ������ �Űܵд�.
	for (int i = 0; i < _pArr->CurCount; ++i)
	{
		pNew[i] = _pArr->pData[i];
	}

	// 3. ���� �޸� �Ҵ���� ������ ����
	free(_pArr->pData);

	// 4. ���ο� ������, �����͸� �����ϴ� ������ ����
	_pArr->pData = pNew;
}

void PushData(DArr* _pArr, int _Data)
{
	if (_pArr->MaxCount <= _pArr->CurCount)
	{
		// ���� Ȯ��
		Realloc(_pArr);
	}

	_pArr->pData[_pArr->CurCount++] = _Data;
}

int GetData(DArr* _pArr, int _Idx)
{
	// �����迭�� �Էµ� ������ ���ڸ� �ʰ��ϴ� �ε����� �����Ϸ��� ��� ���
	assert(!(_pArr->CurCount <= _Idx));

	return _pArr->pData[_Idx];
}