#include <stdio.h>
#include <stdlib.h>
#define size 10

void push (int value);
void pop();
void display();

int s[size],top=-1;

void main()
{
    int value,choice;
    while(1)
    {
        printf("\n****MENU****\n\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        { 
            case 1 : printf("Enter the value to be inserted : ");
                     scanf("%d",&value);
                     push(value);
                     break;
            case 2 : pop();
                     break;
            case 3 : display();
                     break;
            case 4 : printf("\n****Exit****\n");
                     exit(0);
            default : printf("\nInvalid Choice!!! Try Again!!!");
        }
    }
}

void push(int value)
{ 
    if(top==size-1)
     printf("\nStack is Full!! Insertion is not possible!!!");
    else
    {
        top++;
        s[top]=value;
        printf("\n%d Element is inserted in stack",s[top]);
    }
}
void pop()
{
    if(top==-1)
     printf("\nStack is Empty!!! Deletion is not possible!!!");
    else
    {
        printf("Deleted element : %d",s[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
     printf("\nStack is Empty!!!");
    else
    {
        int i;
        printf("Representation of Element in Stack\n");
        for(i=top;i>=0;i--)
         printf("%d\n",s[i]);
    }
}
