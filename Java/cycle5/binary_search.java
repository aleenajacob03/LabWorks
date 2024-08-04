import java.util.*;
public class binary_search{
	public static void main(String[] args) {
		int i;
		int A[]=new int[10];
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter no.of terms in array: ");
		int n=sc.nextInt();
		System.out.print("Enter sorted array: ");
		for (i=0;i<n;i++)
			A[i]=sc.nextInt();
		System.out.print("Enter element to search: ");
		int key=sc.nextInt();
		int first=0,last=n-1;
		while (first<=last)
		{
			int mid=(first+last)/2;
			if (key>A[mid])
				first=mid+1;
			else if (key<A[mid])
				last=mid-1;
			else
			{
				System.out.println("Eleement found at position "+(mid+1));
				break;
			}
		if (first>last)
			System.out.println("Element not found");
		}
	}
}
