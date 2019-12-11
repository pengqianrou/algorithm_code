#include <stdio.h>
int abs(int i){
	if(i<0)
	    return -i;
	else
	    return i;
}
class Queen{
    int nQueen(int); 
	public: 
	    bool Place(int k);
	    void Backtrack(int t);
	    int n,*x;
	    long sum;
}; 

bool Queen::Place(int k){
	for(int i=1;i<k;i++)
		if((abs(k-i)==abs(x[i]-x[k]))||(x[i]==x[k]))
		    return false;
	return true;
}

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
	Queen X;
	X.n=n;
	X.sum=0;
	int *p=new int [n+1];
	for(int i=0;i<=n;i++)
	    p[i]=0;
    X.x=p;
    X.Backtrack(1);
    delete[] p;
    return X.sum;
}
int main(){
	int n=4;
	printf("%d后问题的解法一共有%d种 ",n,nQueen(n));
}
