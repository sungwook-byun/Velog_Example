#include<stdio.h>
#include<cstdlib>
#include<ctime>

#define Size 6

// {5, 4, 3, 2, 6, 1}
void Insertion_Sort(int* _Random_Arr, int _ElementCoust)
{
	int i, j, temp = 0;

	for (i = 1; i < Size; i++) {
		temp = _Random_Arr[i];

		for (j = i; j > 0 && _Random_Arr[j - 1] > temp; j--)
		{
			_Random_Arr[j] = _Random_Arr[j - 1];
		}
		_Random_Arr[j] = temp;
	}

}

int main()
{
	int _Random_Arr[Size] = {120,99,1,2,88,3};
	int Temp = 0;
	//	int Check = 0;


	// 출력용
	printf("정렬 전 : ");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d   ", _Random_Arr[i]);
	}

	printf("\n\n");

	Insertion_Sort(_Random_Arr, Size);

	printf("정렬 후 : ");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d   ", _Random_Arr[i]);
	}




	return 0;
}