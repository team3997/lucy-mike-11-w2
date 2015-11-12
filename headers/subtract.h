/*
 * subtract.h
 *
 *  Created on: Nov 10, 2015
 */


int subtract(char *path1, char *path2) {
	
	int x;
	int y;
	
	//Declare structures for both header files
	struct BitMapHeader header1;
	struct BitMapHeader header2;
	
	//declare arrays for pixel data of both images
	unsigned char *imageArray1;
	unsigned char *imageArray2;

	
	//Grab data from file1, and put it into our header structure(header1) and pixel array (imageArray1)
	FILE *imageFile1 = fopen(path1, "rb"); // open file specified as path 1
	takeBMPfile(&header1, &imageArray1, imageFile1, 0); //take all the data from the file 
	fclose(imageFile1); // close file 
	
	//Grab data from file2, and put it into our header structure(header2) and pixel array (imageArray2)
	FILE *imageFile2 = fopen(path2, "rb"); // open file specificed as path 2
	takeBMPfile(&header2, &imageArray2, imageFile2, 0); //take all the data from the file 
	fclose(imageFile2); // close file 

	
	if(header2.Size > header1.Size){
		printf("\nImage you are trying to subtract from is smaller than the image you are using to subtract!\n");
		printf("\nExiting...\n");
		exit(0);
	}
	
	
	// Subtraction ALGORITHIM
	for (x = 0; x < (header2.Size); x+=1)
	{
		if(imageArray2[x]>imageArray1[x]){
				imageArray1[x] = 255 - imageArray2[x];
		}
		else{
			imageArray1[x] = imageArray1[x] - imageArray2[x];
		}
	}

	// Create a new file named newImage and set the path to images/converted.bmp
	FILE *newImage;
	newImage = fopen("images/converted.bmp","wb");


	// Copy header info from the bigger image to the new image
	fseek(newImage, 0, SEEK_SET);
	fwrite(&header1.Signature, 2, 1, newImage);
	fwrite(&header1.Size, 4, 1, newImage);
	fwrite(&header1.Reserved1, 2, 1, newImage);
	fwrite(&header1.Reserved2, 2, 1, newImage);
	fwrite(&header1.Offset, 4, 1, newImage);
	fwrite(&header1.HeaderSize, 4, 1, newImage);
	fwrite(&header1.Width, 4, 1, newImage);
	fwrite(&header1.Height, 4, 1, newImage);
	fwrite(&header1.Planes, 2, 1, newImage);
	fwrite(&header1.BitsPerPixel, 2, 1, newImage);
	fwrite(&header1.CompressionType, 4, 1, newImage);
	fwrite(&header1.DataOfImage, 4, 1, newImage);
	fwrite(&header1.xPixelsPerMeter, 4, 1, newImage);
	fwrite(&header1.yPixelsPerMeter, 4, 1, newImage);
	fwrite(&header1.Colors, 4, 1, newImage);
	fwrite(&header1.ImportantColor, 4, 1, newImage);


	//Copy all the pixel data from our greyified image array to the new image
	fseek(newImage, header1.Offset, SEEK_SET);
	fwrite(imageArray1, header1.Size, 1,newImage);


	//close the open image.
	fclose(newImage);

	// Print success!
	printf("\nConverted File: images/converted.bmp");
	return 0;
}

