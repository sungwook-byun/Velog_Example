#pragma once

#include <iostream>
#include <assert.h>

#include "List.h"



// Binary Search Tree(BST)
template<typename T1, typename T2>
struct BSTPair
{
	T1 first;
	T2 second;

	BSTPair()
	{}

	BSTPair(const T1& _first, const T2& _second)
		: first(_first)
		, second(_second)
	{
	}
};

template<typename T1, typename T2>
struct BSTNode
{
	BSTPair<T1, T2> pair;

	BSTNode* pParent;
	BSTNode* pLeftChild;
	BSTNode* pRightChild;

	bool HasRightChild() { return pRightChild; }
	bool HasLeftChild() { return pLeftChild; }

	bool IsLeftChild() { return pParent->pLeftChild == this; }
	bool IsRightChild() { return pParent->pRightChild == this; }

	bool IsRoot() { return !pParent; }
	bool IsLeaf() { return !(pLeftChild || pRightChild); }
	bool IsFull() { return pLeftChild && pRightChild; }

	BSTNode()
		: pParent(nullptr)
		, pLeftChild(nullptr)
		, pRightChild(nullptr)
	{}

	BSTNode(const BSTPair<T1, T2>& _pair, BSTNode* _Parent = nullptr, BSTNode* _LeftChild = nullptr, BSTNode* _RightChild = nullptr)
		: pair(_pair)
		, pParent(_Parent)
		, pLeftChild(_LeftChild)
		, pRightChild(_RightChild)
	{}
};

template<typename T1, typename T2>
class BST
{
private:
	BSTNode<T1, T2>* m_Root;		// ��Ʈ ��� �ּ�
	int					m_CurCount;	// ���� ������ ����

public:
	void Circit()
	{
		Circit(m_Root);
	}

private:
	void Circit(BSTNode<T1, T2>* _Node);

public:
	class iterator;

	void insert(const BSTPair<T1, T2>& _pair);

	iterator find(const T1& _key);

	iterator erase(const iterator& _target);

	iterator begin()
	{
		assert(m_Root);

		BSTNode<T1, T2>* pNode = m_Root;

		while (pNode->pLeftChild) { pNode = pNode->pLeftChild; }

		return iterator(this, pNode);
	}

	iterator end()
	{
		return iterator(this, nullptr);
	}

private:
	// ���� �ļ���, ������ ã��
	BSTNode<T1, T2>* FindInOrderSuccessor(BSTNode<T1, T2>* _TargetNode);
	BSTNode<T1, T2>* FindInOrderPredecessor(BSTNode<T1, T2>* _TargetNode);


public:
	BST()
		: m_Root(nullptr)
		, m_CurCount(0)
	{}

	~BST()
	{
		// ��� ������ ����
		// ����Լ�		

		// ������ȸ
		List<BSTNode<T1, T2>*> queue;

		queue.push_back(m_Root);

		while (!queue.empty())
		{
			BSTNode<T1, T2>* pNode = queue.pop_front();

			if (nullptr != pNode->pLeftChild)
				queue.push_back(pNode->pLeftChild);

			if (nullptr != pNode->pRightChild)
				queue.push_back(pNode->pRightChild);

			delete pNode;
		}
	}


	class iterator
	{
	private:
		BST* m_Owner;
		BSTNode<T1, T2>* m_TargetNode;
		wchar_t				m_szDesc[6];	// ���� ����
		// end iterator ����
		// m_Owner �� nullptr �� �ƴϰ� m_TargetNode �� nullptr �̸�...

	public:
		const BSTPair<T1, T2>& operator* ()
		{
			assert(m_Owner && m_TargetNode);

			return m_TargetNode->pair;
		}


		bool operator == (const iterator& _otheriter)
		{
			if (m_Owner == _otheriter.m_Owner && m_TargetNode == _otheriter.m_TargetNode)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !((*this) == _otheriter);
		}


		iterator& operator ++()
		{
			assert(m_Owner);

			// ���� �ļ���(InOrder Successor) ã�Ƽ� ����Ų��.
			m_TargetNode = m_Owner->FindInOrderSuccessor(m_TargetNode);

			if (nullptr == m_TargetNode)
			{
				wcscpy_s(this->m_szDesc, L"End");
			}

			return (*this);
		}

		iterator& operator--()
		{
			assert(m_Owner);

			// ���� ������ ã�Ƽ� ����Ų��.
			m_TargetNode = m_Owner->FindInOrderPredecessor(m_TargetNode);

			// ���� �����ڸ� ã���� ������(nullptr) 
			// ==> Begin Iterator �� -- �Լ��� ȣ���� ��Ȳ
			assert(m_TargetNode);

			// ã�� ���������ڰ� �� ó���̶��
			if (!m_TargetNode->HasLeftChild())
			{
				wcscpy_s(m_szDesc, L"Begin");
			}
			else
			{
				// ���¼��� ����
				wcscpy_s(m_szDesc, L"");
			}

			return (*this);
		}

	public:
		iterator()
			: m_Owner(nullptr)
			, m_TargetNode(nullptr)
			, m_szDesc{}
		{
			wcscpy_s(m_szDesc, L"None");
		}

		iterator(BST* _Owner, BSTNode<T1, T2>* _Node)
			: m_Owner(_Owner)
			, m_TargetNode(_Node)
			, m_szDesc{}
		{
			if (nullptr != m_Owner && nullptr == m_TargetNode)
			{
				wcscpy_s(m_szDesc, L"End");
			}
		}
		friend class BST<T1, T2>;
	};
};

// �Էµ� T1, T2 Ÿ���� �����͸� ��� BSTPair<T1, T2> Ÿ�� ����ü�� ��ȯ
template<typename T1, typename T2>
BSTPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return BSTPair<T1, T2>(_first, _second);
}


template<typename T1, typename T2>
void BST<T1, T2>::insert(const BSTPair<T1, T2>& _pair)
{
	BSTNode<T1, T2>* pNewNode = new BSTNode<T1, T2>(_pair);

	// ���ʷ� �����Ͱ� �Էµ� ��Ȳ
	if (nullptr == m_Root)
	{
		m_Root = pNewNode;
	}

	// �����Ͱ� 2�� �̻��� ���
	else
	{
		BSTNode<T1, T2>* pNode = m_Root;

		while (true)
		{
			// �Էµ� first ���� ���� ����� first ������ ���� ���
			if (pNewNode->pair.first < pNode->pair.first)
			{
				// ������ ���������
				if (nullptr == pNode->pLeftChild)
				{
					// ���� ����� �������� ����
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}

				// �������� ��������.
				pNode = pNode->pLeftChild;
			}

			// �Էµ� first ���� ���� ����� first ������ ū ���
			else if (pNode->pair.first < pNewNode->pair.first)
			{
				// ���� ����� �������� ���������
				if (nullptr == pNode->pRightChild)
				{
					// �Էµ� ��带 ���� ����� ���������� ����
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}

				// ���������� ��������.
				pNode = pNode->pRightChild;
			}
		}
	}

	++m_CurCount;
}

template<typename T1, typename T2>
inline void BST<T1, T2>::Circit(BSTNode<T1, T2>* _Node)
{
	if (nullptr == _Node)
	{
		return;
	}



	Circit(_Node->pLeftChild);

	//std::cout << _Node->pair.first << std::endl;

	Circit(_Node->pRightChild);
}

template<typename T1, typename T2>
typename BST<T1, T2>::iterator BST<T1, T2>::find(const T1& _key)
{
	BSTNode<T1, T2>* pNode = m_Root;

	while (pNode)
	{
		if (_key < pNode->pair.first)
		{
			pNode = pNode->pLeftChild;
		}
		else if (pNode->pair.first < _key)
		{
			pNode = pNode->pRightChild;
		}
		else
		{
			break;
		}
	}
	return iterator(this, pNode);
}

template<typename T1, typename T2>
typename BST<T1, T2>::iterator BST<T1, T2>::erase(const iterator& _target)
{
	BSTNode<T1, T2>* pSuccessor = nullptr;

	// ������ ��尡 ��������� ��� (�ڽ��� 0��)
	if (_target.m_TargetNode->IsLeaf())
	{
		// ������ ����� �ļ��ڸ� ã�´�.
		pSuccessor = FindInOrderSuccessor(_target.m_TargetNode);

		// 1. �����Ϸ��� ��尡 ��Ʈ ����� ���
		if (_target.m_TargetNode->IsRoot())
		{
			// ��Ʈ��带 �����ϰ�, m_Root �����͸� nullptr �� �����Ѵ�.
			delete m_Root;
			m_Root = nullptr;
		}

		// 2. ��Ʈ���� �ƴϴ�. (������常)
		else
		{
			// �θ� ���� ���� ������ ��带 ����Ű�� �����͸� nullptr �� �����Ѵ�.
			if (_target.m_TargetNode->IsLeftChild())
			{
				_target.m_TargetNode->pParent->pLeftChild = nullptr;
			}
			else
			{
				_target.m_TargetNode->pParent->pRightChild = nullptr;
			}

			// �ش� ��带 �޸� �����Ѵ�.
			delete _target.m_TargetNode;
		}

		// ������ ������ �ϳ� ���δ�.
		--m_CurCount;

		// ������ ����� ����(�ļ���) �� ����Ű�� iterator �� ��ȯ���ش�.
		return iterator(this, pSuccessor);
	}

	// �ڽ��� 2�� �ִ� ���
	else if (_target.m_TargetNode->IsFull())
	{

	}

	// �ڽ��� 1�� �ִ� ���
	else
	{
		pSuccessor = FindInOrderSuccessor(_target.m_TargetNode);

		// ������ ��尡 ���� �ڽ��̴�.
		if (_target.m_TargetNode->IsLeftChild())
		{
			// ������ �ڽ��� ���� �ڽ��̴�.
			if (_target.m_TargetNode->HasLeftChild())
			{
				_target.m_TargetNode->pLeftChild->pParent = _target.m_TargetNode->pParent;
				_target.m_TargetNode->pParent->pLeftChild = _target.m_TargetNode->pLeftChild;
			}

			// ������ �ڽ��� ������ �ڽ��̴�.
			else
			{
				_target.m_TargetNode->pRightChild->pParent = _target.m_TargetNode->pParent;
				_target.m_TargetNode->pParent->pLeftChild = _target.m_TargetNode->pRightChild;
			}
		}

		// ������ ��尡 ������ �ڽ��̴�.
		else
		{
			if (_target.m_TargetNode->HasLeftChild())
			{

			}
			else
			{

			}
		}

	}

	return iterator();
}

template<typename T1, typename T2>
BSTNode<T1, T2>* BST<T1, T2>::FindInOrderSuccessor(BSTNode<T1, T2>* _TargetNode)
{
	// ������ �ڽ��� ������ 
	if (_TargetNode->HasRightChild())
	{
		// ������ �ڽ����� ����.
		BSTNode<T1, T2>* pNextNode = _TargetNode->pRightChild;

		// �����ڽ��� ���� �� ���� ��������.
		while (pNextNode->pLeftChild) { pNextNode = pNextNode->pLeftChild; }

		return pNextNode;
	}

	// ������ �ڽ��� ������
	else
	{
		BSTNode<T1, T2>* pNextNode = _TargetNode;

		// �θ��� ���� �ڽ��϶� ���� �ö󰡼� �׶� �θ� ���� ���� �ļ���
		while (true)
		{
			if (pNextNode->IsRoot())
			{
				// ���� ��尡 ���� ������ ����̴�(���� �ļ��ڸ� ã������ ��Ʈ��忡 ����)
				// -> end iterator �� ����				
				return nullptr;
			}
			else if (pNextNode->IsLeftChild())
			{
				return pNextNode->pParent;
			}
			else
			{
				pNextNode = pNextNode->pParent;
			}
		};
	}
}

template<typename T1, typename T2>
BSTNode<T1, T2>* BST<T1, T2>::FindInOrderPredecessor(BSTNode<T1, T2>* _TargetNode)
{
	// End Iterator �ε� -- �� ȣ����� ���
	if (nullptr == _TargetNode)
	{
		BSTNode<T1, T2>* pNode = m_Root;

		while (pNode->pRightChild) { pNode = pNode->pRightChild; }

		return pNode;
	}

	// ���� ������(InOrder Predecessor)
	// ���� �ڽ��� ������
	else if (_TargetNode->HasLeftChild())
	{
		// ���� �ڽ����� ����.
		BSTNode<T1, T2>* pNextNode = _TargetNode->pLeftChild;

		// ������ �ڽ��� ���� �� ���� ��������.
		while (pNextNode->pRightChild) { pNextNode = pNextNode->pRightChild; }

		return pNextNode;
	}

	// ���� �ڽ��� ������
	else
	{
		BSTNode<T1, T2>* pNextNode = _TargetNode;

		// �θ��� ������ �ڽ��϶� ���� �ö󰡼�, �׶� �θ� ���� ���� ������
		while (true)
		{
			if (pNextNode->IsRoot())
			{
				// ���� ��尡 ���� ó�� ����̴�(���� �����ڸ� ã������ ��Ʈ��忡 ����)
				// -> assert, begin �������� �� �� ����.				
				return nullptr;
			}
			else if (pNextNode->IsRightChild())
			{
				return pNextNode->pParent;
			}
			else
			{
				pNextNode = pNextNode->pParent;
			}
		};
	}
}
