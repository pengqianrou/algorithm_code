#include<stdio.h>

int main()
{
     int array1[3][4]={{1,1,1,2},{2,2,3,3},{3,4,4,4}};
     int array2[4][3]={{1,1,1},{2,2,2},{3,3,3},{4,4,4}};
     int array3[3][3];
     for(int i=0;i<3;i++){
         for(int j=0;j<3;j++)
         {
             for(int k=0;k<4;k++)
             {
                 array3[i][j]=array1[i][k]*array2[k][j];
             }
         }
     }
     for(int i=0;i<3;i++){
         for(int j=0;j<3;j++)
         {
             printf("%d",array3[i][j]);
         }
         printf("\n");
     }
 
     return 0;
}
