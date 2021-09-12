#include "BinarySearchTree.h"
#include <iostream.h>

void BinarySearchTree::Insert(TreeNode * node){
	int sayi = node->getKey();
	TreeNode *yeni = new TreeNode(sayi);
	if (!Kok()) { kokYap(yeni); return;}
	TreeNode *d = Search(sayi);
	
	if (sayi < d->getKey()) 
		d->SolYap(yeni);
	else if (sayi > d->getKey())
		d->SagYap(yeni);
}

void BinarySearchTree::Delete(int key){
	TreeNode *p = Kok(),
		 *pp = 0;
	while (p && p->getKey() != key) {
		pp = p;
		if (key < p->getKey()) p=p->Sol();
		else p=p->Sag();
	}

	if (p->Sol() && p->Sag()) {
		TreeNode *s = p->Sol(),
			 *ps = p;
		while (s->Sag()) {
			ps = s;
			s = s->Sag();
		}
		p->setKey(s->getKey());
		p = s;
		pp = ps;
	}
	TreeNode *c;
	if (p->Sol()) c = p->Sol();
	else c = p->Sag();

	if (p == Kok()) kokYap(c);
	else {
		if (p == pp->Sol()) pp->SolYap(c);
		else pp->SagYap(c);
	}
	delete p;


/*	TreeNode *hedef = Search(key);
	if (!hedef) cout << "Binary Delete icinde search hatasi !!" << endl;
	TreeNode *yedek = hedef;
	TreeNode* pp = hedef;
	if (hedef->Sol() && !(hedef->Sag())) 
		hedef = hedef->Sol();
	else if (!(hedef->Sol()) && (hedef->Sag())) 
		hedef = hedef->Sag();
	else if (hedef->Sol() && (hedef->Sag())) {
		yedek = Max(hedef->Sol());
		hedef->setKey(yedek->getKey());
		hedef->setColor(yedek->getColor());
	}
	else hedef = NULL;

//	delete  yedek;	
	yedek = NULL;
*/
}

BinarySearchTree::~BinarySearchTree() {};
BinarySearchTree::BinarySearchTree() {};
