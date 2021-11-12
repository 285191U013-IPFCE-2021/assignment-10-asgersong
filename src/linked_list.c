#include "../include/linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
node *free_list (node * p) // changed function signature from "void" to "node *"
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
  return q;
}

/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    // There is NO testcode for this

    if (p == NULL) // simple case #1 for when end of linked-list is set to point to NULL
      printf("\n");

    else
    {
      printf("%d ", p -> value); // first print the value of the first node in linked list
      print_list(p -> next); // recursive step for next nodes until we reach end of linked list
    }

}

int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp
    if (p == NULL) // simple case #1
      return 0;

    if (p -> next == NULL) // simple case #2
      return square(p -> value);

    else 
      return square(p -> value) + sum_squares(p -> next); // recursive step
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    if (p == NULL) // simple case
      return NULL;
    // else
      return (make_node((*f)(p -> value), map(p -> next, f))); // recursive step
    
  }


int square (int x)
{
  return x * x;
}

// insert function used in test case in main.cpp
// inserts node at the end of linked list
node *insert (node * p, int val)
{
  node * temp = malloc (sizeof (node));
  temp -> value = val;
  temp -> next = NULL; // make sure that end of list still is NULL
  if (p == NULL) // if list is empty
    p = temp;
  else
  {
    node *temp1 = p;
    while (temp1 -> next != NULL) // wait until temp1 is at the end of linked list before inserting
      temp1 = temp1 -> next;
    temp1 -> next = temp;
  }
  
return p;
}
