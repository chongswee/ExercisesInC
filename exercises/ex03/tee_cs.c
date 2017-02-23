/*
TEE in C 
3) Reflect: what worked, what slowed you down? What would you do differently next time?
	WORKED: The redirection of the std output of 'ls' command to tee worked, and it output to stdout, as well as the file. 
		Arguments input worked (-a , -h,-v (which i wrote for fun)))
	SLOWED: Initially I was unsure of how similar this should be to tee, for example the errors and interupts which i did not understand. 
		I also thought of allowing output to multiple files ( which i did not do in the end) and that slowed me down. 
		It would require the contents of the stdin to be saved in a long string, and then fprinted to each file input. 
		Also, in the switch case, initially i've forgotten to use "continue" which resulted in the execution of unwanted subsequent lines.
	As I've spent some time on this code, I think it is okay for its purpose. In the future, I would add more functions and input arguments, or error detection. 
4) Compare your solution to the real thing. What do you see in professional code that is not in your solution?
	The real thing did many error checking which i did not. Also, it made use of much more libraries. The actual code used "write" instead of fprint to the output streams. 
	It made use of a linked list structure declared to store the different outputs (file and stdout).

*/
#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>	

int interupts = 1; 
char filemode[1] = "w";
int debug = 0; // used to set debug = true to print error messages. 

void printhelp(){
	puts("Tee written by CS Goh");
	puts("Only supports -a (append)");
	puts("EG : ls | tee -a listfile.txt");
	puts("Without -a it will (create and) write to the file, erasing previous data");
}

void printversion(){
	puts("Tee version 1");
}


void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main(int argc, char *argv[]){
	char ch;			// for reading optarg 
	int i;			 	// for loop 
	char str[1000]; 	// to read input 
	
	while ((ch = getopt(argc, argv, "aivh")) != EOF){
		switch(ch) {
			case 'a' : {
				if (debug) 
					puts("case A"); 
				strcpy(filemode ,"a") ; 
				continue;
				}
			case 'i' : {
				if (debug) 
					puts("case I"); 
				interupts = 0; 
				continue;
				}
			case 'h':{
				printhelp();
				continue;
			}
			case 'v' :{
				printversion();
				continue;
			}
			default : {
				puts("Default case: Argument not recognised");
				continue;
			}
		}		
	}
	argc -= optind; // decrease count 
	argv += optind; // increment pointer 
	
		
	printf("Output written to %s \n", argv[0]);
	
		// Open file 
		FILE *one = fopen (argv[0], filemode);
		
		//write to file and stdout
		while ((fgets(str, sizeof str, stdin))){
			fprintf(one,"%s",str);
			printf("%s",str);
		}
		
		//closes file 
		fclose(one);
}
