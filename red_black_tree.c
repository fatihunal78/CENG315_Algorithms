#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int no;
typedef enum { BLACK, RED } nodeColor;
typedef struct data
 {
    int key;
 } data;
                                                                                                                             
typedef struct bs_node
{
   data bs_data;              
   struct bs_node *leftchild;     
   struct bs_node *rightchild;     
} bs_node;
typedef bs_node *bs_tree;

typedef struct rbt_node 
{
    struct rbt_node *left;       
    struct rbt_node *right;      
    struct rbt_node *parent;     
    nodeColor color;            
    int key;                
} Node;

void insertrbt(int key);
void correctinsert(Node *p);
void leftrotate(Node *p);
void rightrotate(Node *p);
Node *findrbt(int key);
void bs_insert(data v, bs_tree *tree );
bs_tree bs_search(int x, bs_tree tree);


Node original = { &original, &original, 0, BLACK, 0};
Node *root = &original;

void insertrbt(int key) 
{
    Node *current, *parent, *p;
    no=0;
    current = root;
    parent = 0;
    no+=2;
    while (current != &original) 
    {
        parent = current;
        current = (key < current->key) ?
            current->left : current->right;
	no+=4;
    }
    no++;
    p = malloc (sizeof(*p));
    p->parent = parent;
    p->left = &original;
    p->right = &original;
    p->color = RED;
    p->key = key;
    no+=7;

    if(parent) 
    {
        if(key < parent->key)
	{
            parent->left = p;
	    no+=3;
        }
	else
	{
            parent->right = p;
	    no+=3;
	}
    } else 
	{
        root = p;
	no+=2;
    	}

    correctinsert(p);
    return;
}

void correctinsert(Node *p) 
{
    while (p != root && p->parent->color == RED) 
    {
	no+=3;
        if (p->parent == p->parent->parent->left) 
	{
            Node *q = p->parent->parent->right;
	    no+=1;
            if (q->color == RED) 
	    {
                p->parent->color = BLACK;
                q->color = BLACK;
                p->parent->parent->color = RED;
                p = p->parent->parent;
		no+=5;
            } else 
	      {
                if (p == p->parent->right) 
		{
                    p = p->parent;
		    no+=3;
                    leftrotate(p);
                }
		p->parent->color = BLACK;
                p->parent->parent->color = RED;
		no+=3;
                rightrotate(p->parent->parent);
              }
        } else 
	   {
            	Node *q = p->parent->parent->left;
		no+=2;
            	if (q->color == RED) 
		{
                	p->parent->color = BLACK;
	                q->color = BLACK;
        	        p->parent->parent->color = RED;
                	p = p->parent->parent;
			no+=5;
            	} else 
		  {
                	if (p == p->parent->left) 
			{
                    	p = p->parent;
		    	no+=2;
                    	rightrotate(p);
                  	}
                
			p->parent->color = BLACK;
                	p->parent->parent->color = RED;
			no+=4;
                	leftrotate(p->parent->parent);
           	 }
           }
    }
    root->color = BLACK;
    no+=4;
}

void rightrotate(Node *p) 
{
    Node *q = p->left;
    p->left = q->right;
    no+=2;
    if (q->right != &original)
    {
	q->right->parent = p;
	no+=1;
    }
    if (q != &original)
    {
	q->parent = p->parent;
	no+=1;
    }
    if (p->parent)
    {
        if (p == p->parent->right)
	{
            p->parent->right = q;
	    no+=3;
        }
	else
	{
            p->parent->left = q;
	    no+=3;
	}
    } else 
	{
        root = q;
	no+=1;
	}
    q->right = p;
    if (p != &original)
    {
	p->parent = q;
	no+=1;
    }
    no+=4;
}

void leftrotate(Node *p) 
{
    Node *q = p->right;
    p->right = q->left;
    no+=2;
    if (q->left != &original)
    {
	q->left->parent = p;
	no+=1;
    }
    no++;
    if (q != &original)
    {
	q->parent = p->parent;
	no+=1;
    }
    if (p->parent) 
    {
        if (p == p->parent->left)
	{
            p->parent->left = q;
	    no+=3;
        }
	else
	{
            p->parent->right = q;
	    no+=3;
	}
    } else 
	{
        root = q;
	no+=2;
    	}
    q->left = p;
    if (p != &original)
    {
	p->parent = q;
	no+=1;
    }
    no+=4;
}

Node *findrbt(int key) 
{
    Node *current;
    current = root;
    no=0;
    no++;
    while(current != &original) 
    {
	no++;
        if(key == current->key) 
	{
	    no+=2;
            return current;
        } else 
	  {
            current = (key < current->key) ? current->left : current->right;
	    no+=4;
          }
    }
    no++;
    return NULL;
}

void bs_insert(data v, bs_tree *tree )
{
   if (*tree == NULL)                
   {
      (*tree)=(bs_tree)malloc(sizeof(bs_node));
      (*tree)->bs_data = v;
      (*tree)->leftchild = NULL;
      (*tree)->rightchild = NULL;
      no+=5;
   }
   else                      
     if (v.key < (*tree)->bs_data.key )
	{	
		no+=4;       
		bs_insert( v, &(*tree)->leftchild );
	}
     else
	{
		no+=4;
		bs_insert( v, &(*tree)->rightchild );
	}
}

bs_tree bs_search(int x, bs_tree tree)
{
  if (tree == NULL)
  {     
	no+=2;                  
	return NULL;
  }
  else
     if (tree->bs_data.key == x)
	{
                no+=2;
		return tree;
	}
     else
        if (x < tree->bs_data.key )
	{
	   no+=4;
           return bs_search(x,tree->leftchild);
	}
        else
	{
	   no+=5;
           return bs_search(x, tree->rightchild);
	}
}

int main(int argc,char **argv)
{
int key;
Node *p;

bs_tree tree = NULL;
data v;

char op=0;
int value=0;
int queryno=0;
int insertno=0;
int totalquery=0;
int totalinsert=0;
float qa=0;
float ia=0;


if (argc==2 && (!(strcmp(argv[0], "./hw2")) || !(strcmp(argv[0], "hw2"))) && !(strcmp(argv[1], "bst")))
{
	while(1)
	{
	scanf("%c %d",&op, &value);

	if(op=='i')
	{
	/*insert function*/
	v.key=value;
	no=0;
	bs_insert(v,&tree);
	totalinsert+=no;
	insertno++;
	printf("OK %d\n",no);

	} else if(op=='q')
		{
		/*query function*/
		no=0;
			if(bs_search(value,tree)!=NULL)
			{
			totalquery+=no;
			queryno++;
			printf("YES %d\n",no);
			} else
				{
				totalquery+=no;
	                        queryno++;
				printf("NO %d\n",no);
				}
		} else
			{
			if(queryno > 0)qa=(float)totalquery/queryno;
			if(insertno > 0)ia=(float)totalinsert/insertno;
			printf("QA %lf\n",qa);
			printf("IA %lf\n",ia);
			getchar();
			break;
			}
	getchar();
	}
}

if (argc==2 && (!(strcmp(argv[0], "./hw2")) || !(strcmp(argv[0], "hw2"))) && !(strcmp(argv[1], "rbt")))
{
        while(1)
        {
        scanf("%c %d",&op, &value);
                                                                                                                                               
        if(op=='i')
        {
        /*insert function*/
        key=value;
	no=0;
        insertrbt(key);
        totalinsert+=no;
        insertno++;
	printf("OK %d\n",no);
                                                                                                                                               
        } else if(op=='q')
                {
                /*query function*/
		key=value;
		no=0;
                        if((p=findrbt(key))!=NULL)
			{
                        totalquery+=no;
                        queryno++;
                        printf("YES %d\n",no);
                        } else 
				{
                                totalquery+=no;
                                queryno++;
                                printf("NO %d\n",no);
				}
                } else
                        {
			if (queryno > 0)qa=(float)totalquery/queryno;
                        if (insertno > 0)ia=(float)totalinsert/insertno;
                        printf("QA %lf\n",qa);
                        printf("IA %lf\n",ia);
                        getchar();
                        break;
                        }
        getchar();
        }
}

return 0;
}

