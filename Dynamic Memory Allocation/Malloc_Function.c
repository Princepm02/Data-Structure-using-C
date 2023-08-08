//Demo of malloc() function, to store marks of n students and calculate average marks
#include <stdio.h>
#include <stdlib.h>

void main()
{
    float *ptr,sum=0;
    int i,n;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    //Allocate memory to store n float values
    ptr = (float*)malloc(n*sizeof(float));
    //If dynamic allocation failed exit the program
    if(ptr == NULL)
    {
        printf("\nMemory allocation failed!!!");
        exit(1); //Exit the program
    }
    for(i=0 ; i<n ; i++)
    {
        printf("\nEnter the marks for %d student : ",i+1);
        scanf("%f",(ptr+i));
    }
    for(i=0 ; i<n ; i++)
    {
        sum += *(ptr+i);
    }
    printf("\nAverage marks = %5.2f ",sum);
    free(ptr);
    return;
}


