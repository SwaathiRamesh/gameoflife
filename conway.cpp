#include<iostream>
#include <unistd.h>
//#include<conio.h>
using namespace std;
unsigned int microseconds;
int first;
int second;
char G[100][100];
char H[100][100];
void copygrid(int y)
{
	int i,j;
	for(i=0;i<first;i++)
		for(j=0;j<second;j++)
			if(y)//copy into H, the standby
			H[i][j]=G[i][j];
			else//copy into master for 0
				G[i][j]=H[i][j];
}
void printgrid()
{	
	int i,j;
	microseconds=1;
	sleep(microseconds);
	for(i=0;i<first;i++)
	{
		for(j=0;j<second;j++)
			cout<<G[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n-----------------------------\n";
}	
int return_neighbour_count( int i, int j)
{
	int count=0;
	(G[i-1][j-1]=='F')?((i-1 >=0 && j-1>=0 )? count++: count=count):count=count;
	(G[i-1][j]=='F')?((i-1>=0)?count++:count=count):count=count;
	(G[i-1][j+1]=='F')?((i-1>=0 && j+1<second)? count++:count=count):count=count;
	(G[i][j-1]=='F')?((j-1>=0)?count++:count=count):count=count;
	(G[i][j+1]=='F')?((j+1<second)?count++:count=count):count=count;
	(G[i+1][j-1]=='F')?((i+1<first && j-1>=0)?count++:count=count):count=count;
	(G[i+1][j]=='F')?((i+1<first)?count++:count=count):count=count;
	(G[i+1][j+1]=='F')?((i+1<first && j+1<second)?count++:count=count):count=count;
	return count;
}
main()
{
	int i,j;
	int live_cells=0;
	cout<<"\nEnter Dimensions of Bounding box (X rows, Y columns)\n\tX:\t";
	cin>>first;
	cout<<"\n\tY:\t";
	cin>>second;
//	char G[first][second];
//	char H[first][second];
	for(i=0;i<first;i++)
		for(j=0;j<second;j++)
			G[i][j]='E';
	printgrid();
	cout<<"\nEnter the number of live cells to start with:\t";
	cin>>live_cells;
	while(live_cells--)
	{
		int l,m;
		cout<<"\n Enter x and y index of the cell:\t";
		cin>>l>>m;
		G[l][m]='F';
	}
	int times=5;
	cout<<"\nHow many iterations?(default of 5):\t";
	cin>>times;
	printgrid(); times--;	
	while(times--)
	{
	copygrid(1);
        for(i=0;i<first;i++)
		for(j=0;j<second;j++)
			{
			int n=return_neighbour_count(i,j);
			if(G[i][j]!='F')
				H[i][j]=(n==3)?'F':'E';
			else
				H[i][j]=(n>1)?'F':'E';
			}
	copygrid(0);
	
	for(i=0;i<first;i++)
		for(j=0;j<second;j++)
			H[i][j]='E';
	printgrid();
	}
	
}
