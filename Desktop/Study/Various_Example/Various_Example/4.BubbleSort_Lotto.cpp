#include<stdio.h>
#include<cstdlib>
#include<ctime>
 
// 로또의 복권번호는 6개니까 6으로 설정
#define Size 6

int main()
{
	int Lotto[Size] = {};

	int Winning_Number[Size] = {14 ,33 ,34 ,35 ,37 ,40 }; // 로또 1097회 당첨번호
	int Winning_Bonus = 4; // 로또 1097회 보너스 당첨번호
	int Null = 0;
	int Accumulate_Num = 0;

//	int Num_Size = sizeof(Lotto) / sizeof(int); // Lotto의 경우 4바이트 정수가 6개 들어있으니 24가 나올것이고 int는 4바이트니까 사이즈는 6이 나옴

	// 난수를 발생시킴
	srand((int)time(NULL));
	for (int i = 0; i < Size; ++i)
	{
		Lotto[i] = rand() % 45 + 1;
		for (int j = 0; j < i; ++j)
		{
			if (Lotto[i] == Lotto[j])
				--i;
		}
	}
	// 6개 숫자의 사이를 비교하는것이기 때문에 Size에서 1을 빼줘야함
	for(int j = 0; j < Size - 1; ++j)
	{
		bool Check = true;
		// 이중포문이 돌기 전에 밖의 for문이 먼저 1번 시행 됐고, 계속 1씩 차감되는 형식을 유지해야 하기 때문에 -i로 설정
		for (int i = 0; i < Size - (1 + j); ++i)
		{
			if (Lotto[i] > Lotto[i + 1])
			{
				Null = Lotto[i];
				Lotto[i] = Lotto[i + 1];
				Lotto[i + 1] = Null;
				Check = false;
			}
		}
		if (Check == true)
			break;
	}

	// 보너스 번호 확인
	for (int i = 0; i < Size; ++i)
	{
		if (Lotto[i] == Winning_Bonus)
		{
			++Accumulate_Num;
			break;
		}
	}

	// 당첨 개수 확인
	for (int j = 0; j < Size; ++j)
	{
		for(int i = 0; i < Size; i++)
		{
			if (Winning_Number[j] == Lotto[i])
			{
				++Accumulate_Num;
			}
		}
	}



// 출력부
	printf("-----------------------------------------------------------------------\n");
	printf("▶로또 1097회차 당첨번호는 14 ,33 ,34 ,35 ,37 ,40    보너스 번호 : 4◀\n");
	printf("-----------------------------------------------------------------------\n\n\n");
	
	
	printf("내가 뽑은 번호 : ");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d    ", Lotto[i]);
	}
	printf("\n\n\n\n");

	if (Accumulate_Num == 6)
	{
		printf("▶*********** 1 등 ***********◀\n");
		printf("로또 1097회차 1등에 당첨되셨습니다!\n");
	}
	else if (Accumulate_Num == 5)
	{
		printf("▶*********** 2 등 ***********◀\n");
		printf("로또 1097회차 2등에 당첨되셨습니다!\n");
	}
	else if (Accumulate_Num == 4)
	{
		printf("▶*********** 3 등 ***********◀\n");
		printf("로또 1097회차 3등에 당첨되셨습니다!\n");
	}
	else if (Accumulate_Num == 3 )
	{
		printf("▶*********** 4 등 ***********◀\n");
		printf("로또 1097회차 4등에 당첨되셨습니다!\n");		}
	else
	{
		printf("       ▶미 당 첨◀\n");
		if (Accumulate_Num == 2)
			printf("▶2개를 맞추셨습니다.◀\n\n");
		else if (Accumulate_Num == 1)
			printf("▶1개를 맞추셨습니다.◀\n\n");
		else
			printf("▶하나도 맞추지 못하셨습니다.◀\n\n");
	}

}