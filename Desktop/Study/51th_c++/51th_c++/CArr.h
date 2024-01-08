#pragma once

#include <assert.h>

// 클래스 템플릿
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

	// 헤더에 맴버함수를 구현 한 경우
	// 인라인 함수로 처리	
	// 헤더에 실제 구현을 함으로써, 호출시 해당 구현을 그대로 복사한다.
	// 매크로 함수와 유사, 함수 호출 시 별도의 스택 생성 해제 비용이 없다.

	// 인라인 함수를 남발하는 경우 발생하는 문제.
	// 함수 구문이 여기저기 호출하는 곳마다 복사되어서 코드의 양이 엄청나게 늘어날 수 있다.

	// 인라인 처리를 할 함수들의 특징.
	// 구문이 짧다(기능이 간단한다, Get, Set 종류의 함수)
	// 자주 호출 되는 함수
public:
	int size() { return m_CurCount; }
	int capacity() { return m_MaxCount; }
	T at(int _Idx) { return m_pData[_Idx]; }

	// 반환타입을 참조형태로 반환, 반환된 값을 수정하면 원본값이 수정되는 개념
	T& operator[](int _Idx) { return m_pData[_Idx]; }


public:
	CArr();
	~CArr();

	// 1. 반복자가 접근하려는 데이터를 관리하는 컨테이너의 private 에 손쉽게 접근이 가능
	// 2. 컨테이너 구분없이 동일한 이름을 가져서 반복자 역할 클래스의 이름을 손쉽게 알 수 있게 통일 시킴
	//    (이너클래스가 선언된 컨테이너 클래스가 각각 다르기 때문에 이름 중복문제가 발생하지 않는다.)
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
				// end iteartor 에 ++ 함수를 호출한 경우
				assert(nullptr);
			}

			++m_Idx;

			// end iterator - iterator 가 컨테이너가 보유한 데이터의 마지막 다음을 가리키는 상태
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
			// iterator 가 정상적인 상태가 아니거나, begin iterator 인 경우
			assert(m_pOwner && m_Idx);

			// 만약 end iterator 에게 -- 를 호출하면
			if (-1 == m_Idx)
			{
				// 데이터가 하나도 없는데 마지막 데이터를 가리키려고 하는 경우
				assert(m_pOwner->m_CurCount);

				// 가장 마지막 데이터를 가리킨다.
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
	// 데이터가 꽉 차있으면, 
	if (m_MaxCount <= m_CurCount)
	{
		// 저장 공간 추가할당
		Realloc();
	}

	m_pData[m_CurCount++] = _Data;
}

template<typename T>
void CArr<T>::Realloc()
{
	// 1. 새로운 공간 할당
	m_MaxCount *= 2;
	T* pNew = new T[m_MaxCount];

	// 2. 기존 데이터 이동
	for (int i = 0; i < m_CurCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간 해제
	delete[] m_pData;

	// 4. 새로운 공간을 가리킨다.
	m_pData = pNew;
}