#include <iostream>    
#include <cmath>     
#include <time.h>
#include "RandomNumber.h"     
using namespace std;    
  
class Queen  
{  
    friend bool nQueen(int,int);  
private:  
    bool Place(int k);//���Իʺ�k���ڵ�x[k]�еĺϷ���  
    bool Backtrack(int t);//��n������Ļ��ݷ�  
    bool QueensLV(int stopVegas);//�������n���ʺ���˹ά��˹�㷨  
    int n,*x,*y,sv;  
};  
  
bool Queen::Place(int k)  
{//���Իʺ�k���ڵ�x[k]�еĺϷ��� (��k��,��x[k]��) 
    for(int j=1;j<k;j++)  
        if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])) //ͬһб��||ͬһ�� 
            return false;  
    return true;  
}  

bool Queen::Backtrack(int t)  
{//��n������Ļ��ݷ������ݳ��Իʺ�λ�ã�tΪ��t�� 
    if(t>n){  //���ûʺ��������nʱ�� �����н����+1 
        for(int i=1;i<=n;i++)  
            y[i]=x[i];  
        return true;  
    }  
    else  
        for(int i=1;i<=n;i++)  
        {  
            x[t]=i;  //��t���ʺ���ڵ�i�� 
            if(Place(t)&&Backtrack(t+1)) //����place���ͼ�������һ�� 
                return true;  
        }  
        return false;  
}  
  
bool Queen::QueensLV(int stopVegas)  
{//�������n���ʺ���˹ά��˹�㷨  
    RandomNumber rnd;  
    int k=1;//�����������  
    int count=1;  
    //1<=stopVegas<=n��ʾ����������õĻʺ���  
    while((k<=stopVegas)&&(count>0))  
    {  
        count=0;  
        for(int i=1;i<=n;i++)  
        {  
            x[k]=i;  
            if(Place(k))  
                y[count++]=i;  //��¼�����п��Է��õ�λ�� 
        }  
        if(count>0)  
            x[k++]=y[rnd.Random(count)];//����ܷ��ã����ѡ��һ�����Է��õ�λ��  
    }  
    return (count>0);//count>0��ʾ���óɹ�  
}  
  
bool nQueen(int n,int sv)  
{  
    //����ݷ����ϵĽ�n���������˹ά��˹�㷨  
    Queen X;  
    //��ʼ��X  
    X.n=n;  
    //X.sv=sv;
    int *p=new int[n+1];  //��̬���� 
    int *q=new int[n+1];  
    for(int i=0;i<=n;i++)  //��ʼ������ 
    {  
        p[i]=0;  
        q[i]=0;  
    }  
    X.y=p;  
    X.x=q;  
    int stop=sv;  
    if(n>15)  
        stop=n-15;  
    bool found=false;  
    while(!X.QueensLV(stop));  
    //�㷨�Ļ�����������  
    if(X.Backtrack(stop+1))  
    {  
        for(int i=1;i<=n;i++)  
            cout<<p[i]<<" ";  
        found=true;  
    }  
    cout<<endl;  
    delete []p;  
    delete []q;  
    return found;  
}  
int main()    
{   
    int n,sv;
    cout<<"����ʺ����n �� stopVrgasֵ"<<endl; 
    while(cin>>n>>sv){
    
       clock_t start,end,over;
       start=clock();
       end=clock();
       over=end-start;
       start=clock();
    
       if(!nQueen(n,sv))  
       {  
           cout<<"No Answer"<<endl;  
       }  
    
      	end=clock();
      	cout<<"The time is "<<(double)(end-start-over)/CLK_TCK<<endl;    
        cout<<endl;	
        
    } 

//    system("pause");  
    return 0;  
}  
