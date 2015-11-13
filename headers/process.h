/*
 * selectionProcess.h
 *
 *  Created on: Nov 10, 2015
 */


int process(char *path, int corner) {
	
	const int x;
	const int y;
	int i;
	char *convertedPath;
	
	
	

	//Declare structures for header files of the two bitmaps
	struct BitMapHeader header;
	
	//declare arrays for pixel data of both images
	unsigned char *imageArray;
	
	//Grab data from file1, and put it into our header structure(header1) and pixel array (imageArray1)
	FILE *imageFile = fopen(path, "rb"); // open file specified as path 1
	grabBMP(&header, &imageArray, imageFile, 1); //take all the data from the file 
	fclose(imageFile); // close file 
	
	printf("Enter how far in the x direction you want to select\n");
	scanf("%d",&x); 
	while((x>header.Width) || (x<1)){
		printf("\nThe specified width is greater than the image width (selection must also be greater than 0).\nTry Again \n");
		scanf("%d",&x); 
	}
	
	printf("Enter how far in the y direction you want to select\n");
	scanf("%d",&y); 
	while((y>header.Width) || (y<1)){
		printf("\nThe specified height is greater than the image height (selection must also be greater than 0).\nTry Again \n");
		scanf("%d",&y); 
	}
	
	
	
	processImageData(&header, &imageArray, x, y, corner);
	
	
	//Make output filename
	char *init = "images/output/";
	char *fileEnd = "_subtract.bmp";
	char *underScore = "_";
	char *conPath1 = basename(path1);
	char *conPath2 = basename(path2);
	conPath1[strcspn(conPath1, ".")] = '\0';
	conPath2[strcspn(conPath2, ".")] = '\0';
	convertedPath = malloc(strlen(init)+strlen(conPath1)+strlen(underScore)+strlen(conPath2)+strlen(fileEnd)+1);
	strcpy(convertedPath, init);
	strcat(convertedPath, conPath1);
	strcat(convertedPath, underScore);
	strcat(convertedPath, conPath2);
	strcat(convertedPath, fileEnd);
	
	// Create a new file named newImage and set the path to images/converted.bmp
	FILE *newImage;
	newImage = fopen(convertedPath,"wb");

	// write data to new file.
	putBMP(&header1, &imageArray1, newImage);
	
	//close the open image
	fclose(newImage);
	
	// Print success!
	printf("\nSuccess! Output: %s\n", convertedPath);
	return 0;
}


int processImageData(struct BitMapHeader *HeaderInfo, unsigned char **array, int x, int y, int corner){
	
	
	
	if(corner == 0){
		for (x = 0; x < (HeaderInfo->Size); x++){
		}
	}
	}
	
	else if(corner == 1){
	}
	
	else if(corner == 2){
	}
	
	else if(corner == 3){
	}
	
	
	else{
		printf("Error verifying corner input\n Exiting...\n");
		exit(0);
	}
}