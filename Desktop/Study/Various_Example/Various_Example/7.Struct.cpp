#include<stdio.h>	
#pragma pack(1)

struct Struct_Example
{
	int a;
	char b;
	short c;
};


int main()
{
	Struct_Example Data = { };

	Data.a = 12;
	Data.b = 10;
	Data.c = 5;

	
	printf("a �� ���� : %d \n", Data.a);
	printf("b �� ���� : %d \n", Data.b);
	printf("c �� ���� : %d \n\n\n", Data.c);

	Struct_Example Data2 = {16, 7, 3};

	Data2.a;
	Data.b;
	Data.c;

	printf("a �� ���� : %d \n", Data2.a);
	printf("b �� ���� : %d \n", Data2.b);
	printf("c �� ���� : %d \n", Data2.c);

	return 0;
}