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

// B 클래스는 A 클래스를 상속받았다.
// B 클래스는 A 클래스로부터 파생되었다.
class B : public A
{
private: // 외부 공개 x(private), 파생 클래스(자식 클래스) 에는 접근 허용
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

// C 클래스는 B 클래스를 상속받았다.
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
	//	: m_A(0), m_B(0), m_C(0) // 초기화시에는 해당 클래스 맴버만 가능
	//{
	//	m_A = 0; // m_A 는 A 클래스에서 protected
	//	m_B = 0; // m_B 는 B 클래스에서 private
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
	// 상속
	// 다형성
	// 추상화

	// 상속
	// 부모에 구현되어있는 기능을 물려받음
	// 추가적인 구현을 더하기 위해서
	// 코드 재사용

	// 객체가 생성될 때 생상자가 호출된다.
	// 상속관계에서는 각 클래스는 본인의 맴버의 초기화만 신경쓴다.
	// 자식 클래스가 부모파트의 초기화를 부모클래스의 생성자를 활용한다.
	// 자식클래스에서 부모클래스의 생성자에 대한 명시다 따로 없으면 
	// 부모클래스의 기본 생성자를 호출하게 된다(생략됨)

	// 호출은 자식클래스의 생성자부터 부모 순서로 진행하되
	// 초기화 순서는 부모클래스에서 자식클래스 순서로 진행됨

	//A a; // 4  바이트
	//B b; // 8  바이트
	//C c; // 12 바이트

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