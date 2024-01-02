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


	// _targetIter �� ����Ű�°��� _Data �� �����Ű��, ���� ������ �����͸� ����Ű�� iterator �� ��ȯ���ش�.
	iterator insert(iterator _targetIter, const T& _Data);

	// _targetIter �� ����Ű�� �����͸� �����ϰ�, ������ ������ ����Ű�� iterator �� ��ȯ
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
			// Owner(List) �� �����Ǿ����� ������, �������� iterator �� �ƴϴ�.
			// Owner �� �����Ǿ� �־, m_TargetNode �� nullptr �̸� End Iterator �̱� ������
			// �������� ������ ����Ű�� ������ iterator ���� * �� ���ٱ���� ���� ����
			assert(m_Owner && m_TargetNode);
			return m_TargetNode->Data;
		}

		// 1. ++, -- ��ȯŸ�� ����
		// 2. ++, -- ���������� ����
		iterator& operator ++()
		{
			// enditerator ���� ++ �ϴ� ���
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
			assert(m_Owner && m_TargetNode);
			assert(m_Owner->m_pHead != m_TargetNode); // iterator �� begin �̴�.
			m_TargetNode = m_TargetNode->pPrev;

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


// ��ȯŸ���� �̳�Ŭ������ ��� �տ� typename �� �ٿ��־�� �Ѵ�.
template<typename T>
typename List<T>::iterator List<T>::insert(iterator _targetIter, const T& _Data)
{
	// iterator �� �ش� ����Ʈ�� ������ �����͸� ����Ű�� �������� Ȯ��
	assert(_targetIter.m_Owner == this);

	// insert ��ġ�� �� ó���̶��, push_front �� ó���Ѵ�.
	if (m_pHead == _targetIter.m_TargetNode)
	{
		// insert ��ġ�� �� ������ �����߱� ������ push_front �� ������ ȿ���̴�.
		push_front(_Data);

		// push_front �� ������ ���� m_pHead �� ���ο� �����͸� �����ϴ� ����� �ּҰ� ����ִ�.
		return iterator(this, m_pHead);
	}
	else
	{
		// 1. �ԷµǴ� �����͸� �����ϴ� ��带 �����.
		// 2. ���� ������ ��尡 _targetIter �� ����Ű�� ��带 �������� ����Ų��.
		// 3. ���� ������ ��尡 _targetIter �� ����Ű�� ����� ������, �������� ����Ų��.		
		Node<T>* pNewNode = new Node<T>(_Data, _targetIter.m_TargetNode, _targetIter.m_TargetNode->pPrev);

		// 4. _targetIter �� ���� ���� ����, �� ��尡 ���� ������ ��带 Next �� �����ϰ� �Ѵ�.
		_targetIter.m_TargetNode->pPrev->pNext = pNewNode;

		// 5. _targetIter �� ����Ű�� ����� ������ ���� ������ ���� �����Ѵ�.
		_targetIter.m_TargetNode->pPrev = pNewNode;

		// 6. ������ ī��Ʈ ����
		++m_CurCount;

		// 7. ���ο� ��带 ����Ű�� iterator �� ���� ��ȯ
		return iterator(this, pNewNode);
	}
}

template<typename T>
typename List<T>::iterator List<T>::erase(iterator _targetIter)
{
	// ������ ī��Ʈ ����

	// _targetIter �� ����Ű�� �ִ� ���(������ ���)
	// ������ ��� ��������� Next �� ������ ��� Next �� ��ü
	// ������ ��� ���� ����� Prev �� ������ ��� Prev �� ��ü

	// ���ܻ�Ȳ(������ ��尡 Head �̰ų� Tail �� ���)

	// _targetIter �� ����Ű�� �ִ� ��带 delete(�����Ҵ� ����)

	// ������ ����� ������ ����Ű�� iterator �� ��ȯ���ش�.
	return iterator();
}