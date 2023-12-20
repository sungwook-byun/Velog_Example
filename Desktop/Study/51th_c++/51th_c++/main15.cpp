#include <iostream>

#include <vector>
#include <list>
#include <map>

using namespace std;

#include "DArr.h"
#include "LinkedList.h"

// 자료구조
// 스택 (후입선출) , 큐 (선입선출)
// 동적 배열(가변 배열), 컨테이너(데이터를 관리하는 공간)
void InsertionSort(int* _Arr, int _Count)
{
	for (int j = 1; j < _Count; ++j)
	{
		int Temp = _Arr[j];
		int i = j - 1;
		for (; 0 <= i; --i)
		{
			if (Temp < _Arr[i])
			{
				_Arr[i + 1] = _Arr[i];
			}
			else
			{
				break;
			}
		}

		_Arr[i + 1] = Temp;
	}
}


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

	int data = 0;
	for (int i = 0; i < arr1.CurCount; ++i)
	{
		data = GetData(&arr1, i);
	}

	// data = GetData(&arr1, 5);


	// 연결형 리스트 
	LinkedList mylist = {};

	PushBack(&mylist, 10);
	PushBack(&mylist, 20);
	PushBack(&mylist, 30);

	data = GetData(&mylist, 0);
	data = GetData(&mylist, 1);
	data = GetData(&mylist, 2);




	LinkedList mylist2 = {};

	PushBack(&mylist2, 10);
	PushBack(&mylist2, 20);
	PushBack(&mylist2, 30);
	PushBack(&mylist2, 40);

	data = GetData(&mylist2, 0);
	data = GetData(&mylist2, 1);
	data = GetData(&mylist2, 2);
	data = GetData(&mylist2, 3);
	//data = GetData(&mylist2, 4);

	Reverse(&mylist2);

	data = GetData(&mylist2, 0);
	data = GetData(&mylist2, 1);
	data = GetData(&mylist2, 2);
	data = GetData(&mylist2, 3);


	// 삽입 정렬
	int Arr[4] = { 16, 4, 22, 7 };

	InsertionSort(Arr, 4);


	return 0;
}