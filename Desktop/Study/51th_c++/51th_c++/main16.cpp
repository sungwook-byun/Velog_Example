#include <stdio.h>


// �Լ� �����ε�
// �Լ��� �̸��� ������, �Լ��� ���� ���� or Ÿ���� �޶� �����Ҽ� �ִ� ������ �ִ� ��쿡
// ������ �Լ� �̸����� �������� �Լ��� ���� �� �ִ�.
// ��ȯ Ÿ�Ը� �ٸ����� �����ε��� �� �� ����.
int Add(int a, int b)
{
	return a + b;
}

float Add(float f1, float f2)
{
	return f1 + f2;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}






// C ��Ÿ�� ���
typedef int INT;
typedef struct tagMyStruct
{
	int a;
}tMyStruct;

typedef struct MyType
{
	int a;
}MYTYPE;


// C++
// Ŭ���� �߰�
// ������, �Ҹ���
// �ɹ� �Լ�
// ������ �����ε�(�߰�����)
// ���, ������, �߻�ȭ

// ��ü����
// ĸ��, ���м�
// ���, ������, �߻�ȭ

class Test
{
	//���� ���� ������
	//private:
	//protected:
	//public:

private:
	int		m_i;
	float	m_f;

	// �ɹ��Լ�, �ش� Ŭ������ ��ü�� ���ؼ� ȣ�� ��
public:
	void SetInt(int _a)
	{
		// �ɹ��Լ� �ȿ��� �ڵ����� ��������� �������� this �����Ͱ� �����Ѵ�.		
		// this ������ �������� �ش� �ɹ��Լ��� ȣ���Ų ��ü�� �ּҰ� ���´�.
		// �ɹ��Լ� �ȿ��� ��Ī�ϴ� �ɹ� ������ �տ� this-> �� �����Ǿ��ִ�.
		this->m_i = _a;
	}

	void SetFloat(float _f)
	{
		this->m_f = _f;
	}

	// ������, �Ҹ��� �� �Ѵ� �ɹ��Լ�
	// �����ڴ� ��ü�� ������ �� ȣ��ȴ�.
	// �Ҹ��ڴ� ��ü�� �Ҹ��� �� ȣ��ȴ�.
	// ������ or �Ҹ��ڸ� ������ ���� ������ �� ��Ģ�� ��Ű�� ���ؼ�
	// �ƹ� �ϵ� �����ʴ� �⺻ ������, �⺻ �Ҹ��ڸ� �����ϸ� ���������� ������ ����.
	Test()
		: m_i(0) // ������ �ɹ� �̴ϼȶ�����
		, m_f(0.f)
	{
		// ����
		//m_i = 0;
		//m_f = 0.f;
	}

	Test(int _i)
		: m_i(_i)
		, m_f(0.f)
	{

	}

	Test(int _i, float _f)
		: m_i(_i)
		, m_f(_f)
	{

	}


	~Test()
	{

	}
};


int main()
{
	// �ɹ��� private �ʵ忡 �����߱� ������, ���������� �����ϴ� ���� �Ұ����ϴ�.
	//Test b = {};
	//b.m_i = 10;
	//b.m_f = 10.f;
	Test a;
	a.SetInt(10);
	a.SetFloat(10.f);

	Test b;
	b.SetInt(200);



	return 0;
}