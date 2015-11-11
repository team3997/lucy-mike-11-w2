/*
 * checkFile.h
 *
 *  Created on: Nov 10, 2015
 */



// Function that returns 0 if file is valid, and 1 if not valid
checkFile(char *path) { 
	
	//If the user inputs exit, then exit the program.
	if(strcmp(path,"exit") == 0){
		printf("Exiting...\n");
		exit(0);
	}
	
	// Check if file is valid.
	if (fopen(path, "rb") == NULL) {
		return 1;
	} 
	else{
		return 0;
	}
	
}


	