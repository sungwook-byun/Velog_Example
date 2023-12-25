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

private:
	void Realloc()
	{
		// 수용 공간을 2배로 확장하기
		m_MaxLength *= 2.f;

		// 새로운 공간을 만들어낸다.
		char* pNew = (char*)malloc(sizeof(char) * m_MaxLength);

		// 원래 있던 데이터를 새로운곳으로 옮긴다.
		for (int i = 0; i < m_Length; ++i)
		{
			pNew[i] = m_pStr[i];
		}
		pNew[m_Length] = '\0';

		// 기존 공간을 해제한다.
		free(m_pStr);

		// 새로운 공간을 가리킨다.
		m_pStr = pNew;
	}

	// 연산자 오버로딩
public:
	// 대입 연산자
	void operator = (const char* _str)
	{
		// 입력되려는 문자열의 문자 개수(길이) 파악
		int len = 0;
		while ('\0' != _str[len]) { ++len; }

		// 입력되려는 문자열의 길이가 최대 수용개수를 넘어서면 저장 공간 확장
		while (m_MaxLength < len)
		{
			Realloc();
		}

		// 입력 문자열의 값을, 힙 공간으로 하나씩 옮기기
		int i = 0;
		for (; i < len; ++i)
		{
			m_pStr[i] = _str[i];
		}

		// 마지막에 널문자로 막기
		m_pStr[i] = '\0';

		// 문자열 길이 갱신(입력된 문자열 길이로)
		m_Length = len;
	}

	// 덧셈 연산자
	String operator+ (const String& _string)
	{
		String strNew;
		strNew = this->m_pStr;
		strNew += _string.m_pStr;

		return strNew;
	}

	String operator+ (const char* _Str)
	{
		String strNew;
		return strNew;
	}

	// += 연산자
	void operator +=(const char* _Str)
	{
		// 뒤에 붙을 문자열의 문자 개수(길이) 파악
		int len = 0;
		while ('\0' != _Str[len]) { ++len; }

		// 원래 문자열 길이 + 새로 뒤에 붙을 문자열의 길이가 최대 저장 크기를 벗어나는지 확인
		while (m_MaxLength < m_Length + len)
		{
			Realloc();
		}

		// 뒤에붙을 문자열을 가져오기
		for (int i = 0; i < len; ++i)
		{
			m_pStr[i + m_Length] = _Str[i];
		}

		// 저장하고 있는 문자열 길이 갱신
		m_Length += len;
		m_pStr[m_Length] = '\0';
	}





public:
	String()
		: m_pStr(nullptr)
		, m_MaxLength(10)
		, m_Length(0)
	{
		m_pStr = (char*)malloc(sizeof(char) * (m_MaxLength + 1));
	}

	String(const char* _str)
		: m_pStr(nullptr)
		, m_MaxLength(10)
		, m_Length(0)
	{
		m_pStr = (char*)malloc(sizeof(char) * (m_MaxLength + 1));

		(*this) = _str;
	}

	~String()
	{
		if (nullptr != m_pStr)
			free(m_pStr);
	}
};

class CQuest
{
private:
	int m_i;

public:
	void operator =(int i)
	{
		m_i = i;
		printf("대입 연산자\n");
	}

public:
	CQuest()
		: m_i(0)
	{
		printf("기본 생성자\n");
	}

	CQuest(int i)
		: m_i(i)
	{
		printf("생성자 호출\n");
	}
};



int main()
{
	String str1;
	str1 = "abc";
	str1 += "kkk";

	String str2 = "gh";
	String str3 = str1 + str2;

	printf("%s\n", str3.GetStr());

	// 객체 생성과 동시에 대입이 발생하면 
	// 컴파일러는 생성자 한번으로 문제를 해결하려고 한다.
	// 따라서 대입 연산자를 호출했을 때랑 동일한 형태의 생성자를 준비해서 
	// 똑같은 동작을 수행할 수 있도록 한다.
	String str4 = "hello";
	CQuest q1;
	CQuest q2 = 10;

	return 0;
}