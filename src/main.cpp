extern "C"{
    // Add the header files required to run your main
    #include "../include/linked_list.h"
}
#include <stdio.h>
#include <stdlib.h> // free


// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    // testing print_list function:
    node * p = NULL; // linked list starts out empty
    p = insert(p,2);
    p = insert(p,4);
    p = insert(p,8);
    p = insert(p,3);
    p = insert(p,399);
    printf("\nTest #1 of print_list function:\n");
    print_list(p); // should print "2 4 8 3 399"
    free(p);

    // testing print_list function:
    node *ns = NULL;
    	ns = make_node (1,
			make_node (2,
				   make_node (3,
					      make_node (4,
							  make_node (5,
								    NULL)))));
     printf("\nTest #2 of print_list function:\n");
    print_list(ns);
    free_list(ns);

    // testing sum_squares function:
    node * q = NULL;
    q = insert(q,1);
    q = insert(q,2);
    q = insert(q,3);
    q = insert(q,4);
    q = insert(q,5);
    int sum = sum_squares(q);
    printf("\nTest of sum_squares function:\n sum = %d", sum);

    return 0;
}