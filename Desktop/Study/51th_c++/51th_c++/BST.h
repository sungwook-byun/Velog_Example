#pragma once

#include <iostream>





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


	// BSTPair<T1, T2> pair; �� ����ü�� �ν��Ͻ� �̱� ������ �ڵ����� �⺻ �����ڰ� ȣ��ȴ�. 
	// �׷��ٸ� ������ �ʱ�ȭ�� �־��� first,second�� �⺻������ �����Ǳ� ������ ���� �ٽ� ������ �ʿ䰡 ����.
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

	//class iterator;
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
	}

	/*class iterator
	{

	};*/
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

	std::cout << _Node->pair.first << std::endl;

	Circit(_Node->pLeftChild);
	Circit(_Node->pRightChild);
}