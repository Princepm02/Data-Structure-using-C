/*
Que:- Mr. Anil at any givenpoint of time has 5 friends. He maintains list of his friends that contains only friend's age. 
Every time a new friend is added an old friend is deleted.
Select a suitable data stucture and design functions to help Mr. Anil maintain up to-dated list.

I am using Circular Queue
*/

#include <stdio.h>
#include<stdlib.h>
#define Qsize 5
int f=-1,r=-1;

void newage(int q[],int age)
{
   if(((f==0)&&(r==Qsize-1)) || (f==r+1))
   {
       f=(f+1)%Qsize;
       r=(r+1)%Qsize;
       q[r]=age;
   }
   else
   {
       if((f==-1)&&(r==-1))
       {
            f=(f+1)%Qsize;
            r=(r+1)%Qsize;
       }
       else
       {
            r=(r+1)%Qsize;
       }
       q[r]=age;
   }
   return;
}
void display(int q[])
{
    int i;
    if((f==-1) && (r==-1))
    {
        printf("\nQueue is Empty!!");
        return;
    }
    else
    {
        printf("\nAge of friends : ");
        if(r >= f)
        {
            for(i=f;i<=r;i++)
            {
                printf("%d\t",q[i]);
            }
        }
        else
        {
            for(i=f;i<Qsize;i++)
            {
                printf("%d\t",q[i]);
            }
            for(i=0;i<=r;i++)
            {
                printf("%d\t",q[i]);
            }
        }
    }
    return;
}
void main()
{
    int q[Qsize],age,choice;
    for( ; ; )
    {
        printf("\n1. Insert age \n2. Display \n3.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the age : ");
                     scanf("%d",&age);
                     newage(q,age);
                     break;
            case 2 : display(q);
                     break;
            case 3 : exit(0);
            default : printf("\nInvalid Choice!!!!");
                      break;
        }
    }
}




