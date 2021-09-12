#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int ***robots;
int **arraykey;
int **path;
int *stationrobots;
int stationcount;
int robotcount=0;
char temp[10];

void clear()
{
	int i;
	for(i=0;i<10;i++)
		temp[i]=0;
}

void clearkey()
{
	int i,j;
	for(i=0;i<robotcount+2;i++)
		for(j=0;j<robotcount+2;j++)
			arraykey[i][j]=0;

	for(i=0;i<stationcount+2;i++)
		for(j=0;j<2;j++)
			path[i][j]=0;

}

void initialization()
{
	int i,j,k;
	for(i=0;i<robotcount+2;i++)
		for(j=0;j<robotcount+2;j++)
			for(k=0;k<6;k++)
				robots[i][j][k]=0;

}

int main()
{
	int i,j,k;
	int x,y;
	int a,b;

	scanf("%d\n",&stationcount);
	stationrobots = (int *) malloc((stationcount+2)*sizeof(int));
	
	robotcount=0;

	for(i=1;i<=stationcount;i++)
	{
		scanf("%d",&stationrobots[i]);
		robotcount +=stationrobots[i];
	}

	robots = (int ***) malloc((robotcount+2)*sizeof(int **));
	arraykey= (int **) malloc((robotcount+2)*sizeof(int *));
	path = (int **) malloc((stationcount+2)*sizeof(int *));
	for (i=0; i<robotcount+2; i++)
	{
		robots[i]= (int **) malloc((robotcount+2)*sizeof(int *));
		arraykey[i]= (int *) malloc((robotcount+2)*sizeof(int));
	}
	for (i=0; i<stationcount+2; i++)
	{
		path[i]= (int *) malloc(2*sizeof(int));
	}


	for(i=0; i<robotcount+2; i++)
	{
		for (j=0; j<robotcount+2; j++)
		{
			robots[i][j]= (int *) malloc(6*sizeof(int));
		}
	}

	initialization();
	clearkey();
	getchar();
	clear();
	
	for(i=0;i<=robotcount;i++)
	{
		a=i;
		b=0;

		k=0;
		while((x=getchar())!='_')
		{
			temp[k++]=x;
		}
		y=atoi(temp);
		clear();
		robots[a][b][0]=y;
		
		k=0;
		while((x=getchar())!=' ')
		{
			temp[k++]=x;
		}
		y=atoi(temp);
		clear();
		robots[a][b][1]=y;

		arraykey[robots[a][b][0]][robots[a][b][1]]=i;
		
		k=0;
		while((x=getchar())!=' ' && x!='\n')
		{
			temp[k++]=x;
		}
		y=atoi(temp);
		clear();
		robots[a][b][2]=y;

		if(x==10)
			continue;

adjacency:
		k=0;
		b++;
		while((x=getchar())!='_')
		{
			temp[k++]=x;
		}
		y=atoi(temp);
		clear();
		robots[a][b][0]=y;
		
		k=0;
		while((x=getchar())!=' ' && x!='\n')
		{
			temp[k++]=x;
		}
		y=atoi(temp);
		clear();
		robots[a][b][1]=y;

		if(x==10)
			continue;
			else goto adjacency;
	}

	robots[robotcount+1][0][0]=stationcount+1;
	robots[robotcount+1][0][1]=1;
	arraykey[stationcount+1][1]=robotcount+1;
	
	for(i=0;i<robotcount+1;i++)
	{
		b=1;
		while(robots[i][b][0]!=0)
		{

			if(i==0 || robots[i][0][4]!=0  || robots[i][0][5]!=0)
			{
				if(robots[ arraykey[robots[i][b][0]][robots[i][b][1]] ][0][3] < robots[i][0][3] + robots[ arraykey[robots[i][b][0]][robots[i][b][1]] ][0][2])
				{
					robots[ arraykey[robots[i][b][0]][robots[i][b][1]] ][0][3]= robots[i][0][3] + robots[ arraykey[robots[i][b][0]][robots[i][b][1]] ][0][2];
					robots[ arraykey[robots[i][b][0]][robots[i][b][1]] ][0][4]= robots[i][0][0];
					robots[ arraykey[robots[i][b][0]][robots[i][b][1]] ][0][5]= robots[i][0][1];
				}
			}
			b++;
		}
	}
	
	printf("%d\n",robots[robotcount+1][0][3]);
	

	i=stationcount+1;
	path[i][0]=stationcount+1;
	path[i][1]=1;
	x=robots[robotcount+1][0][4];
	y=robots[robotcount+1][0][5];
	i--;

	while(x!=0 || y!=0)
	{
	path[i][0]=x;
	path[i][1]=y;
	a=x;
	b=y;
	i--;
	x=robots[ arraykey[a][b] ][0][4];
	y=robots[ arraykey[a][b] ][0][5];
	}

	for(j=0;j<stationcount+2;j++)
	{
		if(path[j][0]!=0 || path[j][1]!=0)
			printf("%d_%d ",path[j][0],path[j][1]);
	}
	
	return 0;
}