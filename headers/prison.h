/*
 * rainbow.h
 *
 *  Created on: Dec 5, 2015
 */


int prison(char *path) {

	char *convertedPath;

	//Declare structures for header file
	struct BitMapHeader header;
	//declare arrays for pixel data of both images
	unsigned char *imageArray;
	//Grab data from file, and put it into our header structure(header) and pixel array (imageArray)
	FILE *imageFile = fopen(path, "rb"); // open file specified as path
	grabBMP(&header, &imageArray, imageFile, 0);    //copy pixel data in an array to read from
	fclose(imageFile); // close file


	int part = header.Width*header.Height/13;
	int lastPart = part + (header.Width*header.Height)%13;

	int j = 0;
	int mult =0;
	int z = 1;
	for(z = 1; z<13; z++){
		mult = z%2;
		printf("%d\n", mult);
		for(j=j;j<3*z*part; j+=3){
			imageArray[j] = mult*imageArray[j];
			imageArray[j+1] = mult*imageArray[j+1];
			imageArray[j+2] = mult*imageArray[j+2];
		}
	}
	for(j=j; j<3*header.Width*header.Height; j+=3){
		imageArray[j] = imageArray[j];
		imageArray[j+1] = imageArray[j+1];
		imageArray[j+2] = imageArray[j+2];
	}		
	
	//Make output filename
	char *init = "images/output/";
	char *fileEnd = "_prison.bmp";
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
	putBMP(&header, &imageArray, newImage);
	
	//close the open image
	fclose(newImage);
	
	// Print success!
	printf("\nSuccess! Output: %s\n", convertedPath);
	return 0;
}
