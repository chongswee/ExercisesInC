/*
    TEE in C
    Written by CS Goh
    Take in lines from standard input and write to standard output, as well as to a specified file.
*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int interupts = 1;
char filemode[1] = "w";

/*
    Prints information on how to use this code
*/
void printhelp(){
	puts("Tee written by CS Goh");
	puts("Only supports -a (append)");
	puts("EG command : ls | tee -a listfile.txt");
	puts("Without -a it will (create and) write to the file, erasing previous data");
}

// Prints version - just for fun
void printversion(){
	puts("Tee version 1");
}

/*
    Truncates the string at the first newline, if there is one.
    Taken from :
        Example code for Exercises in C.
        Modified version of an example from Chapter 2.5 of Head First C.
*/
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
			case 'a' : {    // Append option
				strcpy(filemode ,"a") ;
				continue;
				}
			case 'i' : {    // check for -i, but not implemented
				interupts = 0;
				continue;
				}
			case 'h':{  // Help option
				printhelp();
				continue;
			}
			case 'v' :{ // Check version option
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

    // informs the user the file name
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
