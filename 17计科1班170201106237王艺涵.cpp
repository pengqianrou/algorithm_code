#include<iostream>
#define MAX_SIZE 102
using namespace std;
template <class T>
int BinarySearch(T a[],const T&x,int n,int left,int right)
{
    if(left>=right)
        return -1;
    else
    {
        if(a[(left+right)/2]==x)
            return (left+right)/2;
        else if(x>=(left+right)/2)
            return BinarySearch(a,x,n,(left+right)/2+1,right);
        else if(x<(left+right)/2)
            return BinarySearch(a,x,n,left,(left+right)/2-1);
    }
}
int main()
{
    int a[MAX_SIZE];
    int i,len,x,p;
    cin>>len;
    for(i=0;i<len;i++)
        cin>>a[i];
    cin>>x;
    p=BinarySearch(a,x,len,0,len-1);
    if(p==-1)
        cout<<"该数不存在！"<<endl;
    else
    cout<<p+1<<endl;
    return 0;
}
