#include <stdio.h>
int bno(int dno)
{
    int bin=0;
    if ((dno/2)==0)
        return (dno%2);
    else
        return ((dno%2+(bno(dno/2))*10));
}
void main()
{
    int n,D[20],i;
    printf("Enter the no.of terms in list: ");
    scanf("%d",&n);
    printf("Enter the array: ");
    for (i=0;i<n;i++)
        scanf("%d",&D[i]);
    printf("The binary equvalent of the numbers are:[");
    for (i=0;i<n;i++)
        printf("%d ",bno(D[i]));
    printf("]\n");
}