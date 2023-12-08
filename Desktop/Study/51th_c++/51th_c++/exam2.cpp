#include<stdio.h>

int main()
{
	int num[4] = { 5, 2, 4, 6 };
	int Null = 0;

for(int j = 0; j < 3; ++j)
{
	int check = 0;
	for (int i = 0; i < 3 - j; ++i)
	{
		if (num[i] > num[i + 1])
		{
			Null = num[i];
			num[i] = num[i + 1];
			num[i + 1] = Null;
			check++;
		}
	}
	if (check == 0)
		break;
	
}

	//for (int k = 0; k < 4; ++k)
	//{
	//	printf("%d \n", num[k]);
	//}

	return 0;
}