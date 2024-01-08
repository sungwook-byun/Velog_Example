#pragma once

#include <assert.h>

// Ŭ���� ���ø�
template<typename T>
class CArr
{
private:
	T* m_pData;
	int		m_MaxCount;
	int		m_CurCount;

public:
	void push_back(const T& _Data);

	class iterator;
	iterator begin()
	{
		iterator iter(this, 0);
		return iter;
	}

	iterator end()
	{
		iterator iter(this, -1);
		return iter;
	}

private:
	void Realloc();

	// ����� �ɹ��Լ��� ���� �� ���
	// �ζ��� �Լ��� ó��	
	// ����� ���� ������ �����ν�, ȣ��� �ش� ������ �״�� �����Ѵ�.
	// ��ũ�� �Լ��� ����, �Լ� ȣ�� �� ������ ���� ���� ���� ����� ����.

	// �ζ��� �Լ��� �����ϴ� ��� �߻��ϴ� ����.
	// �Լ� ������ �������� ȣ���ϴ� ������ ����Ǿ �ڵ��� ���� ��û���� �þ �� �ִ�.

	// �ζ��� ó���� �� �Լ����� Ư¡.
	// ������ ª��(����� �����Ѵ�, Get, Set ������ �Լ�)
	// ���� ȣ�� �Ǵ� �Լ�
public:
	int size() { return m_CurCount; }
	int capacity() { return m_MaxCount; }
	T at(int _Idx) { return m_pData[_Idx]; }

	// ��ȯŸ���� �������·� ��ȯ, ��ȯ�� ���� �����ϸ� �������� �����Ǵ� ����
	T& operator[](int _Idx) { return m_pData[_Idx]; }


public:
	CArr();
	~CArr();

	// 1. �ݺ��ڰ� �����Ϸ��� �����͸� �����ϴ� �����̳��� private �� �ս��� ������ ����
	// 2. �����̳� ���о��� ������ �̸��� ������ �ݺ��� ���� Ŭ������ �̸��� �ս��� �� �� �ְ� ���� ��Ŵ
	//    (�̳�Ŭ������ ����� �����̳� Ŭ������ ���� �ٸ��� ������ �̸� �ߺ������� �߻����� �ʴ´�.)
	class iterator
	{
	private:
		CArr<T>* m_pOwner;
		int			m_Idx;

	public:
		T& operator *()
		{
			return	m_pOwner->m_pData[m_Idx];
		}

		bool operator == (const iterator& _otheriter)
		{
			if (m_pOwner == _otheriter.m_pOwner && m_Idx == _otheriter.m_Idx)
				return true;
			else
				return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !((*this) == _otheriter);
		}

		iterator& operator ++()
		{
			if (m_pOwner && -1 == m_Idx)
			{
				// end iteartor �� ++ �Լ��� ȣ���� ���
				assert(nullptr);
			}

			++m_Idx;

			// end iterator - iterator �� �����̳ʰ� ������ �������� ������ ������ ����Ű�� ����
			if (m_pOwner->m_CurCount <= m_Idx)
			{
				m_Idx = -1;
			}

			return (*this);
		}

		iterator operator ++(int)
		{
			iterator copy(*this);

			++(*this);

			return copy;
		}

		iterator& operator --()
		{
			// iterator �� �������� ���°� �ƴϰų�, begin iterator �� ���
			assert(m_pOwner && m_Idx);

			// ���� end iterator ���� -- �� ȣ���ϸ�
			if (-1 == m_Idx)
			{
				// �����Ͱ� �ϳ��� ���µ� ������ �����͸� ����Ű���� �ϴ� ���
				assert(m_pOwner->m_CurCount);

				// ���� ������ �����͸� ����Ų��.
				m_Idx = m_pOwner->m_CurCount - 1;
			}
			else
			{
				--m_Idx;
			}

			return *this;
		}

		iterator operator --(int)
		{
			iterator copy(*this);

			--(*this);

			return copy;
		}




	public:
		iterator()
			: m_pOwner(nullptr)
			, m_Idx(-1)
		{
		}

		iterator(CArr<T>* _Owner, int _idx)
			: m_pOwner(_Owner)
			, m_Idx(_idx)
		{}

		~iterator()
		{
		}


	};
};

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_CurCount(0)
	, m_MaxCount(2)
{
	//m_pData = (int*)malloc(sizeof(int) * m_MaxCount);
	m_pData = new T[m_MaxCount];
}

template<typename T>
CArr<T>::~CArr()
{
	//free(m_pData);
	delete[] m_pData;
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// �����Ͱ� �� ��������, 
	if (m_MaxCount <= m_CurCount)
	{
		// ���� ���� �߰��Ҵ�
		Realloc();
	}

	m_pData[m_CurCount++] = _Data;
}

template<typename T>
void CArr<T>::Realloc()
{
	// 1. ���ο� ���� �Ҵ�
	m_MaxCount *= 2;
	T* pNew = new T[m_MaxCount];

	// 2. ���� ������ �̵�
	for (int i = 0; i < m_CurCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ���� ����
	delete[] m_pData;

	// 4. ���ο� ������ ����Ų��.
	m_pData = pNew;
}