/*
 * run.h
 *
 *  Created on: Nov 10, 2015
 */
void run(char *action) { 
	char file[100];
	char file2[100];
	
	if(strcmp(action,"subtract") == 0){
		
 		printf("Enter the filename of the image you would like to subtract from:\n");
		
 		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}
		
		printf("Enter the filename of the image you would like to use to subtract:\n");
		
		fgets(file2,sizeof(file2),stdin);
		file2[strcspn(file2, "\n")] = '\0';
		
		while(checkFile(file2)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file2,sizeof(file2),stdin);
			file2[strcspn(file2, "\n")] = '\0';
		}
		
		//subtract(file, file2);
	}
	else if(strcmp(action,"sharpen") == 0){
		printf("Enter the path of the image you would like to sharpen:\n");
		
		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}
		
		//sharpen(file);
	}
	else if(strcmp(action,"process") == 0){
		printf("Enter the path of the image you would like to process:\n");
		
		fgets(file,sizeof(file),stdin);
		file[strcspn(file, "\n")] = '\0';
		
		while(checkFile(file)){
			printf("\nInvalid File. or path too long. Try Again \n");
			
			fgets(file,sizeof(file),stdin);
			file[strcspn(file, "\n")] = '\0';
		}
		
		//process(file);
	}
	else if(strcmp(action,"exit") == 0){
		printf("Exiting...\n");
		exit(0);
	}
	else{
		printf("Error verifying input");
		exit(0);
	}
}


