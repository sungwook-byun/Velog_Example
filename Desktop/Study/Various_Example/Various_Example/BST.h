#pragma once

#include <iostream>

template <typename T1, typename T2>
struct BSTPair
{
public:
	T1 first;
	T2 second;

	BSTPair()
	{}
	BSTPair(const T1& _first, const T2& _second)
		: first(_first)
		, second(_second)
	{}

	~BSTPair()
	{}

};

template <typename T1, typename T2>
struct BSTNode
{
public:
	BSTPair<T1, T2> pair;

	BSTNode* Parent;
	BSTNode* LeftChild;
	BSTNode* RightChild;


	BSTNode()
		: Parent(nullptr)
		, LeftChild(nullptr)
		, RightChild(nullptr)
	{
	}

	BSTNode(const BSTPair<T1, T2>& _pair, BSTNode* _Parent = nullptr, BSTNode* _LeftChild = nullptr, BSTNode* _RightChild = nullptr)
		: pair(_pair)
		, Parent(_Parent)
		, LeftChild(_LeftChild)
		, RightChild(_RightChild)
	{
	}

	~BSTNode()
	{}

};


template<typename T1, typename T2>
class BST
{
private:
	BSTNode<T1, T2>* RootNode;
	int CurCount;

public:
	void insert(const BSTPair<T1, T2>& _pair);

public:
	void Circit()
	{
		Circit(RootNode);
	}

private:
	void Circit(BSTNode<T1, T2>* _Node);




public:
	BST()
		: RootNode(nullptr)
		, CurCount(0)
	{}

	~BST()
	{}
};


template<typename T1, typename T2>
BSTPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return BSTPair<T1, T2>(_first, _second);
}


template<typename T1, typename T2>
void BST<T1, T2>::insert(const BSTPair<T1, T2>& _pair)
{
	BSTNode<T1, T2>* NewNode = new BSTNode<T1, T2>(_pair);

	// 최초 데이터 입력받는 상황

	if (nullptr == RootNode)
	{
		RootNode = NewNode;
	}
	// 데이터가 2개 이상일때
	else
	{
		BSTNode<T1, T2>* pNode = RootNode;

		while (true)
		{
			if (NewNode->pair.first < pNode->pair.first)
			{
				if (nullptr == pNode->LeftChild)
				{
					pNode->LeftChild = NewNode;
					NewNode->Parent = pNode;
					break;
				}
				pNode = pNode->LeftChild;
			}
			else if (pNode->pair.first < NewNode->pair.first)
			{
				if (nullptr == pNode->RightChild)
				{
					pNode->RightChild = NewNode;
					NewNode->Parent = pNode;
					break;
				}
				pNode = pNode->RightChild;
			}
		}
	}
	++CurCount;
}

template<typename T1, typename T2>
void BST<T1, T2>::Circit(BSTNode<T1, T2>* _Node)
{
	if (nullptr == _Node)
	{
		return;
	}



	Circit(_Node.LeftChild);

	std::cout << _Node.pair.first << std::endl;

	Circit(_Node.RightChild);
}