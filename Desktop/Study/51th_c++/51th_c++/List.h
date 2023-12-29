#pragma once

#include <assert.h>

template<typename T>
struct Node
{
	T			Data;
	Node<T>* pNext;
	Node<T>* pPrev;

	Node()
		: Data()
		, pNext(nullptr)
		, pPrev(nullptr)
	{}

	Node(const T& _Data, Node<T>* _Next, Node<T>* _Prev)
		: Data(_Data)
		, pNext(_Next)
		, pPrev(_Prev)
	{}
};

template<typename T>
class List
{
private:
	Node<T>* m_pHead;
	Node<T>* m_pTail;
	int			m_CurCount;

public:
	void push_back(const T& _Data);
	void push_front(const T& _Data);


	class iterator;

	iterator begin() { return iterator(this, m_pHead); }
	iterator end() { return iterator(this, nullptr); }


	// _targetIter 가 가리키는곳에 _Data 를 저장시키고, 새로 저장한 데이터를 가리키는 iterator 를 반환해준다.
	// iterator insert(iterator _targetIter, const T& _Data);

	// _targetIter 가 가리키는 데이터를 삭제하고, 삭제한 다음을 가리키는 iterator 를 반환
	// iterator erase(iterator _targetIter);


public:
	List()
		: m_pHead(nullptr)
		, m_pTail(nullptr)
		, m_CurCount(0)
	{}

	~List()
	{
		Node<T>* pNode = m_pHead;

		while (pNode)
		{
			Node<T>* pNext = pNode->pNext;
			delete pNode;
			pNode = pNext;
		}
	}

public:
	class iterator
	{
	private:
		List<T>* m_Owner;
		Node<T>* m_TargetNode;

	public:
		T& operator *()
		{
			// Owner(List) 가 설정되어있지 않으면, 정상적인 iterator 가 아니다.
			// Owner 가 설정되어 있어도, m_TargetNode 가 nullptr 이면 End Iterator 이기 때문에
			// 마지막의 다음을 가리키는 상태의 iterator 에게 * 로 접근기능을 쓰면 에러
			assert(m_Owner && m_TargetNode);
			return m_TargetNode->Data;
		}

		// 1. ++, -- 반환타입 문제
		// 2. ++, -- 후위연산자 문제
		void operator ++()
		{
			// enditerator 에서 ++ 하는 경우
			assert(m_Owner && m_TargetNode);
			m_TargetNode = m_TargetNode->pNext;
		}

		void operator --()
		{
			assert(m_Owner && m_TargetNode);
			assert(m_Owner->m_pHead != m_TargetNode); // iterator 가 begin 이다.			
			m_TargetNode = m_TargetNode->pPrev;
		}

		bool operator == (const iterator& _otheriter)
		{
			if (m_Owner == _otheriter.m_Owner && m_TargetNode == _otheriter.m_TargetNode)
				return true;
			else
				return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !((*this) == _otheriter);
		}

	public:
		iterator()
			: m_Owner(nullptr)
			, m_TargetNode(nullptr)
		{}

		iterator(List<T>* _Owner, Node<T>* _TargetNode)
			: m_Owner(_Owner)
			, m_TargetNode(_TargetNode)
		{}

		~iterator()
		{}
	};
};

template<typename T>
void List<T>::push_back(const T& _Data)
{
	Node<T>* pNewNode = new Node<T>(_Data, nullptr, nullptr);

	if (0 == m_CurCount) //nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		m_pTail = pNewNode;
	}

	++m_CurCount;
}

template<typename T>
inline void List<T>::push_front(const T& _Data)
{
	Node<T>* pNewNode = new Node<T>(_Data, m_pHead, nullptr);

	if (nullptr != m_pHead)
	{
		m_pHead->pPrev = pNewNode;
	}
	else
	{
		m_pTail = pNewNode;
	}

	m_pHead = pNewNode;
	++m_CurCount;
}