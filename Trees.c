// 20201CSE0828 
// Prince Mishra

#include<stdio.h>
#include<stdlib.h>
struct list
{
  int data;
  struct list *left;
  struct list *right;
};
typedef struct list *TREE;
TREE createlocation ()
{
  TREE temp;
  temp = (TREE) malloc (sizeof (struct list));
  return (temp);
}

TREE insert (TREE root, int item)	// recursive function
{
  TREE temp;
  temp = createlocation ();
  temp->data = item;
  if (root == NULL)		// binary tree is completely empty
    {
      temp->left = NULL;
      temp->right = NULL;
      root = temp;
    }
  else
    {
      if (root->data > item)
	        root->left = insert (root->left, item);
      else
	        root->right = insert (root->right, item);
    }
  return (root);
}

void inorder (TREE root)
{
  if (root != NULL)
    {
      inorder (root->left);
      printf (",%d", root->data);
      inorder (root->right);
    }
}

void preorder (TREE root)
{
  if (root != NULL)
    {
      printf (" ,%d", root->data);
      preorder (root->left);
      preorder (root->right);
    }
}

void postorder (TREE root)
{
  if (root != NULL)
    {
      postorder (root->left);
      postorder (root->right);
      printf ("%d\t", root->data);
    }
}

void main ()
{
  TREE root = NULL;
  int choice, item;
  for (;;)
    {
      printf("Enter the Chocie\n");
      printf("1:Insert \t 2: inorder \t 3: preorder \t 4: postorder \t 5: Exit\n");
      scanf ("%d", &choice);
      switch (choice)
      {
    	case 1 :   printf ("Enter the item\n");
            	   scanf ("%d", &item);
            	   root = insert (root, item);
            	   break;
    	case 2 :   inorder (root);
            	   break;
    	case 3 :   preorder (root);
            	   break;
    	case 4 :   postorder (root);
            	   break;
    	case 5 :   exit (0);
    	default:   printf ("invalid option \n");
      }
    }
}

