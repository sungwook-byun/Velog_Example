#include <stdio.h>


// 함수 오버로딩
// 함수의 이름은 같지만, 함수의 인자 개수 or 타입이 달라서 구별할수 있는 여지가 있는 경우에
// 동일한 함수 이름으로 여러개의 함수를 만들 수 있다.
// 반환 타입만 다른경우는 오버로딩을 할 수 없다.
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






// C 스타일 방식
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
// 클래스 추가
// 생성자, 소멸자
// 맴버 함수
// 연산자 오버로딩(추가구현)
// 상속, 다형성, 추상화

// 객체지향
// 캡슐, 은닉성
// 상속, 다형성, 추상화

class Test
{
	//접근 제한 지정자
	//private:
	//protected:
	//public:

private:
	int		m_i;
	float	m_f;

	// 맴버함수, 해당 클래스의 객체를 통해서 호출 됨
public:
	void SetInt(int _a)
	{
		// 맴버함수 안에는 자동으로 만들어지는 지역변수 this 포인터가 존재한다.		
		// this 포인터 변수에는 해당 맴버함수를 호출시킨 객체의 주소가 들어온다.
		// 맴버함수 안에서 지칭하는 맴버 변수는 앞에 this-> 가 생략되어있다.
		this->m_i = _a;
	}

	void SetFloat(float _f)
	{
		this->m_f = _f;
	}

	// 생성자, 소멸자 는 둘다 맴버함수
	// 생성자는 객체가 생성될 때 호출된다.
	// 소멸자는 객체가 소멸할 때 호출된다.
	// 생성자 or 소멸자를 구현해 놓지 않으면 위 규칙을 지키기 위해서
	// 아무 일도 하지않는 기본 생성자, 기본 소멸자를 구현하며 구현내용은 다음과 같다.
	Test()
		: m_i(0) // 생성자 맴버 이니셜라이저
		, m_f(0.f)
	{
		// 대입
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
	// 맴버를 private 필드에 선언했기 때문에, 직접적으로 수정하는 것이 불가능하다.
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