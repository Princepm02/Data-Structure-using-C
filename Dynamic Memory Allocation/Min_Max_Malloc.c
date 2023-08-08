#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *a,i,n,min,max;
    printf("Enter the no. of integers : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("Enter the value of a[%d] : ",i);
        scanf("%d",&a[i]);
    }
    min=max=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            max=a[i];
    }
    printf("\nMin : %d \t Max : %d",min,max);
}

