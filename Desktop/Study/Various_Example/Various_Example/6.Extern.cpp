#include<stdio.h>
#include "6-2.Extern.h"

int Test()
{
	int Extern_Val = 500;
	return Extern_Val;
}

int main()
{
	printf("Extern.h �� �ִ� Extern_Val  �� ���� : %d \n", Extern_Val);

	int Extern_Val = 0;
	printf("main()���� ���� �ٲ� Extern_Val �� ���� : %d \n", Extern_Val);

	int Test_Result = Test();
	printf("Test_Result�� �ִ� Extern_Val ���� : %d \n", Test_Result);

	return 0;
}