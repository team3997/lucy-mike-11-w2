/*
 * Convert.c
 *
 *  Created on: Nov 3, 2015
 *      Author: mikec
 */

#include <stdio.h>
#include <stdlib.h>

//Stucture of bitmap header (First 54 bytes of bitmap)
struct BitMapHeader {
	short Signature; //bmp identifiers, always = 19778
	long Size;	//size of bmp in bytes
	short Reserved1; 	// placeholder
	short Reserved2;	//placeholder
	long Offset;	//Offset till pixel data
	long HeaderSize;	//header size in bytes
	long Width;		// Width of image in pixels
	long Height;	// Height
	short Planes;	//1 plane for image
	short BitsPerPixel;	//Amount of bits per pixel
	long CompressionType; //Type of compression used.
	long DataOfImage; //image size in bytes
	long xPixelsPerMeter;
	long yPixelsPerMeter;
	long Colors;
	long ImportantColor;
} Header;



int greyify(char *path) {

	unsigned char *image;
	int greyed;
	int i;


	// Open original file
	FILE *imageFile = fopen(path, "rb");

	// Check if file is valid.
	if (imageFile == NULL) {
		fclose(imageFile);
		printf("\nInvalid Image\n");
		return 0;
	}


	//Read the header info of the bitmap (ORDER MATTERS!)
	fread(&Header.Signature, 2, 1, imageFile);
	fread(&Header.Size, 4, 1, imageFile);
	fread(&Header.Reserved1, 2, 1, imageFile);
	fread(&Header.Reserved2, 2, 1, imageFile);
	fread(&Header.Offset, 4, 1, imageFile);
	fread(&Header.HeaderSize, 4, 1, imageFile);
	fread(&Header.Width, 4, 1, imageFile);
	fread(&Header.Height, 4, 1, imageFile);
	fread(&Header.Planes, 2, 1, imageFile);
	fread(&Header.BitsPerPixel, 2, 1, imageFile);
	fread(&Header.CompressionType, 4, 1, imageFile);
	fread(&Header.DataOfImage, 4, 1, imageFile);
	fread(&Header.xPixelsPerMeter, 4, 1, imageFile);
	fread(&Header.yPixelsPerMeter, 4, 1, imageFile);
	fread(&Header.Colors, 4, 1, imageFile);
	fread(&Header.ImportantColor, 4, 1, imageFile);

	//print header info to screen
	printf("Signature: %d\n", Header.Signature);
	printf("Size: %d\n", Header.Size);
	printf("Reserved1: %d\n", Header.Reserved1);
	printf("Reserved2: %d\n", Header.Reserved2);
	printf("Offset: %d\n", Header.Offset);
	printf("HeaderSize: %d\n", Header.HeaderSize);
	printf("Width: %d\n", Header.Width);
	printf("Height: %d\n", Header.Height);
	printf("Planes: %d\n", Header.Planes);
	printf("BitsPerPixel: %d\n", Header.BitsPerPixel);
	printf("CompressionType: %d\n", Header.CompressionType);
	printf("DataOfImage: %d\n", Header.DataOfImage);
	printf("xPixelsPerMeter: %d\n", Header.xPixelsPerMeter);
	printf("yPixelsPerMeter: %d\n", Header.yPixelsPerMeter);
	printf("Colors: %d\n", Header.Colors);
	printf("ImportantColor: %d\n", Header.ImportantColor);

	// Allocate enough memory for image array
	image = (unsigned char*) malloc(Header.Size);

	// Copy pixel information from imageFile to our image array
	fseek(imageFile, Header.Offset, SEEK_SET);
	fread(image,Header.Size, 1,imageFile);

	// Cycle through every pixel and average the bgr values
	for (i = 0; i < (Header.Size); i+=3)
	{
			greyed = ((image[i] + image[i+1] + image[i+2])/3);
			image[i] = image[i+1] = image[i+2] = greyed;

	}


	// Create a new file named newImage and set the path to images/converted.bmp
	FILE *newImage;
	newImage = fopen("images/converted.bmp","wb");


	// Copy header info from the original image to the new image
	fseek(newImage, 0, SEEK_SET);
	fwrite(&Header.Signature, 2, 1, newImage);
	fwrite(&Header.Size, 4, 1, newImage);
	fwrite(&Header.Reserved1, 2, 1, newImage);
	fwrite(&Header.Reserved2, 2, 1, newImage);
	fwrite(&Header.Offset, 4, 1, newImage);
	fwrite(&Header.HeaderSize, 4, 1, newImage);
	fwrite(&Header.Width, 4, 1, newImage);
	fwrite(&Header.Height, 4, 1, newImage);
	fwrite(&Header.Planes, 2, 1, newImage);
	fwrite(&Header.BitsPerPixel, 2, 1, newImage);
	fwrite(&Header.CompressionType, 4, 1, newImage);
	fwrite(&Header.DataOfImage, 4, 1, newImage);
	fwrite(&Header.xPixelsPerMeter, 4, 1, newImage);
	fwrite(&Header.yPixelsPerMeter, 4, 1, newImage);
	fwrite(&Header.Colors, 4, 1, newImage);
	fwrite(&Header.ImportantColor, 4, 1, newImage);



	//Copy all the pixel data from our greyified image array to the new image
	fseek(newImage, Header.Offset, SEEK_SET);
	fwrite(image,Header.Size, 1,newImage);


	//close the open images.
	fclose(newImage);
	fclose(imageFile);

	// Print success!
	printf("\nConverted File: images/converted.bmp");
	return 0;
}


int main() {
	char *imagePath = "images/party.bmp";
	greyify(imagePath);
	return 0;

}

