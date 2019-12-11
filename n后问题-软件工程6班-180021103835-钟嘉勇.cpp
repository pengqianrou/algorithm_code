#include<stdio.h>
#include<stdlib.h> 

class Queen{
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(int t);
	int n;//皇后个数 
	int *x;//当前解 
	long sum;//当前已找到的可行方案数 
}; 
bool Queen::Place(int k){
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	}
	return true;
} //检查冲突，检查第k行的皇后与上方所有皇后是否冲突 
void Queen::Backtrack(int t){
	if(t>n)
		sum++;
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(Place(t))
				Backtrack(t+1);
		}
	}
}
int nQueen(int n){
	Queen X;//初始化x 
	X.n=n;
	X.sum=0;
	int *p=new int[n+1];//申请动态内存 
	for(int i=0;i<=n;i++){
		p[i]=0;
	}
	X.x=p;
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}

int main(){
	int m,n;
	printf("输入皇后个数：");
	scanf("%d",&n);
	m=nQueen(n);
	printf("有%d个方案",m);
	return 0;
}

