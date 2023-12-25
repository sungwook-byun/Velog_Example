#include "CArr.h"
#include <iostream>

void CArr::realloc()
{
	MaxSize *= 2;
	int* NewData = (int*)malloc(sizeof(int) * MaxSize);

	for (int i = 0; i < CurCount; ++i)
	{
		NewData[i] = Data[i];
	}

	free(Data);

	Data = NewData;
}

CArr::CArr()
	: Data(nullptr)
	, CurCount(0)
	, MaxSize(4)
{
	Data = (int*)malloc(sizeof(int) * MaxSize);
}

CArr::~CArr()
{
	free(Data);
}

void CArr::Push(int pData)
{
	if (MaxSize <= CurCount)
	{
		realloc();
	}
	Data[CurCount++] = pData;
}


