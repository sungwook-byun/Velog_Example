#include <stdio.h>

#define BLEED 1   // 0x1
#define SLOW  2	  // 0x2
#define STURN 4   // 0x4
#define SHORK 8   // 0x8
#define BURN  16  // 0x10
#define ICE   32  // 0x20
#define TIRED 64  // 0x40

// 2개 이상의 상태를 합쳐서 사용할 수 있음
#define CLASS_DEBUF (BLEED | SLOW)

int main()
{
		
		unsigned int status = 0;

		status |= BLEED;
		status |= SLOW;
		status |= CLASS_DEBUF; 


		// 상태 확인
		int hp = 100;
		if (status & SLOW)
		{
			printf("슬로우 상태를 가지고 있다. \n");
			hp -= 30;
		}

		// 상태 제거
		if (status &= ~SLOW)
		{
			printf("슬로우를 제거한다. \n");
			hp += 10;
		}

		status;

	return 0;
}