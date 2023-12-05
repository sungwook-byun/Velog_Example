#include <stdio.h>
#include <cstring>

#define COLD 1
#define HOT 2
#define TIRED 4
#define BLEED 8

#define SKILL_SUM (COLD + BLEED);

// & 둘 다 참(1) 인 경우에만 1
// | 둘 중 하나라도 참(1) 이면 1


	// 상태 이상에 걸리면 체력이 감소하는 기능
	// 상태 이상을 풀면 조금의 체력을 회복하는 기능
int main()
{
	int Status = 0;

// HP를 100%로 선언할 방법은 없는지
	int Hp = 100;
	
	// COLD라는 상태값, TIRED라는 상태값을 부여함
	Status |= SKILL_SUM;
	Status |= TIRED;

//	char Now_Hp[10];
	int Now_Hp = 0;

	// 만약 COLD 상태라면 HP를 40을 깎고 멘트 출력
	if (Status & COLD)
	{
		printf("결빙 상태 입니다. \n");
		Hp -= 40;
		
		printf("물약 복용을 원하시면 1번을 입력해 주세요. \n");
		scanf_s("%d", &Now_Hp);
		//gets_s(Now_Hp);
		

//		char Now_Hp2[10] = "복용";

		if (Now_Hp == 1)
		{

			printf("물약 복용 완료 \n");
			Hp += 10;
			Status &= ~COLD;
			printf("체력이 10 올라서 현재 체력은 %d 이며 결빙이 해제 됩니다. \n", Hp);
		}
		else
		{
			printf("물약을 복용하지 않았습니다. \n");
			printf("현재 체력은 %d 이며 결빙 상태 입니다. \n", Hp);
		}
	}
// 중괄호의 유무
	else
	{
		printf("결빙 상태가 아닙니다.");
	}


	Status;

	return Hp;
}