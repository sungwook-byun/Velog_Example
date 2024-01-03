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
			assert(m_Owner);
			assert(m_Owner->m_pHead != m_TargetNode); // iterator �� begin �̴�.

			if (nullptr == m_TargetNode)
			{
				// ���� iterator �� end �����ε� -- �Լ��� ȣ��� ���
				// ������ ��带 ����Ű�� �Ѵ�.
				m_TargetNode = m_Owner->m_pTail;
			}
			else
			{
				// ���� ����Ű�� �ִ� ����� ���� ��带 ����Ű�� �Ѵ�.
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
	// iterator �� �ش� ����Ʈ�� ������ �����͸� ����Ű�� �������� Ȯ��
	assert(_targetIter.m_Owner == this);


	// _targetIter �� ����Ű�� �ִ� ���(������ ���)		
	if (_targetIter.m_TargetNode == m_pHead)
	{
		// ���ܻ�Ȳ(������ ��尡 Head �� ���)
		// �ι�° ��带 ���ο� ���� ����
		m_pHead = _targetIter.m_TargetNode->pNext;

		if (m_pHead == nullptr)
		{
			// ����Ʈ�ȿ� �����Ͱ� 1�����ٸ�,(������ ��尡 ó������ ������ ��忴��)
			m_pTail = nullptr;
		}
		else
		{
			// ���Ӱ� ������ ������� ������ nullptr �� �ٲ۴�(������ ��带 ����Ű�� �ֱ� ������)
			m_pHead->pPrev = nullptr;
		}
	}
	else if (_targetIter.m_TargetNode == m_pTail)
	{
		// ������ ����� ������ ���ο� Tail �� ����
		m_pTail = _targetIter.m_TargetNode->pPrev;

		// ���� ������ Tail ����� Next �� null �� �ٲ�
		m_pTail->pNext = nullptr;
	}

	// ������ ��尡 Head �� �ƴϰ� Tail �� �ƴϴ�(�߰��̴�)
	else
	{
		// ������ ��� ��������� Next �� ������ ��� Next �� ��ü
		_targetIter.m_TargetNode->pPrev->pNext = _targetIter.m_TargetNode->pNext;

		// ������ ��� ���� ����� Prev �� ������ ��� Prev �� ��ü
		_targetIter.m_TargetNode->pNext->pPrev = _targetIter.m_TargetNode->pPrev;
	}

	// ������ ����� ������ ����Ű�� iterator �� �����.
	iterator nextiter(this, _targetIter.m_TargetNode->pNext);

	// _targetIter �� ����Ű�� �ִ� ��带 delete(�����Ҵ� ����)
	delete _targetIter.m_TargetNode;

	// ������ ī��Ʈ ����
	--m_CurCount;

	return nextiter;
}
