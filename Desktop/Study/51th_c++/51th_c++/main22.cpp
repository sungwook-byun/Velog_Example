#include <iostream>

#include "CArr.h"

#include <vector>
using std::vector;

class MyClass
{
private:
	int	m_i;

public:
	// ���� Ŭ����(Inner Class)
	// ���� Ŭ������ ����� Ŭ����(MyClass) �� private ���� ������ �� �ִ�.
	class Inner
	{
	private:
		float m_f;
	};
};

int main()
{
	int size = 0;

	MyClass c;
	size = sizeof(MyClass);

	MyClass::Inner in;
	size = sizeof(MyClass::Inner);


	CArr<float> arrFloat;
	arrFloat.push_back(1.f);
	arrFloat.push_back(2.f);

	CArr<float>::iterator iter;
	iter = arrFloat.begin();


	return 0;
}