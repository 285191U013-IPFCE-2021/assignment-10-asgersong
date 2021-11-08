extern "C"{
    // Add the header files required to run your main
    #include "../include/linked_list.h"
}
#include <stdio.h>


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
    printf("\nTesting print_list function:\n");
    print_list(p); // should print "2 4 8 3 399"

    return 0;
}