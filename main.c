/*
 * main.c
 *
 *  Created on: Nov 10, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/bmpHeader.h"
#include "headers/options.h"
#include "headers/run.h"
#include "headers/subtract.h"
#include "headers/sharpen.h"
#include "headers/process.h"
#include "headers/checkFile.h"



int main() {
	
	char action[100];
	
	// List the user's options
	listOptions();
	
	//Get input from the user on what action they would like to do.
	fgets(action, sizeof(action), stdin);
	action[strcspn(action, "\n")] = '\0';
	
	//While they do not select a valid option, reprompt them.
	while(!(strcmp(action,"subtract") == 0 || strcmp(action,"sharpen") == 0 || strcmp(action,"process") == 0 || strcmp(action,"exit") == 0)){
		printf("\nThat's not a valid option. Try again:\n");
		
		fgets(action, sizeof(action), stdin);
		action[strcspn(action, "\n")] = '\0';
	}
	
	//Now that a valid option has been selected, go ahead and run it.
	run(action);
	

	return 0;
}
