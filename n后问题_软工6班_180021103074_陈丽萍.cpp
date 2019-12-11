#include<iostream> 
#include<math.h> 
using namespace std;
class Queen{
	friend int nQueen(int);
	private:
		bool Place(int k);
		void Backtrack(int t);
		int n,*x;
		long sum;
};
bool Queen::Place(int k){//检查与上行是否冲突 
	for(int j=1;j<k;j++)
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
		//检查这些皇后是否在同一行或者同一列 
			return false;
		return true;
}
void Queen::Backtrack(int t){//试探第i个皇后该放哪 
	if(t>n)//t为行号 
		sum++;
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;
			if(Place(t))
				Backtrack(t+1);
				//上行已完成皇后的放置，开始下行 
		}
	}
}
int nQueen(int n){
	Queen X;//初始化 
	X.n=n;
	X.sum=0;
	int *p=new int[n+1];//申请动态内存，不用p[0] 
	for(int i=0;i<=n;i++)
		p[i]=0;
	X.x=p;
	X.Backtrack(1);// 试探第1 行皇后放哪 
	delete[] p;//释放整个数组 
	return X.sum;//返回合法方案数 
}
int main(){
	int n;
	cout<<"请输入想求的n皇后问题的n："<<endl;
	cin>>n;
	int k=nQueen(n);
	cout<<"请输出n皇后问题互不攻击放置方案数："<<endl;
	cout<<k<<endl;
	return 0;
}
