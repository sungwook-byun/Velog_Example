#include <stdio.h>


#define BLEED 1   // 0x1
#define SLOW  2	  // 0x2
#define STURN 4   // 0x4
#define SHORK 8   // 0x8
#define BURN  16  // 0x10
#define ICE   32  // 0x20
#define TIRED 64  // 0x40

// 2�� �̻��� ���¸� ���ļ� ����� �� ����
#define CLASS_DEBUF (BLEED | SLOW)

int main()
{
		
		unsigned int status = 0;

		status |= BLEED;
		status |= SLOW;
		status |= CLASS_DEBUF; 


		// ���� Ȯ��
		int hp = 100;
		if (status & SLOW)
		{
			printf("���ο� ���¸� ������ �ִ�. \n");
			hp -= 30;
		}

		// ���� ����
		if (status &= ~SLOW)
		{
			printf("���ο츦 �����Ѵ�. \n");
			hp += 10;
		}

		status;

	return 0;
}