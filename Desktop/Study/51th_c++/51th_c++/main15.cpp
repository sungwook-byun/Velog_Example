#include <iostream>

#include "DArr.h"

// �ڷᱸ��
// ���� (���Լ���) , ť (���Լ���)
// ���� �迭(���� �迭), �����̳�(�����͸� �����ϴ� ����)


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