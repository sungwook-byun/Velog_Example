#include<stdio.h>
#include<cstdlib>
#include<ctime>

#define Size 6

void Insertion_Sort(int* _Random_Arr, int _ElementCoust)
{
	int i, j, temp = 0;

	// 0번째 값은 정렬이 되어있다고 보고 첫번째 값부터 시작함
	for (i = 1; i < Size; ++i) {
		temp = _Random_Arr[i]; // [1]값을 Temp에 우선 저장을 함
		for (j = i; j > 0 && _Random_Arr[j - 1] > temp; --j)  // [0]의 값이 [1]보다 큰지를 비교하고 크다면 for문을 돌림
		{
			_Random_Arr[j] = _Random_Arr[j - 1]; // [1]의 값에 [0]을 밀어서 넣어버림
		}
		_Random_Arr[j] = temp; // --로 인해 j가 감소하고 [0]에 Temp안에 저장되어있던 값인 최초의 [1]을 넣어줌
	} 
}

int main()
{
	int _Random_Arr[Size] = {};
	int Temp = 0;

	// 배열 난수 발생
	srand((int)time(NULL));
	for (int i = 0; i < Size; ++i)
	{
		_Random_Arr[i] = rand() % 100 + 1;
		for (int j = 0; j < i; ++j)
		{
			if (_Random_Arr[i] == _Random_Arr[j])
				--i;
		}
	}


	// 출력용
	printf("정렬 전 : ");
	for(int i = 0; i < Size; ++i)
	{
		printf("%d   ", _Random_Arr[i]);
	}

	printf("\n\n");

	Insertion_Sort(_Random_Arr, Size);

	printf("정렬 후 : ");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d  ", _Random_Arr[i]);
	}
	return 0;
}