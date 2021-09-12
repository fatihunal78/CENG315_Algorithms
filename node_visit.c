#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int **nodearray;
int **visitcontrol;
int node;
int x=0;
int y=0;
int t=0;

void clearnode()
{
	int i,j;

	for(i=0;i<=node;i++)
		for(j=0;j<=node;j++)
		{
			nodearray[i][j]=0;
		}
}

void clearvisit()
{
	int i,j;

	for(i=0;i<=node;i++)
		for(j=0;j<=node;j++)
		{
			visitcontrol[i][j]=0;
		}
}

int main()
{
	
	int i,j;
	int row;
	int tmp;
	int x;


	scanf("%d",&node);

	nodearray = (int **) malloc((node+1)*sizeof(int *));
	visitcontrol = (int **) malloc((node+1)*sizeof(int *));
	for (i=0; i<node+1; i++)
	{
		nodearray[i] = (int *) malloc((node+1)*sizeof(int));
		visitcontrol[i]= (int *) malloc((node+1)*sizeof(int));
	}
	
	clearnode();
	clearvisit();

	for(i=0; i<node;i++)
	{
		scanf("%d",&row);
		
		x=getchar();/* to get space*/
		if(x==10)
			continue;
		hede:
		scanf("%d",&tmp);
		nodearray[row][tmp]=1;
		
		x=getchar(); /*to get enter*/
		if(x==32)
			goto hede;
	}

	printf("\nAdjacency Graph\n");
	printf("\t");

	for(i=1;i<=node;i++)
		printf("node%d\t",i);
	printf("\n");
	
	for(i=1;i<=node;i++)
	{
		printf("node%d\t",i);
		for(j=1;j<=node;j++)
		{
			printf("%d\t",nodearray[i][j]);
		}
		printf("\n");
	}


	return 0;
}
