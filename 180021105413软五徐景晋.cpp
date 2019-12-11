#include <iostream>
#include <cmath>
using namespace std;
//皇后的个数,方案数目
int n,sum=0;
//记录放置方案
int x[100];//不能这样定义int *x;
//用户递归求取方案
void Queen1(void);
void TraceBack(int);
void PrintMethod(void);
//检查这一皇后放置方案是否满足要求
int Place(int);

int main()
{


 cout << "输入皇后个数：" << endl;
 cin>>n;
 Queen1();
 return 0;
}

void Queen1(void)
{
TraceBack(0);
}
void TraceBack(int r)
{
 int i;
 if(r>=n){
 PrintMethod();//这个函数的正确性还没有得到验证
 sum++;
}
 else{
 for(i=0;i<n;i++){
 x[r]=i;//在下一行判断当前路是不可行的之后，进入同级的另外的路径
if(Place(r))//先试探当前这条路是可行的，则进入下一步循环
TraceBack(r+1);
} }
}
void PrintMethod(void)
{
 int i,j;
 cout<<"第"<<sum<<"个方案\n";
 for(i=0;i<n;i++){
for(j=0;j<n;j++){
 if(j==x[i])
cout<<"1";
 else
cout<<"0";
 }
 cout<<endl;
 }
}
int Place(int r)
{
 int i;
 for(i=0;i<r;i++)
 {
 if(x[r]==x[i] || abs(r-i)==abs(x[r]-x[i]))//在此处判断皇后走的下一步路是否可行，如果不可行性，return 0；
 return 0;
}
 return 1;
}

