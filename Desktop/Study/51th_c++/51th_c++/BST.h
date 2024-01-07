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
	BSTNode<T1, T2>* m_Root;		// 루트 노드 주소
	int					m_CurCount;	// 현재 데이터 개수

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
		// 모든 노드들을 삭제
		// 재귀함수		

		// 레벨순회
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
			// 오른쪽 자식이 있으면 
			if (m_TargetNode->HasRightChild())
			{
				// 오른쪽 자식으로 간다.
				BSTNode<T1, T2>* pNextNode = m_TargetNode->pRightChild;

				// 왼쪽자식이 없을 때 까지 내려간다.
				while (pNextNode->pLeftChild) { pNextNode = pNextNode->pLeftChild; }
				m_TargetNode = pNextNode;
			}

			// 오른쪽 자식이 없으며
			else
			{
				BSTNode<T1, T2>* pNextNode = m_TargetNode;

				// 부모의 왼쪽 자식일때 까지 올라가서 그때 부모가 나의 후속자
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

// 입력된 T1, T2 타입의 데이터를 묶어서 BSTPair<T1, T2> 타입 구조체로 반환
template<typename T1, typename T2>
BSTPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return BSTPair<T1, T2>(_first, _second);
}


template<typename T1, typename T2>
void BST<T1, T2>::insert(const BSTPair<T1, T2>& _pair)
{
	BSTNode<T1, T2>* pNewNode = new BSTNode<T1, T2>(_pair);

	// 최초로 데이터가 입력된 상황
	if (nullptr == m_Root)
	{
		m_Root = pNewNode;
	}

	// 데이터가 2개 이상인 경우
	else
	{
		BSTNode<T1, T2>* pNode = m_Root;

		while (true)
		{
			// 입력된 first 값이 현재 노드의 first 값보다 작은 경우
			if (pNewNode->pair.first < pNode->pair.first)
			{
				// 왼쪽이 비어있으면
				if (nullptr == pNode->pLeftChild)
				{
					// 현재 노드의 왼쪽으로 연결
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}

				// 왼쪽으로 내려간다.
				pNode = pNode->pLeftChild;
			}

			// 입력된 first 값이 현재 노드의 first 값보다 큰 경우
			else if (pNode->pair.first < pNewNode->pair.first)
			{
				// 현재 노드의 오른쪽이 비어있으며
				if (nullptr == pNode->pRightChild)
				{
					// 입력된 노드를 현재 노드의 오른쪽으로 연결
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}

				// 오른쪽으로 내려간다.
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