#include "RedBlackTree.h"
#include <iostream.h>

RedBlackTree::~RedBlackTree() {}
RedBlackTree::RedBlackTree() {kokYap(NULL);}

enum {SIYAH, KIRMIZI };
TreeNode *current, *parent, *great, *grand;

void RedBlackTree::rotateWithRightChild(TreeNode*  k1 ) const
{
	TreeNode *k2 = k1->Sag();
	k1->SagYap(k2->Sol());
	k2->SolYap(k1);
//	k1 = k2;
}
// ----------------------------------------------------------------------
void RedBlackTree::rotateWithLeftChild(TreeNode *  k2 ) const
{
	TreeNode *k1 = k2->Sol();
	k2->SolYap(k1->Sag());
	k1->SagYap(k2);
//	k2 = k1;
}
// ----------------------------------------------------------------------
TreeNode * RedBlackTree::rotate( const int & item, TreeNode *theParent ) const
{
	if( item < theParent->getKey() )
	{
		item < theParent->Sol()->getKey() ?
			rotateWithLeftChild( theParent->Sol() )  :  // LL
			rotateWithRightChild( theParent->Sol() ) ;  // LR
		return theParent->Sol();
	}
	else
	{
		item < theParent->Sag()->getKey() ?
			rotateWithLeftChild( theParent->Sag() ) :  // RL
			rotateWithRightChild( theParent->Sag() );  // RR
		return theParent->Sag();
	}
}
// ----------------------------------------------------------------------
void RedBlackTree::handleReorient( const int & item )
        {
		cout << "handle basi" << endl;
                // Do the color flip
            if (!current) return;
		current->setColor(KIRMIZI);
           if (current->Sol()) (current->Sol())->setColor(SIYAH);
           if (current->Sag()) (current->Sag())->setColor(SIYAH);
	cout << "if oncesi" << endl;
            if( parent->getColor() == KIRMIZI )   // Have to rotate
            {
                grand->setColor(KIRMIZI);
                if( item < grand->getKey() != item < parent->getKey() )
                    parent = rotate( item, grand );  // Start dbl rotate
                current = rotate( item, great );
                current->setColor(SIYAH);
            }
            Kok()->setColor(SIYAH); // Make root black
        }
// ----------------------------------------------------------------------
void RedBlackTree::Insert( TreeNode * yeni )
{
	 int x = yeni->getKey();
	
            current = parent = grand = Kok();
	cout << "1" << endl;
            while( current )
            {
                great = grand; grand = parent; parent = current;
                current = x < current->getKey() ?  current->Sol() : current->Sag();
	cout << "while" << endl;
                    // Check if two red children; fix if so
                if( current && current->Sol() && current->Sag() &&
				(current->Sol())->getColor() == KIRMIZI && 
				(current->Sag())->getColor() == KIRMIZI )
                     	handleReorient( x );
	cout << "while sonu" << endl;
            }
	cout << "5" << endl;
                // Insertion fails if already present
  //          if( current != nullNode )
    //            return;
            current = yeni;
	if (!(Kok())) kokYap(yeni);
                // Attach to parent
	else {     
		if( x < parent->getKey() )
                	parent->SolYap(current);
            	else
                	parent->SagYap(current);
           	handleReorient( x );
	}
}


void RedBlackTree::Delete(int key) {
}
