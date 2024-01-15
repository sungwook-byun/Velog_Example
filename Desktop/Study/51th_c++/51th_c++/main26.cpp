#pragma once

#include <iostream>

using std::cout;
using std::wcout;
using std::endl;

using std::cin;

// printf, scanf -> cout, cin

class MyOStream
{

public:
	MyOStream& operator << (const wchar_t* _str)
	{
		wprintf_s(L"%s", _str);
		return (*this);
	}

	void operator << (void(*_pFunc)(void))
	{
		_pFunc();
	}

};

MyOStream mycout;

void MyEndL()
{
	printf("\n");
}

int Test(int _a, int _b)
{
	return _a + _b;
}

class MyIStream
{
public:
	void operator >> (int& _input)
	{
		scanf_s("%d", &_input);
	}
};

MyIStream MyCin;


int main()
{
	int i = 1;
	i <<= 2;

	mycout << L"Output" << L"  Output" << L" Test" << MyEndL;

	// 함수 포인터
	void(*pFunc)(void) = &MyEndL;
	int(*pFunc1)(int, int) = &Test;

	pFunc();
	pFunc1(10, 20);

	cout << "Output" << endl;
	wcout << L"Output" << L"  Add" << endl;

	int input = 0;
	MyCin >> input;

	cin >> input;


	return 0;
}
