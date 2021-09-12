#include "RedBlackTree.h"
#include <iostream.h>

int main(int argc,char **argv) {
	RedBlackTree a;
	a.Insert(new TreeNode(3));
	a.Sort(); cout << endl;
	a.Insert(new TreeNode(2));
	a.Sort(); cout << endl;
//	a.Insert(new TreeNode(5));
  return 0;
}
