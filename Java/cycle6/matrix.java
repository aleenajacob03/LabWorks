import java.util.*;
public class matrix{
    int r,c;
    int mat[][]=new int[10][10];
    matrix(int m,int n,int M[][]){
        r=m;
        c=n;
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                this.mat[i][j]=M[i][j];
        display(this);
    }
    static void add(matrix A,matrix B){
        int R[][]=new int[10][10];
        for (int i=0;i<A.r;i++)
            for (int j=0;j<A.c;j++)
                R[i][j]=A.mat[i][j]+B.mat[i][j];
        System.out.println("Result matrix:");
        new matrix(A.r,A.c,R);
    }
    void display(matrix M){
        for (int i=0;i<M.r;i++){
            for (int j=0;j<M.c;j++)
                System.out.print(M.mat[i][j]+" ");
            System.out.println();
        }
    }
    public static void main(String[] args) {
        int M[][]=new int[10][10];
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter no.of rows and columns of matrix 1: ");
        int m=sc.nextInt();
        int n=sc.nextInt();
        System.out.println("Enter values:");
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                M[i][j]=sc.nextInt();
        System.out.println("Matrix 1:");
        matrix A=new matrix(m,n,M);
        System.out.print("Enter no.of rows and columns of matrix 2: ");
        m=sc.nextInt();
        n=sc.nextInt();
        System.out.println("Enter values:");
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                M[i][j]=sc.nextInt();
        System.out.println("Matrix 2:");
        matrix B=new matrix(m,n,M);
        if (A.r==B.r && A.c==B.c)
            add(A,B);
        else
            System.out.println("Addition not possible");
    }
}
