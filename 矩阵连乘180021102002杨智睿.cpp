
/*

特征：计算A[i:j]的最优次序所包含的计算矩阵子链 A[i:k]和A[k+1:j]的次序也是最优的。

矩阵连乘计算次序问题的最优解包含着其子问题的最优解。这种性质称为最优子结构性质。

问题的最优子结构性质是该问题可用动态规划算法求解的显著特征。

 */

 

#include<iostream>

#include<iomanip> 

#include<memory.h>

using namespace std;

//求出矩阵A[i:j]的最少数乘次数m[i][j]，和记录矩阵A[i:j]此时的断开位置s[i][j]

void MatrixChain(int *p, int n, int m[100][100], int s[100][100] )

{

        for (int i = 1; i <= n; i++) m[i][i] = 0; //初始化，使用矩阵的下标从1，1开始        

		for (int r = 2; r <= n; r++)

           for (int i = 1; i <= n - r+1; i++) {

              int j=i+r-1;

              m[i][j] = m[i+1][j]+ p[i-1]*p[i]*p[j];

              s[i][j] = i;

              for (int k = i+1; k < j; k++) {

                 int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];

                 if (t < m[i][j]) { m[i][j] = t; s[i][j] = k;}

              }

          }

}

 

//利用断开位置s[i][j]输出矩阵A[i:j]的最优加括号方式

void print_optimal(int s[100][100], int i ,int j, int a[])

{

	if(i==j)	cout<<" A["<<a[i-1]<<","<<a[i]<<"]";

	else{

		cout<<" ( ";

		print_optimal(s,i,s[i][j],a);

		print_optimal(s,s[i][j]+1,j,a);

		cout<<" ) ";

	}

}

 

void putout(int a[100][100], int n)

{

	int i,j;

	for(i=1;i<=n;i++){

		for(j=1;j<=n;j++)

			cout<<setw(6)<<a[i][j];

		cout<<endl;

	}

}

 

int main()  

{   

	int n,k; 

	int array[100], m[100][100], s[100][100];

	memset(array,0,sizeof(array));

	memset(m,0,sizeof(m));

	memset(s,0,sizeof(s));

 

	while(1)

	{

		cout<<endl<<"输入矩阵的个数 "<<endl; 

		cin>>n;  

		if(n<=0)break;

		

		cout<<"请输入 "<<n+1<<" 个正整数，分别是各个矩阵的行列数"<<endl;  

		for(k=0;k<n+1;k++)  

			cin>>array[k];  

		cout<<endl; 

		cout<<"原始数据为以下矩阵"<<endl;

		for(k=0;k<n;k++)

			cout<<endl<<setw(3)<<array[k]

			<<" * "<<setw(3)<<array[k+1];  

		cout<<endl; 

 

		MatrixChain(array,n,m,s); 

		

		cout<<"m矩阵"<<endl; 

		putout(m,n);

 

		cout<<"s矩阵"<<endl; 

		putout(s,n);

		

		cout<<endl<<"最优的运算方式的乘法次数为: "<<m[1][n]<<endl

			<<"加括号的方式为："<<endl;

		print_optimal(s,1,n,array);

		

	}

	return 0;

}

