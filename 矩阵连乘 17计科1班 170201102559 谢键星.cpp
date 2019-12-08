#include <iostream>
using namespace std;
#define error 0
void MatrixChain(int*p,int n,int**m,int **s)
{
   for(int i=1;i<=n;i++)
		m[i][i]=0;
		for(int r=2;r<=n;r++)
		{
		  for(int i=1;i<=n-r+1;i++)
		   {
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			  for(int k=i+1;k<j;k++)
			  {
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t;
					s[i][j]=k;
				}
			  }	
		    }
		}
}

int main(){
	int **m=new int*[15];
	for(int i=0; i<15; i++)
        m[i]=new int[15];
        
        int p[7] = {30,35,15,5,10,20,25};
        int **s=new int*[10];
    for(int i=0; i<15; i++)
       
        s[i]=new int[15];
         MatrixChain(p,6,m,s);
          for(int i = 1;i <7;i++)
		  {
           for(int j = 1;j <7;j++)
		   {
                if(j<i)
				{
                    cout<<"       ";
                }
				else
				{
                    cout<<m[i][j]<<" | ";
                }
            }
        cout<<endl;
    }
    
return 0;
	
}
 
	
