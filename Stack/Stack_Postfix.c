#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define STACK_SIZE 20

void push (int item, int *top, int a[])
{
  *top = *top + 1;		//a[++*top] = item; 
  a[*top] = item;
}

int pop (int *top, int a[])
{

  int item;
  item = a[*top];
  *top = *top - 1;
  return item;
}

int calculate (int op1, int op2, char symbol)
{

  switch (symbol)

    {

    case '+':
      return (op1 + op2);

    case '-':
      return (op1 - op2);

    case '*':
      return (op1 * op2);

    case '/':
      return (op1 / op2);

    }

}

int
main ()
{



  int a[100], i, top = -1, op1, op2, res;

  char exp[20], symbol;

  printf ("Enter postfix expression \n");

  scanf ("%s", exp);

  for (i = 0; i < strlen (exp); i++)

    {

      symbol = exp[i];

      if (isdigit (symbol))

	{

	  push (symbol - '0', &top, a);

	}

      else

	{

	  op2 = pop (&top, a);

	  op1 = pop (&top, a);

	  res = calculate (op1, op2, symbol);

	  push (res, &top, a);

	}

    }

  printf ("Result of evaluation of expression is %d\n", a[top]);

}
