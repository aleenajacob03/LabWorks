import java.util.*;
public class heap_sort {
	int A[]=new int[50];
    int l;
	heap_sort(int L[],int n){
		l=n;
        for (int i=0;i<n;i++)
            A[i]=L[i];
        sort();
        display();
	}
	void sort(){
		for(int i=0;i<l;i++){
			int item=A[i],ptr,prnt;
			for(ptr=i;ptr>0;ptr=prnt){
				prnt=ptr/2;
				if (A[prnt]>item){
					A[ptr]=item;
					break;
				}
				A[ptr]=A[prnt];
			}
			if (ptr==0)
				A[ptr]=item;
		}
		for (int n=l-1;n>0;n--){
			int item=A[0],last=A[n],ptr=0,left=1,right=2;
			while (right<=n){
				if (last>A[left] && last>A[right]){
					A[ptr]=last;
					break;
				}
				else if (A[left]>A[right]){
					A[ptr]=A[left];
					ptr=left;
				}
				else{
					A[ptr]=A[right];
					ptr=right;
				}
				left=ptr*2;
				right=left+1;
			}
			if (right>n)
				A[ptr]=last;
			A[n]=item;
		}
	}
    void display(){
        for (int i=0;i<l;i++)
            System.out.print(A[i]+" ");
    }
    public static void main(String args[])
	{
		int L[]=new int[50];
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter no.of elements: ");
        int n=sc.nextInt();
        System.out.print("Enter values: ");
        for (int i=0;i<n;i++)
            L[i]=sc.nextInt();
        heap_sort q=new heap_sort(L,n);
	}
}
