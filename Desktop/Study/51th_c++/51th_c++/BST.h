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
			// ���� �ļ���(InOrder Successor)

			// ������ �ڽ��� ������ 
			if (m_TargetNode->HasRightChild())
			{
				// ������ �ڽ����� ����.
				BSTNode<T1, T2>* pNextNode = m_TargetNode->pRightChild;

				// �����ڽ��� ���� �� ���� ��������.
				while (pNextNode->pLeftChild) { pNextNode = pNextNode->pLeftChild; }
				m_TargetNode = pNextNode;
			}

			// ������ �ڽ��� ������
			else
			{
				BSTNode<T1, T2>* pNextNode = m_TargetNode;

				// �θ��� ���� �ڽ��϶� ���� �ö󰡼� �׶� �θ� ���� ���� �ļ���
				while (true)
				{
					if (pNextNode->IsRoot())
					{
						// ���� ��尡 ���� ������ ����̴�(���� �ļ��ڸ� ã������ ��Ʈ��忡 ����)
						// end iterator
						m_TargetNode = nullptr;
						wcscpy_s(m_szDesc, L"End");
						return (*this);
					}
					else if (pNextNode->IsLeftChild())
					{
						m_TargetNode = pNextNode->pParent;
						break;
					}
					else
					{
						pNextNode = pNextNode->pParent;
					}
				};
			}

			return (*this);
		}

		iterator& operator--()
		{
			// end iterator�� ��� --�� �ϸ� ������ ���� �����ϴ� �� ������ ��带 ã�ƾ���
			if (nullptr == m_TargetNode)
			{
				// ���� ������ ��带 ã�� ���� Ʈ���� ��Ʈ���� �����ϴ� �ӽ� ��带 �����մϴ�.
				BSTNode<T1, T2>* pPrevNode = m_Owner->m_Root;

				// Ʈ���� ���������� �̵��ϸ鼭 ���� ������ ��带 ã���ϴ�.
				while (pPrevNode->pRightChild) { pPrevNode = pPrevNode->pRightChild; }

				// �׷��� ã�� ���� ������ ��带 Ÿ�ٳ�忡 ������ �� ������ ��带 ����Ŵ
				m_TargetNode = pPrevNode;

				return *this;
			}

			// ���� �ڽ��� �ִ°���̸� ����Ʈ������ ���� �����ʿ� �ִ� ��带 ã��
			if (m_TargetNode->HasLeftChild())
			{
				BSTNode<T1, T2>* pPrevNode = m_TargetNode->pLeftChild;

				while (pPrevNode->pRightChild) { pPrevNode = pPrevNode->pRightChild; }

				m_TargetNode = pPrevNode;
			}
			else
			{
				// ���� �ڽ��� ������ �θ��带 ã��
				while (m_TargetNode->IsLeftChild()) { m_TargetNode = m_TargetNode->pParent; }

				m_TargetNode = m_TargetNode->pParent;
			}
			return *this;
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
	// ������ ��尡 ��������� ��� (�ڽ��� 0��)
	if (_target.m_TargetNode->IsLeaf())
	{

	}

	// �ڽ��� 2�� �ִ� ���
	else if (_target.m_TargetNode->IsFull())
	{

	}

	// �ڽ��� 1�� �ִ� ���
	else
	{

	}

	return iterator();
}