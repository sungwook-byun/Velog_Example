#include<stdio.h>
#include "6-2.Extern.h"

int Test()
{
	int Extern_Val = 500;
	return Extern_Val;
}

int main()
{
	printf("Extern.h 에 있는 Extern_Val  의 값은 : %d \n", Extern_Val);

	int Extern_Val = 0;
	printf("main()에서 값을 바꾼 Extern_Val 의 값은 : %d \n", Extern_Val);

	int Test_Result = Test();
	printf("Test_Result에 있는 Extern_Val 값은 : %d \n", Test_Result);

	return 0;
}