// Doubly Linked list
//20201CSE0828 Prince Mishra
#include<stdio.h>
#include<stdlib.h>
struct list
{
  int item;
  struct list *left, *right;
};
typedef struct list *LIST;
LIST
createnode ()
{
  LIST newnode;
  newnode = (LIST) malloc (sizeof (struct list));
  return (newnode);
}

LIST
insertfront (LIST first, int cost)
{
  LIST temp;
  temp = createnode ();
  temp->item = cost;
  if (first == NULL)		// inserting very first node
    {
      temp->right = NULL;
      temp->left = NULL;
      first = temp;
      return first;
    }
  temp->left = NULL;
  temp->right = first;
  first->left = temp;
  first = temp;
  return (first);
}

LIST
insertlast (LIST first, int cost)
{
  LIST cur, temp;
  temp = createnode ();
  temp->item = cost;
  if (first == NULL)		// inserting very first node
    {
      temp->right = NULL;
      temp->left = NULL;
      first = temp;
      return first;
    }
  cur = first;
  while (cur->right != NULL)
    {
      cur = cur->right;
    }
  temp->left = cur;
  temp->right = NULL;
  cur->right = temp;
  return (first);
}

LIST
deletefront (LIST first)
{
  LIST cur;
  if (first == NULL)
    {
      printf ("Doubly list is empty \n");
    }
  else if (first->right == NULL)
    {
      printf ("deleted item is %d\n", first->item);
      free (first);
      first = NULL;
    }
  else
    {
      cur = first;
      first = first->right;
      first->left = NULL;
      printf ("deleted item is %d\n", cur->item);
      free (cur);
    }
  return (first);
}

LIST
deletelast (LIST first)
{
  LIST cur, prev;
  if (first == NULL)
    {
      printf ("Doubly list is empty \n");
    }
  else if (first->right == NULL)
    {
      printf ("deleted item is %d\n", first->item);
      free (first);
      first = NULL;
    }
  else
    {
      cur = first;
      while (cur->right != NULL)
	{
	  prev = cur;
	  cur = cur->right;
	}
      printf ("Deleted item is %d\n", cur->item);
      free (cur);
      prev->right = NULL;
    }
  return (first);
}

void
display (LIST first)
{
  LIST cur;
  if (first == NULL)
    printf ("Doubly linked list is empty\n");
  else
    {
      printf ("Doubly linked list contains \n");
      cur = first;
      while (cur != NULL)
	{
	  printf ("%d\t", cur->item);
	  cur = cur->right;
	}
      printf ("\n");
    }
}

/*void displayreverse(LIST first)// exercise for students
{
if(first == NULL)
return;
else
{
displayreverse(first->right);
printf("%d\t", first->item);
}
} */
void
main ()
{
  int cost, choice;
  LIST first = NULL;
  for (;;)
    {
      printf ("\nEnter the Choice\n");
      printf
	("1: Insert Front\t2: Insert Last\t 3. Delete Front\n 4: Delete Last \t 5: Display \t 6: exit\n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  printf ("Enter the cost of item purchase\n");
	  scanf ("%d", &cost);
	  first = insertfront (first, cost);
	  break;
	case 2:
	  printf ("Enter the cost of item purchase\n");
	  scanf ("%d", &cost);
	  first = insertlast (first, cost);
	  break;
	case 3:
	  first = deletefront (first);
	  break;
	case 4:
	  first = deletelast (first);
	  break;
	case 5:
	  display (first);
	  break;
	case 6:
	  exit (0);
	default:
	  printf ("invalid option\n");
	}
    }
}

