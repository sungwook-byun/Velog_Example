#include<stdio.h>
#include<cstdlib>
#include<ctime>

#define Size 6

void Insertion_Sort(int* _Random_Arr, int _ElementCoust)
{
	int i, j, temp = 0;

	// 0��° ���� ������ �Ǿ��ִٰ� ���� ù��° ������ ������
	for (i = 1; i < Size; ++i) {
		temp = _Random_Arr[i]; // [1]���� Temp�� �켱 ������ ��
		for (j = i; j > 0 && _Random_Arr[j - 1] > temp; --j)  // [0]�� ���� [1]���� ū���� ���ϰ� ũ�ٸ� for���� ����
		{
			_Random_Arr[j] = _Random_Arr[j - 1]; // [1]�� ���� [0]�� �о �־����
		}
		_Random_Arr[j] = temp; // --�� ���� j�� �����ϰ� [0]�� Temp�ȿ� ����Ǿ��ִ� ���� ������ [1]�� �־���
	} 
}

int main()
{
	int _Random_Arr[Size] = {};
	int Temp = 0;

	// �迭 ���� �߻�
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


	// ��¿�
	printf("���� �� : ");
	for(int i = 0; i < Size; ++i)
	{
		printf("%d   ", _Random_Arr[i]);
	}

	printf("\n\n");

	Insertion_Sort(_Random_Arr, Size);

	printf("���� �� : ");
	for (int i = 0; i < Size; ++i)
	{
		printf("%d  ", _Random_Arr[i]);
	}
	return 0;
}