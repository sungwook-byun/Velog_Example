
#include <iostream>



// ������
enum NODE_TYPE // 4 ����Ʈ ����Ÿ��
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

	// ������ ��尡 ���� �ڽ��̴�.
	if (_target.m_TargetNode->IsLeftChild())
	{
		NodeType = LEFT_CHILD;
		// ������ �ڽ��� ���� �ڽ��̴�.
		if (_target.m_TargetNode->HasLeftChild())
			ChildType = LEFT_CHILD;

		// ������ �ڽ��� ������ �ڽ��̴�.
		else
			ChildType = RIGHT_CHILD;
	}

	// ������ ��尡 ������ �ڽ��̴�.
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
