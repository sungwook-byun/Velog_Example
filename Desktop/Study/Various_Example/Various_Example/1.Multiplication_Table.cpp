#include <stdio.h>

int main()
{
	int First_Num = 0;
	int Last_Num = 0;
	int Result_Num = 0;

	//��º�
	printf("  �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� \n");
	printf("��       �ѤѤ�         �ѤѤ�          �ѤѤ�  ��        ��\n");
	printf("��            ��             ��        ��       ��        ��\n");
	printf("��            ��             ��        ��       �ӤѤѤ�  ��\n");
	printf("��      �ѤѤѤѤ�     �ѤѤѤѤ�       �ѤѤ�  ��        ��\n");
	printf("��          ��             ��             ��              ��\n");
	printf("��          ��             ��             ��              ��\n");
	printf("��                                         �ѤѤ�         ��\n");
	printf("  �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ� \n");
	printf("\n\n\n");

	//����º�
	printf("	����� ���� �Է��� �ּ��� : ");
	scanf_s("%d", &First_Num);
	printf("	����� ���� �Է��� �ּ��� : ");
	scanf_s("%d", &Last_Num);
	printf("\n\n\n");
	
	//�ݺ���
	for (int i = 1; i <= Last_Num; ++i)
	{
		Result_Num = First_Num * i;
		printf("	%d	*	%d	=	%d	\n", First_Num, i, Result_Num);
	}
	printf("\n\n\n\n\n\n\n");

	return 0;
}