/*
 * selectionProcess.h
 *
 *  Created on: Nov 10, 2015
 */


int process(char *path, int corner) {
	
	int i;
	int n;
	int counter = 0;
	int greyed;
	
	int x;
	int y;
	
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
	
	
	
	if(corner == 0){ //topleft corner
		for (i = 0; i < 3*(header.Width)*(header.Height - y); i+=3){
			
			
		}

		for (n = i; n < 3*(header.Width)*(header.Height); n+=3){
			
			if((counter % (header.Width)) >= (header.Width - x)){
				
			}
			
			else
			{
				greyed = ((imageArray[n] + imageArray[n+1] + imageArray[n+2])/3);
				imageArray[n] = imageArray[n+1] = imageArray[n+2] = greyed;
			}
			counter++;
		}
			
	}
	
	else if(corner == 1){ // top right corner
		for (i = 0; i < 3*(header.Width)*(header.Height - y); i+=3){
			
			
		}

		for (n = i; n < 3*(header.Width)*(header.Height); n+=3){
			
			
			if((counter % (header.Width)) <= (header.Width - x)){
				
			}
			
			else
			{
				greyed = ((imageArray[n] + imageArray[n+1] + imageArray[n+2])/3);
				imageArray[n] = imageArray[n+1] = imageArray[n+2] = greyed;
			}
			counter++;
		}
			
	}
	
	else if(corner == ){ // bottom left
		for (i = 0; i < 3*(header.Width * y); i+=3){

			if((counter % (header.Width)) <= x){
				greyed = ((imageArray[n] + imageArray[n+1] + imageArray[n+2])/3);
				imageArray[n] = imageArray[n+1] = imageArray[n+2] = greyed;	
			}
			
			else	{

			}
			counter++;
			
		}	
	}
	else if(corner == 3){ // bottom right
		for (i = 0; i < 3*(header.Width * y); i+=3){
			
			if((counter % (header.Width)) <= (header.Width - x)){
				
			}
			
			else
			{
				greyed = ((imageArray[n] + imageArray[n+1] + imageArray[n+2])/3);
				imageArray[n] = imageArray[n+1] = imageArray[n+2] = greyed;
			}
			counter++;
			
		}	
			
	}
		
	
	
	
	//processImageData(&header, &imageArray, x, y, corner);
	
	//Make output filename
	char *init = "images/output/";
	char *fileEnd = "_processed.bmp";
	char *underScore = "_";
	char *conPath1 = basename(path);
	conPath1[strcspn(conPath1, ".")] = '\0';
	convertedPath = malloc(strlen(init)+strlen(conPath1)+strlen(underScore)+strlen(fileEnd)+1);
	strcpy(convertedPath, init);
	strcat(convertedPath, conPath1);
	strcat(convertedPath, underScore);
	strcat(convertedPath, fileEnd);
	
	// Create a new file named newImage and set the path to images/converted.bmp
	FILE *newImage;
	newImage = fopen(convertedPath,"wb");

	// write data to new file.
	putBMP(&header, imageArray, newImage);
	
	//close the open image
	fclose(newImage);
	
	// Print success!
	printf("\nSuccess! Output: %s\n", convertedPath);
	return 0;
}


/*int processImageData(struct BitMapHeader *HeaderInfo, unsigned char **array, int x, int y, int corner){
	
	int i;
	int n;
	int counter = 0;
	int greyed;
	*array = (unsigned char*) malloc(HeaderInfo->Size);
	if(corner == 0){ //topleft
		
	}
	else if(corner == 1){
		for (i = 0; i < 3*(HeaderInfo->Width)*(HeaderInfo->Height - y); i+=3){
			
			
		}

		for (n = i; n < 3*(HeaderInfo->Width)*(HeaderInfo->Height); n+=3){
			
			
			if((counter % (HeaderInfo->Width)) <= (HeaderInfo->Width - x)){
				
			}
			
			else
			{
				greyed = *array[n];
			}
			counter++;
		}
			
	}
	
	else if(corner == 2){
	}
	
	else if(corner == 3){
	}
	
	
	else{
		printf("Error verifying corner input\n Exiting...\n");
		exit(0);
	}
}*/
