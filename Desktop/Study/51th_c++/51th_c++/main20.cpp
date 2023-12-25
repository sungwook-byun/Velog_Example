#include <iostream>

#include "CArr.h"


int Add(int a, int b)
{
	return a + b;
}

int main()
{
	CArr arr;

	int i = 0;
	i = arr.size();
	i = arr.capacity();

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);

	int a = arr[2];
	arr[2] = 60;


	

	for (int i = 0; i < arr.size(); ++i)
	{
		printf("입력 데이터 : %d\n", arr.at(i));
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		printf("입력 데이터 : %d\n", arr[i]);
	}

	return 0;
}