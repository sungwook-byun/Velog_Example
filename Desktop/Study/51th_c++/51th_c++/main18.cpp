#include <iostream>

// ������ �����ε�
class String
{
private:
	char* m_pStr;			// ���ڿ��� �ּ�
	int		m_MaxLength;	// ���ڿ��� ������ �� �ִ� �ִ� ����
	int		m_Length;		// ���ڿ��� ����

public:
	int Length()
	{
		return m_Length;
	}

	const char* GetStr()
	{
		return m_pStr;
	}


	// ������ �����ε�
public:
	// ���� ������
	void operator= (const char* _str)
	{

	}

	// ���� ������
	String operator+ (String _string)
	{
		return String();
	}

	// += ������
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

	// ���ڿ��� �ּ�
	// �������� �ڷ����� const char* Ÿ�� ���� �����Ѵ�.
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