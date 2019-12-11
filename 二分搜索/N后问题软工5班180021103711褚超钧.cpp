#include<stdio.h>
#include<math.h>
int x[9]={0};
bool PLACE(int k)//检测第k个皇后能否放进棋盘
{
    int i=1;
    while(i<k)
    {
        if(x[i]==x[k]||fabs(x[i]-x[k])==fabs(i-k))
            return false;
        i++;
    }
    return true;
}
void NQUEENS(int n)
{
    int i,k=1; //k为当前行号
    x[1]=0;//x[k]为第k行皇后所放的列号
    while(k>0)
    {
        x[k]++;
        while(x[k]<=n&&!PLACE(k))//该行不符合，则放入下一行
          x[k]++;
        if(x[k]<=n)
        {
            if(k==n)//输出x[]
            {
                for(i=1;i<=n;i++)
                    printf("x[%d]:%d  ",i,x[i]);
                printf("\n");
            }

            else//判断下一行
            {
                k++; x[k]=0;
            }
        }
        else k--;//没找到，则回溯
    }
    return ;
}
int main()
{
    NQUEENS(8);
    return 0;
}
