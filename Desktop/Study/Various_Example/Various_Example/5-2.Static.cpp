#include <stdio.h>
int Test()
{
	static int Static_Val = 0;
	++Static_Val;
	return Static_Val;
}

int main()
{

	Test();
	Test();
	Test();
	Test();
//	Static_Val = 0;
	int Count = Test();
	
	printf("Test �Լ� ȣ�� Ƚ�� : %d \n", Count);

	return 0;
}