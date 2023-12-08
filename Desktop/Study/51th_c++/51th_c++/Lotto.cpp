#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6

int main()
{

	int Lotto[SIZE] = { };
	int Null = 0;
	int Winning_Number[SIZE] = { 1, 12, 16, 19, 23, 43 };
	int Winning_Bonus = 34;
	int Count_Num = 0;
	int Check_Bonus = 0;

	// 난수 발생
	srand((int)time(NULL));

	for (int i = 0; i < SIZE; ++i)
	{
		Lotto[i] = (rand() % 45) + 1;
		for (int j = 0; j < i; ++j)
		{
			if (Lotto[i] == Lotto[j])
				--i;
		}
	}

// 위에 과정을 통해 Lotto[SIZE] 라는 난수 6개를 찾아냄
// 그 6개를 이제 오름차순으로 정렬을 할 것임
	
	for (int j = 0; j < SIZE - 1; ++j)
	{
		for (int i = 0; i < SIZE - 1 - j; ++i)
		{
			if (Lotto[i] > Lotto[i + 1])
			{
				Null = Lotto[i];
				Lotto[i] = Lotto[i + 1];
				Lotto[i + 1] = Null;
			}
		}
	}

	//출력 확인용
	printf("구매 번호 : ");
	for (int k = 0; k < SIZE; ++k)
	{
		printf("%d  ", Lotto[k]);
	}

	printf("\n당첨 번호 : %d  %d  %d  %d  %d  %d ", 1, 12, 16, 19, 23, 43);
	printf("보너스 번호 : %d \n\n", Winning_Bonus);
	for(int j = 0; j < SIZE; ++j)
	{
		for(int i = 0; i < SIZE; ++i)
		{
			if (Lotto[i] == Winning_Number[j])
			{
				++Count_Num;
			}
		}
	}

	
	for (int i = 0; i < SIZE; ++i)
	{
		if (Lotto[i] == Winning_Bonus)
		{
			Check_Bonus = 1;
			break;
		}
	}

	if (Count_Num + Check_Bonus == 6)
		printf("6개 모두 맞추셨습니다.\n\n");
	else if (Count_Num + Check_Bonus == 5)
		printf("5개 맞추셨습니다.\n\n");
	else if (Count_Num + Check_Bonus == 4)
		printf("4개 맞추셨습니다.\n\n");
	else if (Count_Num + Check_Bonus == 3)
		printf("3개 맞추셨습니다.\n\n");
	else if (Count_Num + Check_Bonus == 2)
		printf("2개 맞추셨습니다.\n\n");
	else if (Count_Num + Check_Bonus == 1)
		printf("1개 맞추셨습니다.\n\n");
	else
		printf("하나도 맞추지 못하셨습니다.\n\n");


	return 0;
}