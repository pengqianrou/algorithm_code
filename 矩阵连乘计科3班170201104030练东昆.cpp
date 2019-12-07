
#include <iostream> 
using namespace std; 

const int len = 7;
int MatrixChain(int n,int **m,int **s,int *p); 
void Traceback(int i,int j,int **s);

int main(){
	int p[len]={1,2,3,4,5,6,7};
    int **s = new int *[len];
	int **m = new int *[len];
	for(int i=0;i<len;i++)  {  
		s[i] = new int[len];
		m[i] = new int[len];
    } 
	cout<<"The minimum number of calculation of the matrix is:"<<MatrixChain(6,m,s,p)<<endl;
	cout<<"The optimal calculation order of matrix is:"<<endl;
	Traceback(1,6,s);
	return 0;
}

int MatrixChain(int n,int **m,int **s,int *p){
	int resulent;
	for(int i=1; i<=n; i++){
		m[i][i] = 0;
	}
	for(int r=2; r<=n; r++) {
		for(int i=1; i<=n-r+1; i++){
			int j = i+r-1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; 
			s[i][j] = i;
			for(int k=i+1; k<j; k++){  
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
					resulent = t;
				}
			}	
		}
	}
	return resulent;
}

void Traceback(int i,int j,int **s){
	if(i==j){
		return;
	}
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<" Mulentipleny A "<<i<<", "<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<<", "<<j<<endl;
}
