#include<stdio.h>
#include<cstdlib>
#include<ctime>
 
// �ζ��� ���ǹ�ȣ�� 6���ϱ� 6���� ����
#define Size 6

int main()
{
	int Lotto[Size] = {};

	int Winning_Number[Size] = {14 ,33 ,34 ,35 ,37 ,40 }; // �ζ� 1097ȸ ��÷��ȣ
	int Winning_Bonus = 4; // �ζ� 1097ȸ ���ʽ� ��÷��ȣ
	int Null = 0;
	int Accumulate_Num = 0;

//	int Num_Size = sizeof(Lotto) / sizeof(int); // Lotto�� ��� 4����Ʈ ������ 6�� ��������� 24�� ���ð��̰� int�� 4����Ʈ�ϱ� ������� 6�� ����

	// ������ �߻���Ŵ
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
	// 6�� ������ ���̸� ���ϴ°��̱� ������ Size���� 1�� �������
	for(int j = 0; j < Size - 1; ++j)
	{
		bool Check = true;
		// ���������� ���� ���� ���� for���� ���� 1�� ���� �ư�, ��� 1�� �����Ǵ� ������ �����ؾ� �ϱ� ������ -i�� ����
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

	// ���ʽ� ��ȣ Ȯ��
	for (int i = 0; i < Size; ++i)
	{
		if (Lotto[i] == Winning_Bonus)
		{
			++Accumulate_Num;
			break;
		}
	}

	// ��÷ ���� Ȯ��
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



// ��º�
	printf("-----------------------------------------------------------------------\n");
	printf("���ζ� 1097ȸ�� ��÷��ȣ�� 14 ,33 ,34 ,35 ,37 ,40    ���ʽ� ��ȣ : 4��\n");
	printf("-----------------------------------------------------------------------\n\n\n");
	
	
	printf("���� ���� ��ȣ : ");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d    ", Lotto[i]);
	}
	printf("\n\n\n\n");

	if (Accumulate_Num == 6)
	{
		printf("��*********** 1 �� ***********��\n");
		printf("�ζ� 1097ȸ�� 1� ��÷�Ǽ̽��ϴ�!\n");
	}
	else if (Accumulate_Num == 5)
	{
		printf("��*********** 2 �� ***********��\n");
		printf("�ζ� 1097ȸ�� 2� ��÷�Ǽ̽��ϴ�!\n");
	}
	else if (Accumulate_Num == 4)
	{
		printf("��*********** 3 �� ***********��\n");
		printf("�ζ� 1097ȸ�� 3� ��÷�Ǽ̽��ϴ�!\n");
	}
	else if (Accumulate_Num == 3 )
	{
		printf("��*********** 4 �� ***********��\n");
		printf("�ζ� 1097ȸ�� 4� ��÷�Ǽ̽��ϴ�!\n");		}
	else
	{
		printf("       ���� �� ÷��\n");
		if (Accumulate_Num == 2)
			printf("��2���� ���߼̽��ϴ�.��\n\n");
		else if (Accumulate_Num == 1)
			printf("��1���� ���߼̽��ϴ�.��\n\n");
		else
			printf("���ϳ��� ������ ���ϼ̽��ϴ�.��\n\n");
	}

}