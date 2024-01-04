#include <set>
#include <map>
using std::set;
using std::map;
using std::make_pair;
#include <iostream>

#include "BST.h"

int main()
{

	BST<int, float> bst;

	bst.insert(make_bstpair(100, 1.1f));
	bst.insert(make_bstpair(200, 2.2f));
	bst.insert(make_bstpair(300, 3.3f));
	bst.insert(make_bstpair(400, 4.4f));

	return 0;
}
