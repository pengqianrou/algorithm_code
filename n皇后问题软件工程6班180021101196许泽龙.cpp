#include <iostream>  
#include <cstring>  
#include<iomanip>
#include<cmath> 
#include<stdlib.h>
using namespace std; 
 
   class Queen
   { 
     friend int nQueen(int);
     private:
     	bool Place(int k);
     	void Backtrack(void);
    	 int n;         //皇后数
    	 int *x;       //  当前解
    	 long sum ;     //  当前已找到的可行方案数
   };
    bool Queen::Place(int k)
    {
    	for(int j=1;j<k;j++)
   			if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))return false;
  		 return true;
    }
   
void Queen::Backtrack(void)
{
   	x[1]=0;
   	int k=1;
   	while(k>0)
   	{
   		x[k]+=1;
   		while((x[k]<=n)&&!Place(k))
   		  x[k]+=1;
   		if(x[k]<=n)
   		  if(k==n)
	      {  sum++;
			 cout<<n<<"皇后问题的一个方案";
      		 for(int i=1;i<=n;i++)
         		 cout<<x[i]<<" ";
        	 cout<<endl;
		  }	
        
   		   else{
   			k++;
   			x[k]=0;
   		   }
   		else k--;
   	}
}
   
int nQueen(int n)
{
     Queen X;
	   //初始化X 
     X.n=n;
     X.sum=0;
     int *p=new int[n+1];
     for(int i=0;i<=n;i++)
	    p[i]=0;
     X.x=p;
     X.Backtrack();
     delete []p;
     return X.sum;
}
 

int main()
  {
     int n1=5;
     cout<<n1<<"皇后问题共有"<< nQueen(n1)<<"个解决方案";
     system("pause");
	 return 0;
  }

