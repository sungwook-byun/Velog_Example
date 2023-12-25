#pragma once


struct DArr
{
	int* Data;
	int Count;
	int maxsize;
};

void Init(DArr* _Data);

void Push(DArr* _Data, int data);

int Get(DArr* _Data, int arr);

void Realloc(DArr* _Data);