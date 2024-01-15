#include <iostream>

using std::cout;
using std::endl;

class A
{
protected:
	int m_A;
public:
	void SetA(int _a) { m_A = _a; }
public:
	A()
		: m_A(0)
	{}

	A(int _A)
		: m_A(_A)
	{

	}

	~A()
	{
		cout << "A Class Destruction" << endl;
	}
};

// B Ŭ������ A Ŭ������ ��ӹ޾Ҵ�.
// B Ŭ������ A Ŭ�����κ��� �Ļ��Ǿ���.
class B : public A
{
private: // �ܺ� ���� x(private), �Ļ� Ŭ����(�ڽ� Ŭ����) ���� ���� ���
	int m_B;

public:
	void SetB(int _b)
	{
		m_B = _b;
	}

	int GetB()
	{
		return m_B;
	}
public:

	B()
		: m_B(0)
	{}

	B(int _A, int _B)
		: A(_A)
		, m_B(_B)
	{}

	~B()
	{
		cout << "B Class Destruction" << endl;

	}
};

// C Ŭ������ B Ŭ������ ��ӹ޾Ҵ�.
class C : public B
{
private:
	int m_C;

public:
	void SetC(int _c)
	{
		m_A = _c;
		//m_B = _c;
		m_C = _c;
	}

public:
	//C() 
	//	: m_A(0), m_B(0), m_C(0) // �ʱ�ȭ�ÿ��� �ش� Ŭ���� �ɹ��� ����
	//{
	//	m_A = 0; // m_A �� A Ŭ�������� protected
	//	m_B = 0; // m_B �� B Ŭ�������� private
	//	m_C = 0;
	//}
	C()
		: m_C(0)
	{}

	C(int _A, int _B, int _C)
		: B(_A, _B)
		, m_C(_C)
	{}

	~C()
	{
		cout << "C Class Destruction" << endl;
	}
};

int main()
{
	// ���
	// ������
	// �߻�ȭ

	// ���
	// �θ� �����Ǿ��ִ� ����� ��������
	// �߰����� ������ ���ϱ� ���ؼ�
	// �ڵ� ����

	// ��ü�� ������ �� �����ڰ� ȣ��ȴ�.
	// ��Ӱ��迡���� �� Ŭ������ ������ �ɹ��� �ʱ�ȭ�� �Ű澴��.
	// �ڽ� Ŭ������ �θ���Ʈ�� �ʱ�ȭ�� �θ�Ŭ������ �����ڸ� Ȱ���Ѵ�.
	// �ڽ�Ŭ�������� �θ�Ŭ������ �����ڿ� ���� ��ô� ���� ������ 
	// �θ�Ŭ������ �⺻ �����ڸ� ȣ���ϰ� �ȴ�(������)

	// ȣ���� �ڽ�Ŭ������ �����ں��� �θ� ������ �����ϵ�
	// �ʱ�ȭ ������ �θ�Ŭ�������� �ڽ�Ŭ���� ������ �����

	//A a; // 4  ����Ʈ
	//B b; // 8  ����Ʈ
	//C c; // 12 ����Ʈ

	//a.SetA(10);
	//b.SetA(20);
	//c.SetA(30);

	//b.SetB(10);
	//c.SetB(10);

	//c.SetC(10);

	//A a1(10);
	//B b1(10, 20);
	C c1(10, 20, 30);

	int size = 0;
	//size = sizeof(a1);
	//size = sizeof(b1);
	size = sizeof(c1);

	return 0;
}