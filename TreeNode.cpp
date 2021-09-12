#include "TreeNode.h"
#include <iostream.h>


enum { SIYAH, KIRMIZI };

TreeNode::TreeNode(){ 
	renk = KIRMIZI;
	sol = sag = NULL;
}

TreeNode::TreeNode(int key){ 
	renk = KIRMIZI; 
	sayi = key;
	sol = sag = NULL;
}

TreeNode::TreeNode(int key,int color){ 
	renk = color; 
	sayi = key;
	sol = sag = NULL;
}

TreeNode::~TreeNode() { }

int TreeNode::getKey(){ 
	return sayi;
}

int TreeNode::getColor(){ 
	return renk;
}

void TreeNode::setKey(int key){ 
	sayi = key;
}

void TreeNode::setColor(int color){ 
	renk = color;
}

TreeNode* TreeNode::Sol() {
	return sol;
}

TreeNode* TreeNode::Sag() {
	return sag;
}

void TreeNode::SolYap(TreeNode* p) {sol = p;}

void TreeNode::SagYap(TreeNode* p) {sag = p;}
