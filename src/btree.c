#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

int get_min_right (struct tree_node * t)
{
  struct tree_node * temp = t;

  while(temp -> left != NULL)
    temp = temp -> left;
  
  return temp -> item;
}

struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t

  // create temporary tree_node which's item field will be given the value x 
  // and its right and left branches will be nullpointers
  struct tree_node * temp = malloc(sizeof(struct tree_node));
    temp -> item = x;
    temp -> left = NULL;
    temp -> right = NULL;

  if (t == NULL) // simple case
    return temp;
  
  // recur down the tree either left or right depending on x
  if (x > t -> item) // larger than => go right
    t -> right = Insert(x, t -> right); // recursive step

  else // smaller than or equal => go left
    t -> left = Insert(x, t -> left); // recursive step

  // return unchanged tree_node pointer
  return t;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t


  if (t == NULL) // simple case
    return t;
  else if (t -> item > x) // then x must be present in the right subtree
    t -> left = Remove (x, t -> left);

  else if (t -> item < x) // then x must be present in the left subtree
    t -> right = Remove (x, t -> right);

  
  else // if t -> item == x
  // replace the tree_node with NULL by returning NULL to the calling pointer.
  {
    // case #1: both left and right is NULL => replace the node with NULL
    if (t -> left == NULL && t -> right == NULL)
    {
      free(t);
      return NULL;
    }

    // case #2: tree_node has either only left or right => replace the tree_node with left/right
    else if (t -> left == NULL || t -> right == NULL)
    {
      struct tree_node * temp = t -> left;
      if (t -> right == NULL)
        temp = t -> left;
     
      else
        temp = t -> right;
      
      free(t);
      return temp;
    }

    // case #3: tree_node has both left and right => find min. right -> item,
    // replace "tree_node -> item" with min.,
    // and again call the Remove function with t -> right to delete the node which has the min. item
    // since we find the min. value from the right subtree.
    else
    {
    int min_right = get_min_right(t -> right);
    t -> item = min_right;
    t -> right = Remove(min_right, t -> right);
    }

  }
  return t;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.

  if (t == NULL) // simple case #1 (if tree is empty, it does not contain x)
    return 0;

  else if (t -> item == x) // simple case #2 
    return 1;

  else if (x > t -> item)
    return Contains(x, t -> right);
  
  else // if (x < t -> item)
    return Contains(x, t -> left);
}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree
  return t = NULL;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  if (t == NULL)
    return 1;
  // else
  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full

    // binaray tree of singly-linked lists can never be full. One can always insert more nodes.
    return 0; // 0 is false
}

