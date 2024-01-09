
#include <iostream>



// 열거형
enum NODE_TYPE // 4 바이트 정수타입
{
	PARENT,
	LEFT_CHILD,
	RIGHT_CHILD,



	END,
};


struct tNode
{
	tNode* arrNode[END];
};

int main()
{
	NODE_TYPE type = PARENT;
	type = LEFT_CHILD;
	type = RIGHT_CHILD;

	tNode node1;

	node1.arrNode[PARENT] = nullptr;
	node1.arrNode[LEFT_CHILD] = nullptr;
	node1.arrNode[RIGHT_CHILD] = nullptr;

	NODE_TYPE ChildType;
	NODE_TYPE NodeType;

	// 삭제할 노드가 왼쪽 자식이다.
	if (_target.m_TargetNode->IsLeftChild())
	{
		NodeType = LEFT_CHILD;
		// 보유한 자식이 왼쪽 자식이다.
		if (_target.m_TargetNode->HasLeftChild())
			ChildType = LEFT_CHILD;

		// 보유한 자식이 오른쪽 자식이다.
		else
			ChildType = RIGHT_CHILD;
	}

	// 삭제할 노드가 오른쪽 자식이다.
	else
	{
		NodeType = RIGHT_CHILD;
		if (_target.m_TargetNode->HasLeftChild())
			ChildType = LEFT_CHILD;

		else
			ChildType = RIGHT_CHILD;
	}

	node1.arrNode[ChildType]->arrNode[PARENT] = node1->arrNode[PARENT]->arrNode[NodeType];
	node1->arrNode[PARENT]->arrNode[NodeType] = node1.arrNode[ChildType];

	return 0;
}
