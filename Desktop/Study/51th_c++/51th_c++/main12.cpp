#include<stdio.h>


int main()
{
	short arrData[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int* pData = (int*)arrData;
	
	pData += 2;

	int Value = *((short*)pData);

	{
		char data[2] = { 2, 2 };

		short* pData = (short*)data;

		Value = *pData;

	}

	return 0;
}