#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>

#define PRE 	1
#define IN 	2
#define POST 	3

#ifndef TREE_NODE
#include "TreeNode.h"
#endif

#ifndef SEARCH_TREE
#include "SearchTree.h"
#endif

SearchTree::SearchTree() {
	kok = NULL;
}

SearchTree::~SearchTree() {
}

TreeNode * SearchTree::Search(int key){ 
	if (!kok) return NULL;
	TreeNode * gezici=kok;
	for( ; ; ) {
		if (key < gezici->getKey()) {
			if (gezici->Sol()) { gezici = gezici->Sol();}
			else break;
		}
		else if (key > gezici->getKey()) {
			if (gezici->Sag()) { gezici = gezici->Sag(); }
			else break;
		}
		else if (key == gezici->getKey()) break;
	}
	return gezici;
}
	
TreeNode * SearchTree::Minimum(){
	return Min(kok);
}

TreeNode * SearchTree::Min(TreeNode* dugum) {
	if (dugum == NULL) return NULL;
        TreeNode* d = dugum;
        while ((d->Sol()) != NULL) 
		d = d->Sol();
        return d;
}

TreeNode * SearchTree::Maximum(){
	return Max(kok);
}

TreeNode * SearchTree::Max(TreeNode* dugum) {
	if (dugum == NULL) return NULL;
        TreeNode* d = dugum;
        while (d->Sag() != NULL) 
		d = d->Sag();
        return d;
}

TreeNode * SearchTree::Successor(int key){
	TreeNode *sonuc, *d=Kok();
	while(1) {
		if (key < d->getKey()) {
			sonuc=d;
			d=d->Sol();
		}
		else if (key > d->getKey())
			d=d->Sag();
		else if (key == d->getKey()) break;
	}
	if (d->Sag()) return Min(d->Sag());
	return sonuc;
}

TreeNode * SearchTree::Predecessor(int key){
	TreeNode *sonuc, *d=Kok();
	while(1) {
                if (key < d->getKey()) {
                        d=d->Sol();
                }
                else if (key > d->getKey()) {
                        sonuc=d;
	                d=d->Sag();
		}
                else if (key == d->getKey()) break;
        }
        if (d->Sol()) return Max(d->Sol());
        return sonuc;
}

void SearchTree::yazdir(int tip, TreeNode* p) {
	if (!p) return;
	switch (tip) {
		case PRE: cout << p->getKey() << " ";
			yazdir(tip,p->Sol());
			yazdir(tip,p->Sag());
			break;
		case IN: yazdir(tip,p->Sol());
			cout << p->getKey() << " ";
			yazdir(tip,p->Sag());
			break;
		case POST: yazdir(tip,p->Sol());
			yazdir(tip,p->Sag());
			cout << p->getKey() << " ";
			break;
	}
}

void SearchTree::PreOrderTraversal(){
	yazdir(PRE, Kok());
}

void SearchTree::InOrderTraversal(){
	yazdir(IN, Kok());
}

void SearchTree::PostOrderTraversal(){
	yazdir(POST, Kok());
}

void SearchTree::Sort(){
	yazdir(IN, Kok());
}

TreeNode* SearchTree::Kok() { return kok; }

void SearchTree::kokYap(TreeNode* p) { kok = p;}
