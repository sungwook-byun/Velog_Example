#include <stdio.h>

int main()
{
	int First_Num = 0;
	int Last_Num = 0;
	int Result_Num = 0;

	//출력부
	printf("  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("ㅣ       ㅡㅡㅡ         ㅡㅡㅡ          ㅡㅡㅡ  ㅣ        ㅣ\n");
	printf("ㅣ            ㅣ             ㅣ        ㅣ       ㅣ        ㅣ\n");
	printf("ㅣ            ㅣ             ㅣ        ㅣ       ㅣㅡㅡㅡ  ㅣ\n");
	printf("ㅣ      ㅡㅡㅡㅡㅡ     ㅡㅡㅡㅡㅡ       ㅡㅡㅡ  ㅣ        ㅣ\n");
	printf("ㅣ          ㅣ             ㅣ             ㅣ              ㅣ\n");
	printf("ㅣ          ㅣ             ㅣ             ㅣ              ㅣ\n");
	printf("ㅣ                                         ㅡㅡㅡ         ㅣ\n");
	printf("  ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ \n");
	printf("\n\n\n");

	//입출력부
	printf("	출력할 행을 입력해 주세요 : ");
	scanf_s("%d", &First_Num);
	printf("	출력할 열을 입력해 주세요 : ");
	scanf_s("%d", &Last_Num);
	printf("\n\n\n");
	
	//반복문
	for (int i = 1; i <= Last_Num; ++i)
	{
		Result_Num = First_Num * i;
		printf("	%d	*	%d	=	%d	\n", First_Num, i, Result_Num);
	}
	printf("\n\n\n\n\n\n\n");

	return 0;
}