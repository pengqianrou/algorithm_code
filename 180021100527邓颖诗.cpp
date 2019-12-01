#include <iostream>
using namespace std;
template<class Type>
#define maxint 11111
void Dijkstra(int n,int v,Type dist[],int prev[],Type c[][100])
{//n is the number of points, v is the source, 
//dist is the current shortest path length, prev is the front drive, 
//c is the figure 
	bool s[maxint];//s is mark 
	for(int i=1;i<=n;i++)//Initialization
	{
		dist[i]=c[v][i];
		s[i]=false;
		if(dist[i]==maxint)
			prev[i]=0;
		else
			prev[i]=v;
	}
	dist[v]=0;
	s[v]=true;
	for(int i=1;i<n;i++)
	{
		int temp=maxint;
		int u=v;
		for(int j=1;j<=n;j++)
		{
			if((!s[j])&&(dist[j]<temp))
			{//Find the points that have not passed 
			//and are the shortest from the source
				u=j;
				temp=dist[j];
			}
		}
		s[u]=true;
		for(int j=1;j<=n;j++){
			if((!s[j])&&(c[u][j]<maxint))
			{//Find points that hasn't passed 
			//but has a path to the current point
				Type newdist=dist[u]+c[u][j];
				if(newdist<dist[j])
				{//If you find a shorter road, replace it
					dist[j]=newdist;
					prev[j]=u;
				}
			}
		}
	}
}
int main()
{
	cout<<"Please enter the number of points and the number of edges:"<<endl;
	int n,v;
	cin>>n>>v;
	int c[100][100];
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
			c[i][j]=maxint;
	}
	cout<<"Please enter edges:"<<endl;
	for(int i=0;i<v;i++)
	{
		int a,b,w;
		cin>>a>>b>>w;
		c[a][b]=w;
	} 
	int dist[100];
	int prev[100];
	Dijkstra(n,1,dist,prev,c);
	cout<<"Please enter the end point:";
	int x;
	cin>>x;
	cout<<"The shortest path length:"<<dist[x];
	return 0;
} 
