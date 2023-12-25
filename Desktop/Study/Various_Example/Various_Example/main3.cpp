#include <iostream>
#include "Darr2.h"


int main()
{
	DArr Arr = {};

	Init(&Arr);

	Push(&Arr, 10);
	Push(&Arr, 20);
	Push(&Arr, 30);
	Push(&Arr, 40);

	Get(&Arr, 1);
	Get(&Arr, 2);
	Get(&Arr, 3);
	Get(&Arr, 4);

	Push(&Arr, 50);
	Get(&Arr, 5);

	for (int i = 0; i < Arr.Count; ++i)
	{
		printf("%d \n", Arr.Data[i]);
	}


	return 0;
}