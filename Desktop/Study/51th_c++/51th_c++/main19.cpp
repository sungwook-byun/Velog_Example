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

private:
	void Realloc()
	{
		// ���� ������ 2��� Ȯ���ϱ�
		m_MaxLength *= 2.f;

		// ���ο� ������ ������.
		char* pNew = (char*)malloc(sizeof(char) * m_MaxLength);

		// ���� �ִ� �����͸� ���ο������ �ű��.
		for (int i = 0; i < m_Length; ++i)
		{
			pNew[i] = m_pStr[i];
		}
		pNew[m_Length] = '\0';

		// ���� ������ �����Ѵ�.
		free(m_pStr);

		// ���ο� ������ ����Ų��.
		m_pStr = pNew;
	}

	// ������ �����ε�
public:
	// ���� ������
	void operator = (const char* _str)
	{
		// �ԷµǷ��� ���ڿ��� ���� ����(����) �ľ�
		int len = 0;
		while ('\0' != _str[len]) { ++len; }

		// �ԷµǷ��� ���ڿ��� ���̰� �ִ� ���밳���� �Ѿ�� ���� ���� Ȯ��
		while (m_MaxLength < len)
		{
			Realloc();
		}

		// �Է� ���ڿ��� ����, �� �������� �ϳ��� �ű��
		int i = 0;
		for (; i < len; ++i)
		{
			m_pStr[i] = _str[i];
		}

		// �������� �ι��ڷ� ����
		m_pStr[i] = '\0';

		// ���ڿ� ���� ����(�Էµ� ���ڿ� ���̷�)
		m_Length = len;
	}

	// ���� ������
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

	// += ������
	void operator +=(const char* _Str)
	{
		// �ڿ� ���� ���ڿ��� ���� ����(����) �ľ�
		int len = 0;
		while ('\0' != _Str[len]) { ++len; }

		// ���� ���ڿ� ���� + ���� �ڿ� ���� ���ڿ��� ���̰� �ִ� ���� ũ�⸦ ������� Ȯ��
		while (m_MaxLength < m_Length + len)
		{
			Realloc();
		}

		// �ڿ����� ���ڿ��� ��������
		for (int i = 0; i < len; ++i)
		{
			m_pStr[i + m_Length] = _Str[i];
		}

		// �����ϰ� �ִ� ���ڿ� ���� ����
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
		printf("���� ������\n");
	}

public:
	CQuest()
		: m_i(0)
	{
		printf("�⺻ ������\n");
	}

	CQuest(int i)
		: m_i(i)
	{
		printf("������ ȣ��\n");
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

	// ��ü ������ ���ÿ� ������ �߻��ϸ� 
	// �����Ϸ��� ������ �ѹ����� ������ �ذ��Ϸ��� �Ѵ�.
	// ���� ���� �����ڸ� ȣ������ ���� ������ ������ �����ڸ� �غ��ؼ� 
	// �Ȱ��� ������ ������ �� �ֵ��� �Ѵ�.
	String str4 = "hello";
	CQuest q1;
	CQuest q2 = 10;

	return 0;
}