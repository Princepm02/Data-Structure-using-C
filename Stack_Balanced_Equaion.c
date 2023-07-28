//This program will check that the given equation has balanced expression or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

void main()
{
    char stk[max],ex[100];
    int top,i;
    top=-1;
    printf("Enter an infix expression\n");
    gets(ex);
    for(i=0;ex[i]!='\0';i++)
    {
        if(ex[i]=='(' || ex[i]=='[' || ex[i]=='{')
        {
            top++;
            stk[top]=ex[i];
        }
        else if(ex[i]==')')
        {
            if(stk[top]=='(')
            {
                top--;
            }
            else
            {
                printf("Unbalanced expression\n");
                exit(0);
            }
        }
        else if(ex[i]==']')
        {
            if(stk[top]=='[')
            {
                top--;
            }
            else
            {
                printf("Unbalanced expression\n");
                exit(0);
            }
        }
        else if(ex[i]=='}')
        {
            if(stk[top]=='{')
            {
                top--;
            }
            else
            {
                printf("Unbalanced expression\n");
                exit(0);
            }
        }
    }
    if(top==-1)
      printf("expression is balanced\n");
    else
      printf("expression is not balanced\n");
}
