#include <iostream>
#include "CArr.h"

int main()
{
	CArr arr = {};
	
	arr.Push(10);
	arr.Push(20);
	arr.Push(30);
	arr.Push(40);

	int a = arr[2];
	arr[2] = 50;


	



	for (int i = 0; i < arr.size(); ++i)
	{
		printf("입력 데이터 : %d\n", arr.at(i));
	}



	return 0;
}