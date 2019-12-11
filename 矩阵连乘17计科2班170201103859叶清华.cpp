#include <iostream>
using namespace std;
void MatrixChain(int p[6],int n,int m[][7],int s[][7])
{
	for(int i=1;i<=n;i++)
	    m[i][i]==0;
	for(int r=2;r<=n;r++)
	for(int i=1;i<=n-r+1;i++)
	{
	    int j=i+r-1;
	    m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
	    s[i][j]=i;
	    for(int k=i+1;k<j;k++)
	    {
	        int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
	        if(t<m[i][j]){
	            m[i][j]=t;
	            s[i][j]=k;
	        }
	   }
	}
}
void TraceBack(int i,int j, int s[][7])
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        TraceBack(i,s[i][j],s);
        TraceBack(s[i][j]+1,j,s);
        cout<<")";
    }
	/*
    if(i==j) return;
    TrackBack(i,s[i][j],s);
    TrackBack(s[i][j]+1,j,s);
    cout<<"Multiply A "<<i<<","<<s[i][j]; 
    cout<<" and A "<<(s[i][j]+1)<<","<<j<<endl;
    */
}
int main()
{
   int n=6;
   int p[]={30,35,15,5,10,20,25};
   int s[7][7]={0};
   int m[7][7]={0};
   MatrixChain(p,n,m,s);
   TraceBack(1,n,s);
}
