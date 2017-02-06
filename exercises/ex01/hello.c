#include <stdio.h>
int main()
{
    printf("Hello World\n");
	/*
	With Optimization, and without printing, the variable is not declared 
		at all, because the variable is not utilized  
	
	Without Optimization, the variable is declared in assembly
		language, but not used. (hence redundant step/memory) 
	*/
	int x = 5;
	
	/*
	With Optimization, the compilation process processed 
		the addition step ( 5 + 1 )
	Without Optimization, the addition is processed 
		in assembly language
	*/
	int y = x + 1;
	printf("%d",y);
}

/* 
Otimization work by processing more data during the compilation process, 
	rather than execution process( which is in assembly code).
	> Increase in steps in compilation
	> Reduction in steps in assembly language
	
This will lengthen the time taken to compile, but will result in a faser program 
	by using less memory and steps as illustrated in this exercise (line 7) 
*/
