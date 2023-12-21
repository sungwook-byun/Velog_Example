#include <iostream>

class MyClass
{
	// 클래스는 아무것도 명시하지 않으면 private 필드가 기본
private:
	float		m_f;
	long long	m_ll;

public:
	// 생성자가 1개 이상 존재하면, 컴파일러는 기본생성자를 만들어주지 않는다.
	MyClass(float _f)
		: m_f(_f)
		, m_ll(0)
	{}

	~MyClass()
	{}
};

int main()
{
	// 기본 생성자가 없기 때문에, 존재하지 않는 함수를 호출하려고 해서 컴파일러 에러
//	MyClass a;
	MyClass a(10.f);


	return 0;
}