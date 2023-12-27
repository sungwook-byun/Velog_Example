#include <iostream>

#include "CArr.h"

#include <vector>
using std::vector;

class MyClass
{
private:
	int	m_i;

public:
	// 포함 클래스(Inner Class)
	// 포함 클래스가 선언된 클래스(MyClass) 의 private 까지 접근할 수 있다.
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