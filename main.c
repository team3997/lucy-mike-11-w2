/*
 * main.c
 *
 *  Created on: Nov 10, 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmpHeader.h"
#include "options.h"
#include "run.h"
#include "subtract.h"
#include "sharpen.h"
#include "process.h"
#include "checkFile.h"



int main() {
	
	char action[10];
	
	listOptions();
	
	fgets(action, sizeof(action), stdin);
	action[strcspn(action, "\n")] = '\0';
	
	while(!(strcmp(action,"subtract") == 0 || strcmp(action,"sharpen") == 0 || strcmp(action,"process") == 0 || strcmp(action,"exit") == 0)){
		printf("\nThat's not a valid option. Try again:\n");
		
		fgets(action, sizeof(action), stdin);
		action[strcspn(action, "\n")] = '\0';
	}
	run(action);
	

	return 0;
}

