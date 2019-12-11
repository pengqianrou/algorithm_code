#include <stdio.h>
#include <math.h>
#define N 20
class Queen{
	friend int nQueen(int);
	private:
		bool Place(int k);
		int Backtrack(int t);
		int n,
		*x;
		long sum;
};
bool place(int k)
{
	int x[k];
for(int j=1;j<k;j++)
if(abs(k-j)==abs(x[k]-x[j])||x[k]==x[j])
return 0;
return 1;
}
int Backtrack(int t)
{
	int n,sum,x[t];
if(t>n)
sum++;
else
for(int i=1;i<=n;i++)
{
x[t]=i;
if(place(t))
    Backtrack(t+1);
}
}
int nQueen(int n){
	Queen X;
	int x=0;
	X.n=n;
	X.sum=0;
	int *p=new int[n+1];
	for(int i=0;i<=n;i++)
	    p[i]=0;
	    X.x=p; 
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}
int main()
{
	int n;
    printf("Please input n:");
    scanf("%d",&n);
    printf("%d\n",Backtrack(1));
    return 0;
}
