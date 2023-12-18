#include <iostream>

#include "DArr.h"

// 자료구조
// 스택 (후입선출) , 큐 (선입선출)
// 동적 배열(가변 배열), 컨테이너(데이터를 관리하는 공간)


int main()
{
	int iArr[100] = {};


	DArr arr1 = {};
	DArr arr2 = {};
	DArr arr3 = {};
	DArr arr4 = {};


	InitDArr(&arr1);
	PushData(&arr1, 10);
	PushData(&arr1, 20);
	PushData(&arr1, 30);
	PushData(&arr1, 40);

	PushData(&arr1, 50);

	return 0;
}