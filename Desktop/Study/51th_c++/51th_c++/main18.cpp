#include <iostream>

// 연산자 오버로딩
class String
{
private:
	char* m_pStr;			// 문자열의 주소
	int		m_MaxLength;	// 문자열을 저장할 수 있는 최대 길이
	int		m_Length;		// 문자열의 길이

public:
	int Length()
	{
		return m_Length;
	}

	const char* GetStr()
	{
		return m_pStr;
	}


	// 연산자 오버로딩
public:
	// 대입 연산자
	void operator= (const char* _str)
	{

	}

	// 덧셈 연산자
	String operator+ (String _string)
	{
		return String();
	}

	// += 연산자
	void operator +=(const char* _Str)
	{

	}




public:
	String()
		: m_pStr(nullptr)
		, m_MaxLength(10)
		, m_Length(0)
	{
		m_pStr = (char*)malloc(sizeof(char) * (m_MaxLength + 1));
	}

	~String()
	{
		if (nullptr != m_pStr)
			free(m_pStr);
	}
};



int main()
{
	String str;

	// 문자열은 주소
	// 내가만든 자료형에 const char* 타입 값을 대입한다.
	// str.String::operator=("abcdef");
	str = "abcdef";

	String str1;
	String str2;
	String str3 = str1 + str2; //str1.String::operator+(str2);

	int a = 0;
	a = 10;



	String s1;
	s1 = "abcd";


	String s2;
	s2 = "efgh";

	String s3;
	s3 = s1 + s2;
	s3 += "hijkl";



	return 0;
}