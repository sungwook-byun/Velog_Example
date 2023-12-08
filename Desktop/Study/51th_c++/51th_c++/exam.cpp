#include<stdio.h>


int main()
{
	int iArray[10] = { 44, 99, 47, 76, 26, 11, 46, 87, 56, 28 };
	int iNum = sizeof(iArray) / sizeof(int);
	

	for (int j = 0; j < iNum - 1; ++j)
	{
		int check = 0; // 0으로 초기화
		for (int i = 0; i < iNum - (1 + j); ++i)
		{
			if (iArray[i] > iArray[i + 1])
			{
				int Temp = iArray[i];
				iArray[i] = iArray[i + 1];
				iArray[i + 1] = Temp;
				check++; // 자리 바꿈이 있을경우 횟수를 증가시킴
			}
		}
		// 자리 바꿈이 없다면 생략
		if (check == 0)
			break;
	}

	for (int i = 0; i < 10; ++i)
	{
		printf("%d \n", iArray[i]);
	}
	return 0;
}