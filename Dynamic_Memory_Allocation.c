//Dynamic Memory Allocation
//WAP to read and print n integer
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i,n,*ptr;
    printf("\nEnter Array Size : ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("\nEnter %d integer : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("\nIntegers entered are : ");
    for(i=0;i<n;i++)
    {
        printf(" %d ",ptr[i]);
    }
    
}
