#include<cstring>
#include<iostream> 
using namespace std;

int m[4][4],s[4][4]; 
void MartrixChain(int p[], int n){
	for(int i = 1; i <= n; i++) m[i][i] = 0;
	for(int r = 2; r <= n; r++){
		for(int i = 1; i <= n-r+1; i++){
			int j = i + r - 1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(int k = i + 1; k < j; k++){
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}

void Traceback(int i, int j){
	if(i == j) return;
	Traceback(i, s[i][j]);
	Traceback(s[i][j]+1, j);
	cout<<"矩阵 A("<<i<<","<<s[i][j] << ")";
	cout<<" 与 B(" <<(s[i][j]+1)<<","<<j<<")连乘"<<endl;
}

int main(){
	int a[8]={12,31,42,43,4,5,23};
	cout<<"计算矩阵大小为：";
	for(int i = 0; i <= 4; i++) cout<<a[i]<<" ";
	MartrixChain(a,4);
	cout<<endl;
	cout<<"矩阵的最小连乘次数为"<<m[1][4]<<endl;
	Traceback(1,4);
}
