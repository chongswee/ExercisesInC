/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void free_anything(int *p) {
    free(p);
}


int read_element(int *array, int index) {
    int x = array[index];
    printf("%d\n",x);
    return x;
}


int main ()
{
    int never_allocated;

    int *free_twice;
    free_twice = (int*)malloc (sizeof(int));

    int *use_after_free;
    use_after_free =(int*)malloc (sizeof(int));

    int *never_free;
    never_free = (int*)malloc (sizeof(int));

    //int array1[100];
    int *array1;
    array1 = (int*)malloc (100 * sizeof(int));

    int *array2;
    array2 = (int*)malloc (100 * sizeof(int));

    // valgrind does not bounds-check static arrays
    read_element(array1, 0);
    read_element(array1, 99);

    // but it does bounds-check dynamic arrays
    read_element(array2, 0);
    read_element(array2, 99);

    // and it catches use after free
    free(use_after_free);
  //  *use_after_free = 17;
    *never_free = 17;

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    //free_anything(&never_allocated);

    free(free_twice);
    free(never_free);

    free(array2);
    free(array1);

    return 0;
}
