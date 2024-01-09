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
	BSTNode<T1, T2>* m_Root;		// 루트 노드 주소
	int					m_CurCount;	// 현재 데이터 개수

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
	// 중위 후속자, 선행자 찾기
	BSTNode<T1, T2>* FindInOrderSuccessor(BSTNode<T1, T2>* _TargetNode);
	BSTNode<T1, T2>* FindInOrderPredecessor(BSTNode<T1, T2>* _TargetNode);


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
		wchar_t				m_szDesc[6];	// 설명 정보
		// end iterator 조건
		// m_Owner 가 nullptr 이 아니고 m_TargetNode 가 nullptr 이면...

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

			// 중위 후속자(InOrder Successor) 찾아서 가리킨다.
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

			// 중위 선행자 찾아서 가리킨다.
			m_TargetNode = m_Owner->FindInOrderPredecessor(m_TargetNode);

			// 중위 선행자를 찾을수 없었다(nullptr) 
			// ==> Begin Iterator 에 -- 함수를 호출한 상황
			assert(m_TargetNode);

			// 찾은 중위선행자가 맨 처음이라면
			if (!m_TargetNode->HasLeftChild())
			{
				wcscpy_s(m_szDesc, L"Begin");
			}
			else
			{
				// 상태설명 갱신
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

	// 삭제할 노드가 리프노드인 경우 (자식이 0개)
	if (_target.m_TargetNode->IsLeaf())
	{
		// 삭제할 노드의 후속자를 찾는다.
		pSuccessor = FindInOrderSuccessor(_target.m_TargetNode);

		// 1. 삭제하려는 노드가 루트 노드인 경우
		if (_target.m_TargetNode->IsRoot())
		{
			// 루트노드를 삭제하고, m_Root 포인터를 nullptr 로 변경한다.
			delete m_Root;
			m_Root = nullptr;
		}

		// 2. 루트노드는 아니다. (리프노드만)
		else
		{
			// 부모 노드로 가서 삭제될 노드를 가리키는 포인터를 nullptr 로 변경한다.
			if (_target.m_TargetNode->IsLeftChild())
			{
				_target.m_TargetNode->pParent->pLeftChild = nullptr;
			}
			else
			{
				_target.m_TargetNode->pParent->pRightChild = nullptr;
			}

			// 해당 노드를 메모리 해제한다.
			delete _target.m_TargetNode;
		}

		// 데이터 개수를 하나 줄인다.
		--m_CurCount;

		// 삭제된 노드의 다음(후속자) 을 가리키는 iterator 를 반환해준다.
		return iterator(this, pSuccessor);
	}

	// 자식이 2개 있는 경우
	else if (_target.m_TargetNode->IsFull())
	{

	}

	// 자식이 1개 있는 경우
	else
	{
		pSuccessor = FindInOrderSuccessor(_target.m_TargetNode);

		// 삭제할 노드가 왼쪽 자식이다.
		if (_target.m_TargetNode->IsLeftChild())
		{
			// 보유한 자식이 왼쪽 자식이다.
			if (_target.m_TargetNode->HasLeftChild())
			{
				_target.m_TargetNode->pLeftChild->pParent = _target.m_TargetNode->pParent;
				_target.m_TargetNode->pParent->pLeftChild = _target.m_TargetNode->pLeftChild;
			}

			// 보유한 자식이 오른쪽 자식이다.
			else
			{
				_target.m_TargetNode->pRightChild->pParent = _target.m_TargetNode->pParent;
				_target.m_TargetNode->pParent->pLeftChild = _target.m_TargetNode->pRightChild;
			}
		}

		// 삭제할 노드가 오른쪽 자식이다.
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
	// 오른쪽 자식이 있으면 
	if (_TargetNode->HasRightChild())
	{
		// 오른쪽 자식으로 간다.
		BSTNode<T1, T2>* pNextNode = _TargetNode->pRightChild;

		// 왼쪽자식이 없을 때 까지 내려간다.
		while (pNextNode->pLeftChild) { pNextNode = pNextNode->pLeftChild; }

		return pNextNode;
	}

	// 오른쪽 자식이 없으면
	else
	{
		BSTNode<T1, T2>* pNextNode = _TargetNode;

		// 부모의 왼쪽 자식일때 까지 올라가서 그때 부모가 나의 중위 후속자
		while (true)
		{
			if (pNextNode->IsRoot())
			{
				// 현재 노드가 가장 마지막 노드이다(중위 후속자를 찾기전에 루트노드에 도달)
				// -> end iterator 로 변경				
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
	// End Iterator 인데 -- 를 호출받은 경우
	if (nullptr == _TargetNode)
	{
		BSTNode<T1, T2>* pNode = m_Root;

		while (pNode->pRightChild) { pNode = pNode->pRightChild; }

		return pNode;
	}

	// 중위 선행자(InOrder Predecessor)
	// 왼쪽 자식이 있으면
	else if (_TargetNode->HasLeftChild())
	{
		// 왼쪽 자식으로 간다.
		BSTNode<T1, T2>* pNextNode = _TargetNode->pLeftChild;

		// 오른쪽 자식이 없을 때 까지 내려간다.
		while (pNextNode->pRightChild) { pNextNode = pNextNode->pRightChild; }

		return pNextNode;
	}

	// 왼쪽 자식이 없으면
	else
	{
		BSTNode<T1, T2>* pNextNode = _TargetNode;

		// 부모의 오른쪽 자식일때 까지 올라가서, 그때 부모가 나의 중위 선행자
		while (true)
		{
			if (pNextNode->IsRoot())
			{
				// 현재 노드가 가장 처음 노드이다(중위 선행자를 찾기전에 루트노드에 도달)
				// -> assert, begin 이전으로 갈 수 없다.				
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
