/*
 * run.h
 *
 *  Created on: Nov 10, 2015
 */

//Figure out which action the user wants to run, and ask which files they want to process for those actions.
void run(char *action) { 
	char file[100];
	char file2[100];
	int corner = 0;
	
	//If the user picks subtract
	if(strcmp(action,"subtract") == 0){
		
 		printf("\nEnter the filename of the image you would like to subtract from:\n");
		
		//Get first file
 		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		//Make sure file is valid
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}
		
		printf("\nEnter the filename of the image you would like to use to subtract:\n");
		
		//Get second file
		fgets(file2,sizeof(file2),stdin);
		file2[strcspn(file2, "\n")] = '\0';
		
		//Make sure file is valid
		while(checkFile(file2)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file2,sizeof(file2),stdin);
			file2[strcspn(file2, "\n")] = '\0';
		}
		
		subtract(file, file2);
	}
	
	//If the user picks sharpen
	else if(strcmp(action,"sharpen") == 0){
		printf("\nEnter the path of the image you would like to sharpen:\n");
		
		//Get file
		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		//Make sure file is valid
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}
		
		sharpen(file);
	}
	//If the user picks process
	else if(strcmp(action,"process") == 0){
		printf("\nEnter the path of the image you would like to process:\n");
		
		//Get file
		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		//Make sure file is valid
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}
		
		printf("\nFrom which corner do you want to select?\n");
		printf("Input: \n0 for top left \n1 for top right \n2 for bottom left \n3 for bottom right\n");
		
		//Get input
		scanf("%d",&corner); 
		while(!((corner == 1) || (corner == 0) || (corner == 2) || (corner == 3)) ){
			printf("\nNot a valid corner choice. Try Again \n");
			scanf("%d",&corner); 
		}
		printf("success\n");
		process(file, corner);
	}
	//if user picks rainbow
	else if(strcmp(action,"prison") == 0){
		printf("\nEnter the path of the image you would like to put into prison:\n");
		
		//Get file
		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		//Make sure file is valid
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}

		prison(file);  
	}
	//If the user types exit, then quit the program.
	else if(strcmp(action,"exit") == 0){
		printf("\nExiting...\n");
		exit(0);
	}
	//
	else{
		printf("\nError verifying input. \nExiting...\n");
		exit(0);
	}
}


