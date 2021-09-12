/******************************************************************/
/**********************************************************************/
/* source code "binary search tree" (bst.c) for exercise 8, sheet 3   */
/*                                                                    */
/* lecture Algorithms and Data Structures WS 04/05                    */                                                             
/* Andreas Frommer, 9.5.00                                            */
/* Update: 29/10/2004    S. Fischer                                   */         
/*                                                                    */
/* provides all functions for a binary search tree                    */
/*                                                                    */
/* key_type is in; adjust input and output for struct data_set,       */
/* struct bs_node, the functions is_equal and is_less                 */
/*                                                                    */
/******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {false=0, true=1};

typedef int key_type;                           /* TO ADJUST */
typedef int rest_type;

typedef struct data_set
 {
    key_type key;
    rest_type rest_data;
 }
data_set;


typedef struct bs_node
{
   data_set bs_data;               /* data in node */
   struct bs_node *bs_lchild;           /* pointer to left and */
   struct bs_node *bs_rchild;                   /*  right child */
}
bs_node;

typedef bs_node *bs_tree;
              
/******************************************************************/

int is_equal( key_type s1, key_type s2)
{
  if (s1==s2)
     return true;
  else
     return false;
}

/******************************************************************/

int is_less( key_type s1, key_type s2)
{
  if (s1<s2)
     return true;
  else
     return false;
}
/******************************************************************/

bs_tree bs_search(key_type s, bs_tree t)
{ 
            /* searchs in the binary search tree t for a node with key
               s and returns a pointer to the first found node;
               if there in no such a node, it returns NULL */

  if (t == NULL)                       /* stop searching, key not there */
     return NULL; 
  else
     if ( is_equal( t->bs_data.key, s ) )
                                 /* key found */
           return t;
     else                    /* not found yet; continue searching */
        if ( is_less( s, t->bs_data.key ) )
           return bs_search( s, t->bs_lchild );
        else
           return bs_search( s, t->bs_rchild );
}

/******************************************************************/

void bs_insert( data_set d, bs_tree *t )
{
          /* inserts a data set d into the binary search tree t */
     
   if (*t == NULL)                /* positon for insertion found */
   {
      (*t)=(bs_tree)malloc(sizeof(bs_node));
      (*t)->bs_data = d;
      (*t)->bs_lchild = NULL;
      (*t)->bs_rchild = NULL;
   } 
   else                      /* not found yet; continue searching */
     if ( is_less( d.key, (*t)->bs_data.key ) )
        bs_insert( d, &(*t)->bs_lchild );
     else
        bs_insert( d, &(*t)->bs_rchild );
}

/******************************************************************/ 

void delete_minimum( bs_tree *t, bs_tree *minimum)
{
 
    /* provides a pointer pointing at the node with minimal
       key in the binary search tree t and deletes this 
       node from  t                                         */ 
 
  if (*t == NULL) 
     printf("errror in delete_minimum : t = NULL\n");
  else
     if ((*t)->bs_lchild == NULL)
     {                                        /* minimum found */
         *minimum = *t;
         *t = (*t)->bs_rchild;                     /* delete node */
     }
     else            /* minimum not found yet; continue searching */
         delete_minimum( &(*t)->bs_lchild, minimum );
}

/******************************************************************/

void bs_delete( key_type s, bs_tree *t)
{
             /* deletes a node with key s from the binary search tree t.
                If there is not such a node, the tree stays unchanged.   */
       
  bs_node *minimum;          /* points at the minimum in
                                 the right subtree         */
  if (*t != NULL) 
  {
     if ( is_equal( (*t)->bs_data.key, s ) )
     {                /* otherwise there is no s in the tree; ready */
        if ((*t)->bs_lchild == NULL) 
                              /* at most right child;
                                  simply delete node   */
             (*t) = (*t)->bs_rchild;
        else
           if ((*t)->bs_rchild == NULL)  
                                  /* only left child;
                                    simply delete node */
               (*t) = (*t)->bs_lchild;
           else       /* both children; replace node with
                          minimum of the right subtree */
           { 
                 delete_minimum( &((*t)->bs_rchild), &minimum );
                 minimum->bs_lchild = (*t)->bs_lchild;
                 minimum->bs_rchild = (*t)->bs_rchild;
                 (*t) = minimum;
           }
      }
      else      /*  i.e. t->bs_data.key != s :           */
      {         /*  continue searching for the node which should be deleted */
        if ( is_less( s, (*t)->bs_data.key ) )
           bs_delete( s, &((*t)->bs_lchild) );
        else
           bs_delete( s, &((*t)->bs_rchild) );
      }
   }
}

/******************************************************************/

void display(bs_tree t)
{
  /* Displays complete tree; t points at the root        */
  /* the indentation corresponds to the depth of the nodes in the tree, the
     root of the tree has depth 0 and is displayed most left     */

  static int depth = -1;       /* depth of a node, root = 0 */
  int i;
  
  depth++;
  if (t != NULL)
    {
      display(t->bs_lchild);
      for (i = 0; i <= depth; i++)
	printf("   ");
      printf(" %3i\n", t->bs_data.key);
      display(t->bs_rchild);
    }
  depth--;
}

/******************************************************************/

int main(void)


/* for testing. ADJUST input and output !  */

{
  bs_tree t = NULL;
  bs_node *pointer;
  key_type s;
  data_set d;
  char c = ' ';
  short more;

  for (more = 1; more; )
    {
      if (c != '\n')
        {
          printf("\033[1;34m"); /* blue big font
                                   (ANSI-controll-digits,
                                   comment out if there are any problems !)         */
          printf("o: output/display binary search tree\n");
          printf("i: insert dataset\n");
          printf("s: search for data set\n");
          printf("d: delete data set\n");
          printf("q: quit program\n");
          printf("\033[0m");
                            /* sets font properties back*/
        }
      c = getchar();
      switch(c)
        {
          case 'o':
            display(t);
            break;
          case 'i':
            printf("data set to be inserted (only key): "); 
                                                      /* TO ADJUST */
            scanf("%d", &(d.key) );    /* TO ADJUST */
            bs_insert(d,&t);
            break;
          case 's':
            printf("key to be searched for: ");
            scanf("%d", &s);                    /* TO ANJUST */
            pointer = bs_search(s,t);
            printf("the binary search tree %s contain(s) the data set with key %d \n",
                   pointer == NULL ? "does not" : "",s);
                                                      /* TO ADJUST */
            break;
          case 'd':
            printf("key of the data set that should be deleted: ");
            scanf("%d", &s);                          /* TO  ADJUST */
            bs_delete(s,&t);
            break;
          case 'q':
            more = 0;
            break;
        }
      putchar('\n');
    }  
 
  return 0;
} 


