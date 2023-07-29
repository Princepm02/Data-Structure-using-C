// Queue and it's operation using array 
#include <stdio.h>
#include <stdlib.h>
#define qsize 5
int f=-1,r=-1;

void enqueue(int q[],int item);
void dequeue(int q[]);
void display(int q[]);

void main()
{
    int q[qsize],item,choice;
    for( ; ;)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("\nEnter no. to be inserted : ");
                     scanf("%d",&item);
                     enqueue(q,item);
                     break;
            case 2 : dequeue(q);
                     break;
            case 3 : display(q);
                     break;
            case 4 : exit(0);
            default : printf("\nInvalid choice!!!\n");
        }
    }
}

void enqueue(int q[],int item)
{
    if(r==qsize-1)
       printf("Queue is full!!");
    else
    {
        if(f==-1 && r==-1)
           f=r=0;
        else
           r++;
        q[r]=item;
    }
    return;
}

void dequeue(int q[])
{
    int item;
    if(f==-1 && r==-1)
       printf("\nQueue is Empty!!!");
    else
    {
        item=q[f];
        printf("%d is deleted from the queue",item);
        if(f==r)
           f=r=-1;
        else
           f++;
    }
    return;
}

void display(int q[])
{
    int i;
    if(f==-1 && r==-1)
       printf("\nQueue is Empty");
    else
    {
        printf("\nElement in Queue");
        for(i=f;i<=r;i++)
           printf(" %d ",q[i]);
    }
    return;
}
