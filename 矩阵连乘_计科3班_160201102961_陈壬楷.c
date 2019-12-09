void matrixChain(){
    for(int i=1;i<=n;i++)m[i][i]=0;

    for(int r=2;r<=n;r++)//对角线循环
        for(int i=1;i<=n-r+1;i++){//行循环
            int j = r+i-1;//列的控制
            //找m[i][j]的最小值，先初始化一下，令k=i
            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            //k从i+1到j-1循环找m[i][j]的最小值
            for(int k = i+1;k<j;k++){
                int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    //s[][]用来记录在子序列i-j段中，在k位置处
                        断开能得到最优解
                    s[i][j]=k;
                }
            }
        }
}