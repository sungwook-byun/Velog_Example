#include<iostream>
#include "DArr.h"

int main()
{
	DArr Arr = {};
	
	InitDArr(&Arr);
	PushData(&Arr, 10);
	PushData(&Arr, 20);
	PushData(&Arr, 30);
	PushData(&Arr, 40);
	PushData(&Arr, 50);

	for (int i = 0; i < Arr.CurCount; ++i)
	{
		printf("%d  \n", Arr.pData[i]);
	}

	return 0;
}