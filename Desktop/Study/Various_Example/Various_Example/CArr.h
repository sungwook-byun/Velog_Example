#pragma once


class CArr
{
private:
	int* Data;
	int CurCount;
	int MaxSize;

	void realloc();



public:
	CArr();
	~CArr();

	void Push(int pData);

	int size()
	{
		return CurCount;
	}
	int max_size()
	{
		return MaxSize;
	}
	int at(int arr) 
	{
		return Data[arr]; 
	}
	int& operator[](int _arr)
	{
		return Data[_arr];
	}



};

