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

// B 클래스는 A 클래스를 상속받았다.
// B 클래스는 A 클래스로부터 파생되었다.
class B : public A
{
protected: // 외부 공개 x(private), 파생 클래스(자식 클래스) 에는 접근 허용
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

// C 클래스는 B 클래스를 상속받았다.
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
	// 상속
	// 다형성
	// 추상화

	// 상속
	// 부모에 구현되어있는 기능을 물려받음
	// 추가적인 구현을 더하기 위해서
	// 코드 재사용

	A a; // 4  바이트
	B b; // 8  바이트
	C c; // 12 바이트

	a.SetA(10);
	b.SetA(20);
	c.SetA(30);

	b.SetB(10);
	c.SetB(10);

	c.SetC(10);




	return 0;
}