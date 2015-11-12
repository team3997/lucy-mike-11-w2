/*
 * subtract.h
 *
 *  Created on: Nov 10, 2015
 */


int subtract(char *path1, char *path2) {
	
	int x;
	int y;
	char *convertedPath;
	
	
	

	//Declare structures for header files of the two bitmaps
	struct BitMapHeader header1;
	struct BitMapHeader header2;
	
	//declare arrays for pixel data of both images
	unsigned char *imageArray1;
	unsigned char *imageArray2;

	//Grab data from file1, and put it into our header structure(header1) and pixel array (imageArray1)
	FILE *imageFile1 = fopen(path1, "rb"); // open file specified as path 1
	grabBMP(&header1, &imageArray1, imageFile1, 0); //take all the data from the file 
	fclose(imageFile1); // close file 
	
	//Grab data from file2, and put it into our header structure(header2) and pixel array (imageArray2)
	FILE *imageFile2 = fopen(path2, "rb"); // open file specificed as path 2
	grabBMP(&header2, &imageArray2, imageFile2, 0); //take all the data from the file 
	fclose(imageFile2); // close file 

	//if Image 2 has bigger width or height, terminate.
	if((header2.Width > header1.Width) || (header2.Height > header1.Height)){
		printf("\nThe image you are trying to subtract from is smaller than the image you are using to subtract!\n");
		printf("\nExiting...\n");
		exit(0);
	}
	
	
	// Subtraction ALGORITHIM (this replaces imageArray1 with the new pixel data)
	for (x = 0; x < (header2.Size); x++) //loops through each rgb value in each pixel
	{
		if(imageArray2[x]>imageArray1[x]){ // if color value from image2 is greater than the color value from image1, 
				imageArray1[x] = (255 + imageArray1[x]) - imageArray2[x]; //do a wrap-around algorithim where it starts subtracting from 255
		}
		else{
			imageArray1[x] = imageArray1[x] - imageArray2[x]; //else, simply subtract (image1 - image2)
		}
	}
	
	
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

