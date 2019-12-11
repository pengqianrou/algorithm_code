import java.util.Scanner;

public class matrixMultiply {
    public static void main(String[] args){
        int ra,ca,rb,cb;
        System.out.println("输入第一个矩阵的列数和行数：");
        Scanner scan = new Scanner(System.in);
        ra=scan.nextInt();
        ca=scan.nextInt();
        int a[][]= new int[ra][ca];
        System.out.println("输入第一个矩阵：");
        for(int i=0;i<ra;i++){
            for(int j=0;j<ca;j++){
                a[i][j]=scan.nextInt();
            }
        }
        System.out.println("输入第二个矩阵的列数和行数：");
        rb=scan.nextInt();
        cb=scan.nextInt();
        int b[][]= new int[rb][cb];
        System.out.println("输入第二个矩阵：");
        for(int i=0;i<rb;i++){
            for(int j=0;j<cb;j++){
                b[i][j]=scan.nextInt();
            }
        }
        int c[][]=new int[ra][cb];
        if(ca!=rb){
            System.out.println("这两个矩阵不能相乘");
        }
        else {
            for(int i=0;i<ra;i++){
                for(int j=0;j<cb;j++){
                    int sum=a[i][0]*b[0][j];
                    for(int k=1;k<ca;k++){
                        sum=sum+a[i][k]*b[k][j];
                    }
                    c[i][j]=sum;
                }
            }
            System.out.println("相乘的结果：");
            for(int i=0;i<ra;i++){
                for(int j=0;j<cb;j++){
                    System.out.print(c[i][j]);
                    System.out.print(" ");
                    if(j==cb-1){
                        System.out.println(" ");
                    }
                }
            }
        }
    }
}
