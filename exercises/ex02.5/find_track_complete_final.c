/* Example code for Exercises in C.
Modified version of an example from Chapter 2.5 of Head First C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<regex.h>
#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
	if (strstr(tracks[i], search_for)) {
	    printf("Track %i: '%s'\n", i, tracks[i]);
	}
    }
}

/*
	Finds all tracks that match the given pattern.
	Prints track number and title. 
*/
void find_track_regex(char pattern[])
{
    int i = 0; // used for looping
    int status; // used to indicate status of regex execution 
    regex_t re; // declare regex object
	
	// creating regex pattern. 
	char regexpattern[100];
	strcpy(regexpattern,"^.*");
	strcat(regexpattern,pattern);
	strcat(regexpattern,".*$");
	// pattern can be " ^.*[search_for].*$ 
	// ^ indicates the start of the string $ indicates the end (.*) refers to any number of character or digits 
	
	if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
	    puts("Error 1");
	    return;      /* report error */
	}
	for(i=0;i<NUM_TRACKS;i++){
		status = regexec(&re, tracks[i], (size_t) 0, NULL, 0);
		if (status != 0) { // if doesn't match, go to next track.
		    continue;
		}
		printf("Track %i: '%s'\n", i, tracks[i]);
	}		
	
	// frees up re
	regfree(&re);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    find_track_regex(search_for);

    return 0;
}