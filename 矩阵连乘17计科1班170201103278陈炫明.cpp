#include<iostream>

using namespace std;
#define MaxSize 20

void MatrixChain(int *p, int n, int m[][MaxSize], int s[][MaxSize]){  
	int i,j,r,k;
	int t; 
	for(i = 1; i <= n; i++){ 
		m[i][i]= 0;           
	}
	
	for(r = 2; r <= n; r++){           
		for(i = 1; i <= n-r+1; i++){   
			j = i + r - 1;            
			m[i][j] = m[i+1][j] + p[i-1] * p[i] * p[j];     
			s[i][j] = i; 
			for(k = i+1; k < j; k++){
				t =  m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];     
				if(t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			} 
		}
	} 
	cout<<endl<<"最优乘法次数："<<m[1][n]<<endl;
}

void TraceBack(int i,int j, int s[][MaxSize]){   
	if(i < j-1){
		TraceBack(i,s[i][j],s);
		TraceBack(s[i][j]+1,j,s);
		cout<<"Matrix A"<<i<<" , "<<s[i][j]<<"and A"<<s[i][j]+1<<" , "<<j<<endl; 
	}
} 

int main(){
	int m[MaxSize][MaxSize],      
		s[MaxSize][MaxSize];     
		
	int p[MaxSize]; 
	int n;	
	do{
		cout<<"请输入矩阵连乘的矩阵个数（2到20）n = ";
		cin>>n;
	}while(n < 2 || n > 20);
	
	cout<<"请依次输入n个矩阵的行数及最后一个矩阵的列数（输入n+1个数）：" <<endl;
	for(int i = 0; i < n+1; i++){
		cin>>p[i];
	} 
	
	MatrixChain(p,n,m,s); 
	TraceBack(1,n,s); 	
}
