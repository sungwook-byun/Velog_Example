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

	bool IsLeftChild() { pParent->pLeftChild == this; }
	bool IsRightChild() { pParent->pRightChild == this; }

	bool IsRoot() { return !pParent; }


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
	void insert(const BSTPair<T1, T2>& _pair);

public:
	void Circit()
	{
		Circit(m_Root);
	}

private:
	void Circit(BSTNode<T1, T2>* _Node);

public:
	class iterator;
	iterator begin()
	{
		assert(m_Root);

		BSTNode<T1, T2>* pNode = m_Root;

		while (pNode->pLeftChild) { pNode = pNode->pLeftChild; }

		return iterator(this, pNode);
	}

	//iterator end();
	//iterator find(const T1& _key);



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

	public:
		iterator& operator ++()
		{
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

				// �θ��� ���� �ڽ��϶� ���� �ö󰡼� �׶� �θ� ���� �ļ���
				do {
					if (pNextNode->IsRoot())
					{
						// end iterator
						break;
					}
					else
					{
						pNextNode = pNextNode->pParent;
					}
				} while (!pNextNode->IsLeftChild())

					m_TargetNode = pNextNode->pParent;
			}

			return (*this);
		}

		iterator& operator--()
		{



			return (*this);
		}






	public:
		iterator()
			: m_Owner(nullptr)
			, m_TargetNode(nullptr)
		{}

		iterator(BST* _Owner, BSTNode<T1, T2>* _Node)
			: m_Owner(_Owner)
			, m_TargetNode(_Node)
		{}
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