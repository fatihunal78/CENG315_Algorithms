#include "BinarySearchTree.h"
#include <iostream.h>

int main(int argc,char **argv) {
	BinarySearchTree b;
	b.Insert(new TreeNode(4));
	b.Insert(new TreeNode(3)); 
	b.Insert(new TreeNode(1));
	b.Insert(new TreeNode(123)); 
	b.Insert(new TreeNode(0)); 
	b.Insert(new TreeNode(-5)); 
	b.Insert(new TreeNode(2)); 
	b.Insert(new TreeNode(-4)); 
	b.Insert(new TreeNode(100)); 
	b.Sort();
	b.PreOrderTraversal();
	b.InOrderTraversal();
	b.PostOrderTraversal();
	
	cout << "Min: " << (b.Minimum())->getKey() << endl;
	cout << "Max: " << (b.Maximum())->getKey() << endl;
	cout << "Suc 0: " << (b.Successor(0))->getKey() << endl;
	cout << "Suc 100: " << (b.Successor(100))->getKey() << endl;
	cout << "Pre 123: " << (b.Predecessor(123))->getKey() << endl;
	cout << "Pre -4: " << (b.Predecessor(-4))->getKey() << endl;
	
	
	b.Delete(0);
	b.Sort();
	b.Delete(-4);
	b.Sort();
	b.Delete(4);
	b.Sort();
	return 0;
}
