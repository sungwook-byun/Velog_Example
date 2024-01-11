#include <iostream>


class A
{
protected:
	int m_A;

public:
	void SetA(int _a)
	{
		m_A = _a;
	}
};

// B Ŭ������ A Ŭ������ ��ӹ޾Ҵ�.
// B Ŭ������ A Ŭ�����κ��� �Ļ��Ǿ���.
class B : public A
{
protected: // �ܺ� ���� x(private), �Ļ� Ŭ����(�ڽ� Ŭ����) ���� ���� ���
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
		m_B = _c;
		m_C = _c;
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

	A a; // 4  ����Ʈ
	B b; // 8  ����Ʈ
	C c; // 12 ����Ʈ

	a.SetA(10);
	b.SetA(20);
	c.SetA(30);

	b.SetB(10);
	c.SetB(10);

	c.SetC(10);




	return 0;
}