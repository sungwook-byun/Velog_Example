#pragma once

template<typename T>
class Node
{
public:
	T			Data;
	Node<T>*	pNext; // 다음노드의 주소값을 가져야 하니 Node<T>*
	Node<T>*	pPrev; // 이전 노드의 주소값을 가져야 하니 Node<T>*

	Node()
		: Data(0)
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
	int			 CurCount;
	Node<T>*	 Head;
	Node<T>*	 Tail;
	
public:
	List()
		: Head(nullptr)
		, Tail(nullptr)
		, CurCount(0)
	{}

	void Push(const T& _Data2);

	~List()
	{
		Node<T>* TempNode = Head;

		while (TempNode)
		{
			Node<T>* Spare_Next = TempNode->pNext;
			delete TempNode;
			TempNode = Spare_Next;
		}
	}
};


template<typename T>
void List<T>::Push(const T& _Data2)
{
	Node<T>* NewNode = new Node<T>(_Data2, nullptr, nullptr);

	if (0 == CurCount)
	{
		Head = NewNode;
		Tail = NewNode;
	}
	else
	{
		Tail->pNext = NewNode;
		NewNode->pPrev = Tail;
		Tail = NewNode;
	}
	++CurCount;

}
