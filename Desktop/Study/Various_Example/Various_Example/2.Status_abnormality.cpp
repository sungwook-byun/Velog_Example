#include<stdio.h>

// define���� �����̻� ���� 16���� ������ ������ �ص�
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
	printf("���谡�� �г����� �Է��� �ּ��� : ");
	scanf_s("%s", Name, 10);
	printf("���谡 �г��� : %s \n", Name);
	printf("*******************************************\n\n");
	while (1)
	{
	printf("������ HP�� %d �Դϴ�.\n\n", HP);
	printf("Q. � �����̻��� �ο� �Ͻðڽ��ϱ�?.\n");
	printf("��(1.����� / 2.�񸶸� / 3.�� / 4.���� / 5.�ǰ��� / 6.�ߵ� / 7. ��ȯ�� / 8. ����) : ");
	scanf_s("%d", &Status);
	printf("\n\n");


	// ���� �ο� if��
	if (Status == 1)
	{
		Status = 0;
		Status |= HUNGRY;
		HP -= 20;
		printf("������� ���¸� �ο� �߽��ϴ�. (- HP 20) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else if (Status == 2)
	{
		Status = 0;
		Status |= THIRSTY;
		HP -= 20;
		printf("���񸶸� ���¸� �ο� �߽��ϴ�. (- HP 20) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else if (Status == 3)
	{
		Status = 0;
		Status |= HOT;
		HP -= 20;
		printf("���� ���¸� �ο� �߽��ϴ�. (- HP 20) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else if (Status == 4)
	{
		Status = 0;
		Status |= COLD;
		HP -= 20;
		printf("������ ���¸� �ο� �߽��ϴ�. (- HP 20) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else if (Status == 5)
	{
		Status = 0;
		Status |= TIRED;
		HP -= 20;
		printf("���ǰ��� ���¸� �ο� �߽��ϴ�. (- HP 20) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else if (Status == 6)
	{
		Status = 0;
		Status |= POISON;
		HP -= 60;
		printf("���ߵ� ���¸� �ο� �߽��ϴ�. (- HP 20) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else if (Status == 7)
	{
		Status = 0;
		Status |= TOTAL_CRISIS;
		HP -= 60;
		printf("����ȯ�� ���¸� �ο� �߽��ϴ�. (- HP 60) \n");
		printf("������ ü���� %d �Դϴ�. \n", HP);
	}
	else
	{
		printf("�����α׷��� �����մϴ�. \n\n\n");
		break;
	}

	
	// ���� ���� if��
	printf("Q. ������ ���� �Ͻðڽ��ϱ�? ( 1. YES / 2. NO ) : ");
	scanf_s("%d",&Check);
	printf("\n\n");
	if (Check == 1)
	{
		if (Status & HUNGRY)
		{
			Status &= ~HUNGRY;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� ����� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
		else if (Status & THIRSTY)
		{
			Status &= ~THIRSTY;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� �񸶸� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
		else if (Status & HOT)
		{
			Status &= ~HOT;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� �� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
		else if (Status & COLD)
		{
			Status &= ~COLD;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� ���� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
		else if (Status & TIRED)
		{
			Status &= ~TIRED;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� �ǰ��� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
		else if (Status & POISON)
		{
			Status &= ~POISON;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� �ߵ� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
		else
		{
			Status &= ~TOTAL_CRISIS;
			HP += 30;
			printf("������ ���� �߽��ϴ�.\n");
			printf("+HP 30 ȸ���� ��ȯ�� ���¸� �����մϴ�.\n");
			printf("���� HP�� %d �Դϴ�.\n", HP);
			printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
		}
	}
	else
	{
		printf("������ �������� �ʾҽ��ϴ�.\n");
		printf("���� ȭ������ ���ư��ϴ�.\n\n\n");
	}
	}
	return 0;
}