#include <stdio.h>
void selectionsort(int L[],int n)
{
    int i,j,min,temp;
	for (i=0;i<n-1;i++)
    {
        min=i;
        for (j=i+1;j<n;j++)
          	if (L[j]<L[min])
            	min=j;
		temp=L[min];
		L[min]=L[i];
		L[i]=temp;
    }
	for (i=0;i<n;i++)
		printf("%d ",L[i]);
	printf("\n");
}
void insertionsort(int L[],int n)
{
	int i,j,key;
    for (i=0;i<n;i++) 
	{
		key=L[i];
        for (j=i-1;j>=0 && L[j]>key;j--)
            L[j+1]=L[j];
        L[j+1]=key;
    }
	for (i=0;i<n;i++)
		printf("%d ",L[i]);
	printf("\n");
}
void heapsort(int L[],int n)
{
    int i,l,prnt,ptr,item,last,left,right;
    for (i=0;i<n;i++)
	{
		item=L[i];
		for (ptr=i;ptr>0;ptr=prnt)
		{
			prnt=ptr/2;
			if (item<=L[prnt])
			{
				L[ptr]=item;
				break;
			}
			L[ptr]=L[prnt];
		}
		if (ptr==0)
			L[0]=item;
	}
	for (l=n-1;l>0;l--)
	{
		item=L[0],last=L[l],ptr=0,left=1,right=2;
		while (right<=l)
		{
			if (last>=L[left] && last>=L[right])
			{
				L[ptr]=last;
				break;
			}
			else if (L[right]<=L[left])
			{
				L[ptr]=L[left];
				ptr=left;
			}
			else
			{
				L[ptr]=L[right];
				ptr=right;
			}
			left=2*ptr;
			right=left+1;
		}
		if (right>l)
			L[ptr]=last;
		L[l]=item;
	}
	for (i=0;i<n;i++)
		printf("%d ",L[i]);
	printf("\n");
}
int* mergesort(int L[],int low,int up)
{
	int i,j,k,mid,M[20];
	if (up>low)
	{
		mid=(low+up)/2;
		mergesort(L,low,mid);
		mergesort(L,mid+1,up);
		i=low,j=mid+1,k=low;
		while (i<=mid && j<=up)
		{
			if (L[i]<L[j])
			{
				M[k]=L[i];
				i++;
			}
			else
			{
				M[k]=L[j];
				j++;
			}
			k++;
		}
		while (i<=mid)
		{
			M[k]=L[i];
			i++;
			k++;
		}
		while (j<=up)
		{
			M[k]=L[j];
			j++;
			k++;
		}
		for (i=low;i<=up;i++)
			L[i]=M[i];
	}
	return L;
}
int* quicksort(int L[],int left, int right)
{
	int i,temp,loc;
	if (left<right)
	{
		int l=left,r=right;
		while (l<r)
		{
			for (loc=l;L[loc]<=L[r] && loc<r;r--);
			if (L[loc]>L[r])
			{
				temp=L[loc];
				L[loc]=L[r];
				L[r]=temp;
				l++;
			}
			for (loc=r;L[loc]>=L[l] && loc>l;l++);
			if (L[loc]<L[l])
			{
				temp=L[loc];
				L[loc]=L[l];
				L[l]=temp;
				r--;
			}
		}
		quicksort(L,left,loc-1);
		quicksort(L,loc+1,right);
	}
	return L;
}
void main()
{
    int cont=1,n,op,i,L[20],*S;
    printf("Enter no.of terms in list: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for (i=0;i<n;i++)
        scanf("%d",&L[i]);
	printf("Sorting operations:");
    while (cont)
    {
        printf("\nEnter preferred operation\n1.Insetion sort\n2.Selection sort\n3.Heap sort\n4.Merge sort\n5.Quick sort\n6.Exit\nEnter option: ");
        scanf("%d",&op);
        switch(op)
        {
        	case(1):printf("Insertion sorted elements: ");
                    insertionsort(L,n);
        			break;
        	case(2):printf("Selection sorted elements: ");
                    selectionsort(L,n);
        			break;
        	case(3):printf("Heap sorted elements: ");
                    heapsort(L,n);
        			break;
        	case(4):printf("Merge sorted elements: ");
                    S=mergesort(L,0,n-1);
					for (i=0;i<n;i++)
						printf("%d ",*(S+i));
					printf("\n");
        			break;
        	case(5):printf("Quick sorted elements: ");
                    S=quicksort(L,0,n-1);
					for (i=0;i<n;i++)
						printf("%d ",*(S+i));
					printf("\n");
        			break;
        	case(6):cont=0;
                    break;
            default:printf("Invalid option");
        }
    }
}
