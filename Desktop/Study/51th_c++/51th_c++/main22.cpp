#include <iostream>

#include "CArr.h"

#include <vector>
using std::vector;

using std::cout;
using std::endl;
using std::cin;


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
	arrFloat.push_back(1.1f);
	arrFloat.push_back(2.2f);
	arrFloat.push_back(3.3f);

	CArr<float>::iterator iter;
	iter = arrFloat.begin();

	/*float data = (*iter);
	*iter = 3.3f;
	data = *iter;*/

	iter = arrFloat.begin();
	for (; iter != arrFloat.end(); ++iter)
	{
		cout << *iter << endl;
	}
	return 0;
}