#include <stdio.h>

void Test(int *a)
{
	*a = 500;
}


int main()
{
	int i = 10;

	int* pointer_val = &i;

	printf("i의 값은 : %d \n", i);

	*pointer_val = 200;

	printf("pointer_val의 값은 : %d \n", *pointer_val);

	i = *pointer_val;

	printf("i의 값은 : %d \n", i);
	printf("\n\n\n\n");
	

	int iArr[10] = {};

	*iArr = 15;
	*(iArr + 1) = 30;
	printf("iArr[0] 의 값은 : %d \n", iArr[0]);
	printf("iArr[1] 의 값은 : %d \n", iArr[1]);
	printf("\n\n\n\n");

	{
		int a = 100;
		Test(&a);

		printf("a의 값은 : %d \n", a);
	}


	return 0;
}