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


	// BSTPair<T1, T2> pair; 는 구조체의 인스턴스 이기 때문에 자동으로 기본 생성자가 호출된다. 
	// 그렇다면 위에서 초기화로 넣어준 first,second가 기본값으로 설정되기 때문에 따로 다시 설정할 필요가 없음.
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

	//class iterator;
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
	}

	/*class iterator
	{

	};*/
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

	std::cout << _Node->pair.first << std::endl;

	Circit(_Node->pLeftChild);
	Circit(_Node->pRightChild);
}