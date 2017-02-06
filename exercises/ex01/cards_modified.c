/*
	Card game counter
	Goh Chong Swee
	5 Feb 2017
*/


#include<stdio.h>
#include<stdlib.h>
/*	Function name: updatecount
	Description: 
		Updates count(by address) based on value of val. 
	Inputs: 
		1. Int by address count, 
		2. Int by value val;
	Outputs:
		Nil
*/
void updatecount(int *count,int val){
	if ((val>2) && (val <7)){
			puts("Adding");
			(*count)++;
		} else if (val == 10){
			puts("minus");
			(*count)--;
		}
}

/*	Function name: scan_card
	Description: 
		Prompts user to enter card name,
		Saves card name into array which is input as arg 
	Inputs: 
		1. Character array to contain card's name
	Outputs:
		Nil
*/
void scan_card(char *card_name){
	puts("Enter the card_name: ");
	scanf("%2s" ,card_name);
}

/*	Function name: update_value
	Description: 
		updates val based on content of card_name
	Inputs: 
		1. Character array to contain card's name
		2. int val (passed by address) 
	Outputs:
		Nil
*/
int update_value(char *card_name,int *val){
	switch (card_name[0]){
			case 'K':
			case 'Q':
			case 'J':
				(*val) = 10;
				break;
			case 'A':
				(*val) = 11;
				break;
			case 'X':
				return 1;
			default:
				(*val) = atoi(card_name);
				if (((*val) < 1) || ((*val) >10)){
					puts("I don't understand that value!");
					return 1;
				}
			}
	return 0;
}

/*	Function name: main
	Description: 
		where the main function runs
	Inputs: 
		Nil.
	Outputs:
		0
*/
int main(){
	char card_name[3];
	
	int count = 0;
	
	while (card_name[0] != 'X'){
			int val = 0;

		scan_card(card_name);
		
		
		
		if(update_value(card_name,&val)){
			continue;
		}
		updatecount(&count,val);
		printf("Current count : %i\n",count);
	}
	return 0;
}
