#include<stdio.h>

static int a = 0;

int Test()
{

	++a;
	return a;
}



int main()
{
	
	Test();
	Test();
	Test();

	a = 10;

	int data = Test();

	printf("a의 값은 : %d \n", a);
	printf("data의 값은 : %d \n", data);


	return 0;
}