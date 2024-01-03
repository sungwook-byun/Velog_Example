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
	int size() { return m_CurCount; }

	class iterator;

	iterator begin() { return iterator(this, m_pHead); }
	iterator end() { return iterator(this, nullptr); }


	// _targetIter 가 가리키는곳에 _Data 를 저장시키고, 새로 저장한 데이터를 가리키는 iterator 를 반환해준다.
	iterator insert(iterator _targetIter, const T& _Data);

	// _targetIter 가 가리키는 데이터를 삭제하고, 삭제한 다음을 가리키는 iterator 를 반환
	iterator erase(iterator _targetIter);


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
		iterator& operator ++()
		{
			// enditerator 에서 ++ 하는 경우
			assert(m_Owner && m_TargetNode);
			m_TargetNode = m_TargetNode->pNext;

			return *this;
		}

		iterator operator++(int)
		{
			iterator copyiter = *this;

			++(*this);

			return copyiter;
		}

		iterator& operator --()
		{
			assert(m_Owner);
			assert(m_Owner->m_pHead != m_TargetNode); // iterator 가 begin 이다.

			if (nullptr == m_TargetNode)
			{
				// 현재 iterator 가 end 상태인데 -- 함수가 호출된 경우
				// 마지막 노드를 가리키게 한다.
				m_TargetNode = m_Owner->m_pTail;
			}
			else
			{
				// 현재 가리키고 있는 노드의 이전 노드를 가리키게 한다.
				m_TargetNode = m_TargetNode->pPrev;
			}

			return *this;
		}

		iterator operator --(int)
		{
			iterator copyiter = *this;

			++(*this);

			return copyiter;
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

		friend class List<T>;
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


// 반환타입이 이너클래스인 경우 앞에 typename 을 붙여주어야 한다.
template<typename T>
typename List<T>::iterator List<T>::insert(iterator _targetIter, const T& _Data)
{
	// iterator 가 해당 리스트가 소유한 데이터를 가리키는 상태인지 확인
	assert(_targetIter.m_Owner == this);

	// insert 위치가 맨 처음이라면, push_front 로 처리한다.
	if (m_pHead == _targetIter.m_TargetNode)
	{
		// insert 위치를 맨 앞으로 지정했기 때문에 push_front 와 동일한 효과이다.
		push_front(_Data);

		// push_front 가 끝나고 나면 m_pHead 에 새로운 데이터를 저장하는 노드의 주소가 들어있다.
		return iterator(this, m_pHead);
	}
	else
	{
		// 1. 입력되는 데이터를 저장하는 노드를 만든다.
		// 2. 새로 생성된 노드가 _targetIter 가 가리키는 노드를 다음으로 가리킨다.
		// 3. 새로 생성된 노드가 _targetIter 가 가리키는 노드의 이전을, 이전으로 가리킨다.		
		Node<T>* pNewNode = new Node<T>(_Data, _targetIter.m_TargetNode, _targetIter.m_TargetNode->pPrev);

		// 4. _targetIter 의 이전 노드로 가서, 그 노드가 새로 생성된 노드를 Next 로 지정하게 한다.
		_targetIter.m_TargetNode->pPrev->pNext = pNewNode;

		// 5. _targetIter 가 가리키는 노드의 이전을 새로 생성된 노드로 지정한다.
		_targetIter.m_TargetNode->pPrev = pNewNode;

		// 6. 데이터 카운트 증가
		++m_CurCount;

		// 7. 새로운 노드를 가리키는 iterator 를 만들어서 반환
		return iterator(this, pNewNode);
	}
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator _targetIter)
{
	// iterator 가 해당 리스트가 소유한 데이터를 가리키는 상태인지 확인
	assert(_targetIter.m_Owner == this);


	// _targetIter 가 가리키고 있는 노드(삭제할 노드)		
	if (_targetIter.m_TargetNode == m_pHead)
	{
		// 예외상황(삭제할 노드가 Head 인 경우)
		// 두번째 노드를 새로운 헤드로 지정
		m_pHead = _targetIter.m_TargetNode->pNext;

		if (m_pHead == nullptr)
		{
			// 리스트안에 데이터가 1개였다면,(삭제할 노드가 처음이자 마지막 노드였다)
			m_pTail = nullptr;
		}
		else
		{
			// 새롭게 지정된 헤드노드의 이전을 nullptr 로 바꾼다(삭제될 노드를 가리키고 있기 때문에)
			m_pHead->pPrev = nullptr;
		}
	}
	else if (_targetIter.m_TargetNode == m_pTail)
	{
		// 삭제할 노드의 이전을 새로운 Tail 로 지정
		m_pTail = _targetIter.m_TargetNode->pPrev;

		// 새로 지정된 Tail 노드의 Next 를 null 로 바꿈
		m_pTail->pNext = nullptr;
	}

	// 삭제할 노드가 Head 도 아니고 Tail 도 아니다(중간이다)
	else
	{
		// 삭제할 노드 이전노드의 Next 를 삭제할 노드 Next 로 교체
		_targetIter.m_TargetNode->pPrev->pNext = _targetIter.m_TargetNode->pNext;

		// 삭제할 노드 다음 노드의 Prev 를 삭제할 노드 Prev 로 교체
		_targetIter.m_TargetNode->pNext->pPrev = _targetIter.m_TargetNode->pPrev;
	}

	// 삭제된 노드의 다음을 가리키는 iterator 를 만든다.
	iterator nextiter(this, _targetIter.m_TargetNode->pNext);

	// _targetIter 가 가리키고 있는 노드를 delete(동적할당 해제)
	delete _targetIter.m_TargetNode;

	// 데이터 카운트 감소
	--m_CurCount;

	return nextiter;
}
