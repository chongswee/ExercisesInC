/*

	Base code Retrieved from
	https://github.com/AllenDowney/SoftwareSystems.git

	Editted by 
	Goh Chong Swee
	6 Feb 2017

*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int *foo() {
    int i;
	
	//without static, an error will occur since the memory is deallocated once the function ends. 
	//Adding static solves the problem - this kinda declares the variable as global in the static segment
    int static array[SIZE];

	// prints the address of the array 
   // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];
	
	// prints the address of the array 
    //printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
	// declared just for the "for loop" 
	// alternatively, it can be declared within the for loop such that memory frees when the loop ends 
    int i;
	
	//attempts to return an array address, to a pointer
	//array is declared in foo, hence it is dealloated once it exit foo ( if it is not declared as static)
	int *array = foo();
	
	//does not serve any purpose since void does not return any data, and no data is passed from main to the function bar. 
	//void function can serve the purposes of printing data etc, or editing global variables. 
    bar();

	// loop to print the contents in array based on its size 
    for (i=0; i<SIZE; i++) {
		printf("%d\n", array[i]);
    }

    return 0;
}