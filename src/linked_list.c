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

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    // There is NO testcode for this

    if (p == NULL) // simple case #1
      return;
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
    return -1;
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    return NULL;
}


int square (int x)
{
  return x * x;
}

// insert function used in test case in main.cpp
// inserts node at the end of linked list
node *insert (node * p, int val)
{
  node * temp = (struct node*)malloc(sizeof(struct node));
  temp -> value = val;
  temp -> next = NULL;
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
