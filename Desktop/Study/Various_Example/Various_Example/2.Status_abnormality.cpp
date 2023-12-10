#include<stdio.h>

// define으로 상태이상 값을 16진수 값으로 설정을 해둠
#define HUNGRY 0x1		//  1  
#define THIRSTY	0x2		//  2 
#define HOT	0x4		    //  4  
#define COLD 0x8		//  8  
#define TIRED 0x10	    //  16 
#define POISON 0x20	    //	32 
#define TOTAL_CRISIS (HUNGRY | HOT | POISON);

int main()
{
	int Status = 0;
	int HP = 100;
	int Check = 0;
	char Name[10];

	printf("*******************************************\n");
	printf("모험가의 닉네임을 입력해 주세요 : ");
	scanf_s("%s", Name, 10);
	printf("모험가 닉네임 : %s \n", Name);
	printf("*******************************************\n\n");
	while (1)
	{
	printf("▶현재 HP는 %d 입니다.\n\n", HP);
	printf("Q. 어떤 상태이상을 부여 하시겠습니까?.\n");
	printf("▶(1.배고픔 / 2.목마름 / 3.고열 / 4.동상 / 5.피곤함 / 6.중독 / 7. 대환장 / 8. 종료) : ");
	scanf_s("%d", &Status);
	printf("\n\n");


	// 상태 부여 if문
	if (Status == 1)
	{
		Status = 0;
		Status |= HUNGRY;
		HP -= 20;
		printf("▶배고픔 상태를 부여 했습니다. (- HP 20) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else if (Status == 2)
	{
		Status = 0;
		Status |= THIRSTY;
		HP -= 20;
		printf("▶목마름 상태를 부여 했습니다. (- HP 20) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else if (Status == 3)
	{
		Status = 0;
		Status |= HOT;
		HP -= 20;
		printf("▶고열 상태를 부여 했습니다. (- HP 20) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else if (Status == 4)
	{
		Status = 0;
		Status |= COLD;
		HP -= 20;
		printf("▶동상 상태를 부여 했습니다. (- HP 20) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else if (Status == 5)
	{
		Status = 0;
		Status |= TIRED;
		HP -= 20;
		printf("▶피곤함 상태를 부여 했습니다. (- HP 20) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else if (Status == 6)
	{
		Status = 0;
		Status |= POISON;
		HP -= 60;
		printf("▶중독 상태를 부여 했습니다. (- HP 20) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else if (Status == 7)
	{
		Status = 0;
		Status |= TOTAL_CRISIS;
		HP -= 60;
		printf("▶대환장 상태를 부여 했습니다. (- HP 60) \n");
		printf("▶현재 체력은 %d 입니다. \n", HP);
	}
	else
	{
		printf("▶프로그램을 종료합니다. \n\n\n");
		break;
	}

	
	// 물약 복용 if문
	printf("Q. 물약을 복용 하시겠습니까? ( 1. YES / 2. NO ) : ");
	scanf_s("%d",&Check);
	printf("\n\n");
	if (Check == 1)
	{
		if (Status & HUNGRY)
		{
			Status &= ~HUNGRY;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 배고픔 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
		else if (Status & THIRSTY)
		{
			Status &= ~THIRSTY;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 목마름 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
		else if (Status & HOT)
		{
			Status &= ~HOT;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 고열 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
		else if (Status & COLD)
		{
			Status &= ~COLD;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 동상 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
		else if (Status & TIRED)
		{
			Status &= ~TIRED;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 피곤함 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
		else if (Status & POISON)
		{
			Status &= ~POISON;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 중독 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
		else
		{
			Status &= ~TOTAL_CRISIS;
			HP += 30;
			printf("물약을 복용 했습니다.\n");
			printf("+HP 30 회복과 대환장 상태를 해제합니다.\n");
			printf("현재 HP는 %d 입니다.\n", HP);
			printf("메인 화면으로 돌아갑니다.\n\n\n");
		}
	}
	else
	{
		printf("물약을 복용하지 않았습니다.\n");
		printf("메인 화면으로 돌아갑니다.\n\n\n");
	}
	}
	return 0;
}