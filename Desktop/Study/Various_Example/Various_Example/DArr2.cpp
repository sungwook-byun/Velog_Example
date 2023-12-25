#include "Darr2.h"
#include <iostream>

void Init(DArr* _Data)
{
	_Data->Count = 0;
	_Data->maxsize = 4;
	_Data->Data = (int*)malloc(sizeof(int) * _Data->maxsize); 
}

void Realloc(DArr* _Data)
{
	_Data->maxsize *= 2;
	int* NewData = (int*)malloc(sizeof(int) * _Data->maxsize);

	for (int i = 0; i < _Data->Count; ++i)
	{
		NewData[i] = _Data->Data[i];
	}

	free(_Data->Data);
	_Data->Data = NewData;

}

void Push(DArr* _Data, int data)
{
	if (_Data->maxsize <= _Data->Count)
	{
		Realloc(_Data);
	}
	_Data->Data[_Data->Count++] = data;
}

int Get(DArr* _Data, int arr)
{
	return _Data->Data[arr];
}


