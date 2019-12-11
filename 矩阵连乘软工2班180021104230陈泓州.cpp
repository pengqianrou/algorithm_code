//矩阵连乘 
#include <iostream>
using namespace std;
void MatrixChain(int p[],int n,int m[][15],int s[][15]){
	//p是用于存放矩阵行列数的数组,n是矩阵数,m是最优值数组 
	//s是记录最优断开位置的数组 
	for(int i = 1;i <= n;i++)
	m[i][i] = 0;
	for(int r = 2;r <= n;r++){	//r是段长 
		for(int i = 1;i <= n-r+1;i++){	//i是段起点 
			int j = i + r-1;	//j是段终点 
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];		//i处分裂 
			s[i][j] = i;	//初始化 
			for(int k = i + 1; k < j;k++){		//在k处分裂,遍历各种k的情况 
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j]){		//如果当前方案更好,则刷新 
					m[i][j] = t;
					s[i][j] = k;		//m[i][j]记录 
				}
			}
		}
	} 
}

void Traceback(int i,int j,int s[][15]){
	if(i == j)
	return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<", "<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
}

int main(){
	int m[15][15] = {0};
	int s[15][15] = {0};
	int p[20] = {0};
	int n;
	cout<<"请输入矩阵个数:"<<endl;
	while(cin>>n)
	{
		cout<<"分别输入"<<n<<"个矩阵的行数和列数:"<<endl;
		for(int i = 1;i <= n;i++)
		{
			int a,b;
			cin>>a>>b;
			if(i == 1)	//判断并保存矩阵行数列数 
			{
				p[0] = a;
				p[1] = b;
			}
			else if(a == p[i-1])
				p[i] = b;
			else if(b == p[i-1])
				p[i] = a;
			else
			{
				cout<<"输入的矩阵不符合条件."<<endl;
				break;
			}
		}
		MatrixChain(p,n,m,s);
		cout<<"最少的数乘次数:"<<m[1][n]<<"."<<endl;
		Traceback(1,n,s);
		cout<<endl; 
		cout<<"请输入矩阵个数:"<<endl;
	}
	return 0;
	 
} 
