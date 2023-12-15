#include < stdio.h>

// 삽입 정렬

// 버블소트
void BubbleSort(int* _Data, int _ElementCoust)
{
	for (int j = 0; j < _ElementCoust; ++j)
	{
		bool bChange = false;

		for(int i = 0; i < _ElementCoust - 1 - j; ++i)
			{
			if(_Data[i] > _Data[i + 1])
			{
				int Temp = _Data[i];
				_Data[i] = _Data[i + 1];
				_Data[i + 1] = Temp;
				bChange = true;
			}
			if (bChange == false)
			{
				break;
			}
		}
	}

}


int main()
{

	int Data[5] = { 27, 3, 99, 45, 94 };


	BubbleSort(Data, 5);

	return 0;
}