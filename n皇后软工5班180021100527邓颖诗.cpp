#include <iostream>
#include <algorithm> 
using namespace std;
class Queen{
	friend int nQueen(int);
	private:
		bool Place(int k);//Judging function
		void Backtrack(int t);
		int n,*x;//n is the number of Queen,
		//x is the position of the Queen on line i 
		long sum;//feasible situation
};
bool Queen::Place(int k){
	for(int j=1;j<k;j++)
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	return true;
	//If it does not conflict with the position 
	//of any queen in front of it
}
void Queen::Backtrack(int t){
	if(t>n)//N queens have been set
		sum++;
	else{
		for(int i=1;i<=n;i++){
			x[t]=i;//Try every position
			if(Place(t))
			//If there is no conflict, 
			//go to the next level
				Backtrack(t+1);
		}
	}
}
int nQueen(int n){
	Queen X;
	X.n=n;
	X.sum=0;
	int *p=new int[n+1];
	for(int i=0;i<=n;i++)
		p[i]=0;
	X.x=p;
	//Initialization
	X.Backtrack(1);
	delete[] p;
	return X.sum; 
}
int main()
{
	cout<<"Please enter the number of Queen:"<<endl;
	int n;
	cin>>n;
	int result=nQueen(n);
	cout<<"The result is:"<<result;
	return 0;
} 
