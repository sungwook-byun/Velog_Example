#include <iostream>

class MyClass
{
	// Ŭ������ �ƹ��͵� ������� ������ private �ʵ尡 �⺻
private:
	float		m_f;
	long long	m_ll;

public:
	// �����ڰ� 1�� �̻� �����ϸ�, �����Ϸ��� �⺻�����ڸ� ��������� �ʴ´�.
	MyClass(float _f)
		: m_f(_f)
		, m_ll(0)
	{}

	~MyClass()
	{}
};

int main()
{
	// �⺻ �����ڰ� ���� ������, �������� �ʴ� �Լ��� ȣ���Ϸ��� �ؼ� �����Ϸ� ����
//	MyClass a;
	MyClass a(10.f);


	return 0;
}