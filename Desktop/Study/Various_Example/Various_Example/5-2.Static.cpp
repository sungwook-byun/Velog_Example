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
	
	printf("Test 함수 호출 횟수 : %d \n", Count);

	return 0;
}