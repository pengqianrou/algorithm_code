#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int sum=0;
bool Place(int k,int i,int *x);
void backtrack(int k,int n,int *x);;
void NQueens(int n,int *x);

int main()
{
	int N;
	cout<<"qing shu ru huang hou de ge shu"<<endl;
	cin>>N;
    int x[N];
  
    for(int i=0;i<N;i++) x[i]=-1;
    NQueens(N,x);
    cout<<sum<<endl;
    while(1)
	{
	 } 
    return 0;
}

bool Place(int k,int i,int *x) 
{
   for (int j=0;j<k;j++)
   if ((x[j]==i)||(abs(x[j] -i)==abs(j-k))) 
   return false;
   return true;
}
void backtrack(int k,int n,int *x) 
{
    for (int i=0;i<n;i++)
    {
        if(Place(k,i,x))                            
        {
            x[k]=i;
            if (k==n-1)    
            {
                sum++;
                
                cout<<endl;
            }
            else
            {
               backtrack(k+1,n,x);
            }
       }
    }
}
void NQueens(int n,int *x)
{
     backtrack(0,n,x);
}

