#include<stdio.h>
#include<iostream>
#include <cstdlib>
using namespace std;
class Queen {
	friend int nQueen(int);
private:
	bool Place(int k);
	void Backtrack(int t);
	int n;
	int *x;
	long sum;
};

bool Queen::Place(int k) {
	for(int j=1;j<k;j++)
		if(abs(k-j)==abs(x[j]-x[k])||(x[j]==x[k]))
			return false;
	return true;
}

void Queen::Backtrack(int t) {
	if(t>n)
		sum++;
	else {
		for(int i=1; i<=n; i++) {
			x[t]=i;
			if(Place(t))
				Backtrack(t+1);
		}
	}
}

int nQueen(int n) {
	Queen X;
	X.n=n;
	X.sum=0;
	int *p = new int [n+1];
	for(int i=0;i<=n;i++)
		p[i]=0;
	X.x=p;
	X.Backtrack(1);
	delete[] p;
	cout<<X.sum<<endl;//the book doesn't have this code ?
	return X.sum;
}


int main() {//the first method to print the nQueen problems
	int n;
	printf("please input how many n for the nQueen Problem:  ");
	scanf("%d",&n);
	nQueen(n); 
	
/*---------after the line 55, you can also use nQueen(detailed number) to print the result, but it just print what in brackets*/

/*	nQueen(4);
	nQueen(2);
	nQueen(3);
	nQueen(8);
	nQueen(7);
	nQueen(6);*/
	return 0;
}
