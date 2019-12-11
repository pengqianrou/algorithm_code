#include <iostream>
using namespace std;




void MatrixChain(int *p,int n,int **m,int **s)	//计算最少次数 
{
	for(int i=1;i<=n;i++)    
	    m[i][i]=0;           //和自己不用计算 
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n-r+1;i++)
		{		
		   int j=i+r-1;
		   m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];   //计算第i个到第j个最优 
		   s[i][j]=i;
		   for(int k=i+1;k<j;k++)
		   {
		   	  int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
		   	  if(t<m[i][j])               
		   	  {
		   	     m[i][j]=t;
			     s[i][j]=k;				  	//第i个到第j个最优的断裂位置 
			  }
		   }
		}
	}
 
}

void Traceback(int i,int j,int **s,int **m)
{
	if(i==j) return;
	Traceback(i,s[i][j],s,m);
	Traceback(s[i][j]+1,j,s,m);
	
	if(i==s[i][j])
	    cout<<"计算A"<<i;
	else	
	    cout<<"计算A"<<i<<"~"<<s[i][j];
	if(s[i][j]+1==j)
	    cout<<"和A"<<j<<"的乘积"<<endl;		    
	else
	    cout<<"和A"<<(s[i][j]+1)<<"~"<<j<<"的乘积"<<endl;	
}

int main()
{
int *p,n,**m,**s;
	cout<<"请输入大于1的矩阵数量"<<endl;
	cin>>n;
	while(n<=1)
	{
	   cout<<"请输入大于1的矩阵数量"<<endl;
	   cin>>n;
	}
	
	p=new int[n+1];
	m=new int*[n+1];
	s=new int*[n+1];
	
	for(int i=0;i<=n;i++)
	{
		m[i]=new int[n+1];
		s[i]=new int[n+1];		
	}
	
	cout<<"请输入"<<n<<"个矩阵的维度数："<<endl;
	for(int i=1;i<=n;i++) //只需给出单数的维度 
	{
        
        if(i==1)
        {
        	cout<<"p"<<i-1<<"=";
        	cin>>p[i-1];    
			while(p[i-1]<=0)
			{
			    cout<<"请输入合法的数（大于1的整数）";
			    cout<<"p"<<i-1<<"=";
        	    cin>>p[i-1];    
			} 	
		}
         	cout<<"p"<<i<<"=";
        	cin>>p[i];
			while(p[i]<=0)
			{
			    cout<<"请输入合法的数（大于1的整数）";
			    cout<<"p"<<i<<"=";
        	    cin>>p[i];    
			} 	  

        cout<<"A["<<i<<"]="<<p[i-1]<<"*"<<p[i]<<endl<<endl;
        

	} 

	
	MatrixChain(p,n,m,s);
	cout<<"对于m[1]["<<n<<"]来说最优值为："<<m[1][n]<<"次"<<endl<<endl;


	cout<<"下面输出最优的计算次序"<<endl;
	Traceback(1,n,s,m);
	
	delete []p;
	delete []m;
	delete []s; 
	return 0;
}
