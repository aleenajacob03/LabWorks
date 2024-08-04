import java.util.*;

public class quicksort{
    int A[]=new int[50];
    int l;
    quicksort(int L[],int n){
        l=n;
        for (int i=0;i<n;i++)
            A[i]=L[i];
        sort(0,l-1);
        display();
    }
    int partition(int left,int right){
        int loc=left,temp;
        while (left<right){
            for (loc=left;A[loc]<=A[right] && loc<right;right--);
            if (A[loc]>A[right]){
                temp=A[loc];
                A[loc]=A[right];
                A[right]=temp;
                left++;
            }
            for (loc=right;A[loc]>=A[left] && loc>left;left++);
            if (A[loc]<A[left]){
                temp=A[loc];
                A[loc]=A[left];
                A[left]=temp;
                right--;
            }
        }
        return loc;
    }
    void sort(int left,int right){
        int p;
        if (left<right){
            p=partition(left,right);
            sort(left,p);
            sort(p+1,right);
        }
    }
    void display(){
        for (int i=0;i<l;i++)
            System.out.print(A[i]+" ");
    }
    public static void main(String[] args){
        int L[]=new int[50];
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter no.of elements: ");
        int n=sc.nextInt();
        System.out.print("Enter values: ");
        for (int i=0;i<n;i++)
            L[i]=sc.nextInt();
        quicksort q=new quicksort(L,n);
    }
}
