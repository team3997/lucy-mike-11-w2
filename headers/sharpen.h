/*
 * sharpen.h
 *
 *  Created on: Nov 13, 2015
 *      Author: Xyzzy
 */

/*
 * subtract.h
 *
 *  Created on: Nov 10, 2015
 */


int sharpen(char *path) {

	char *convertedPath;

	//Declare structures for header file
	struct BitMapHeader header;

	//declare arrays for pixel data of both images
	unsigned char *pixels;
	unsigned char *pixelsAlt;

	//Grab data from file, and put it into our header structure(header) and pixel array (imageArray)
	FILE *imageFile = fopen(path, "rb"); // open file specified as path
	grabBMP(&header, &pixels, imageFile, 1);    //copy pixel data in an array to read from
	grabBMP(&header, &pixelsAlt, imageFile, 1); //copy pixel data again into an array to alter
	fclose(imageFile); // close file

/*
 * {-1, -1, -1}
 * {-1,  9, -1}
 * {-1, -1, -1}
 */

/*
 * {[(w+ (h+1)*header.Width)-1], [(w+ (h+1)*header.Width)], [(w+ (h+1)*header.Width) +1]}
 * {[(w+  h   *header.Width)-1], [(w+  h   *header.Width)], [(w+  h   *header.Width) +1]}
 * {[(w+ (h-1)*header.Width)-1], [(w+ (h-1)*header.Width)], [(w+ (h-1)*header.Width) +1]}
 */
	
	int h;
	int w;
	int tarMult = 9;
	int neighMult = -1;
	int r;
	int rUp;
	int rDn;
	int g;
	int gUp;
	int gDn;
	int b;
	int bUp;
	int bDn;
	int red;
	int grn;
	int blu;
	
	// Sharpen ALGORITHIM (acts on all except for edge pixels)
	for(h = 1; h < header.Height-1; h++){
		for(w = 1; w < header.Width-1; w++){
			

			r   = 3*(w+ h*header.Width); 	//R value of target pixel
			rUp = 3*(w+ (h+1)*header.Width); 	//R value of pixel above target
			rDn = 3*(w+ (h-1)*header.Width); 	//R value of pixel below target

			g   = 3*(w+ h*header.Width)+1; 	//G value of target pixel
	 		gUp = 3*(w+ (h+1)*header.Width)+1; //G value of pixel above target
			gDn = 3*(w+ (h-1)*header.Width)+1; //G value of pixel below target

			b   = 3*(w+ h*header.Width)+2; 	//B value of target pixel
			bUp = 3*(w+ (h+1)*header.Width)+2; //B value of pixel above target
			bDn = 3*(w+ (h-1)*header.Width)+2; //B value of pixel below target

			//Sum R values
			red = sumVal(pixels, r) + sumVal(pixels, rUp) + sumVal(pixels, rDn) - pixels[r];
			red = red*neighMult + pixels[r]*tarMult;
			if(red<0){
				red = 0;
			}
			else if(red > 255){
				red = 255;
			}
			pixelsAlt[r] = red;

			//Sum G values
			grn = sumVal(pixels, g) + sumVal(pixels, gUp) + sumVal(pixels, gDn) - pixels[g];
			grn = grn*neighMult + pixels[g]*tarMult;
			if(grn<0){
				grn = 0;
			}
			else if(grn > 255){
				grn = 255;
			}
			pixelsAlt[g] = grn;

			//Sum B values
			blu = sumVal(pixels, b) + sumVal(pixels, bUp) + sumVal(pixels, bDn) - pixels[b];
			blu = blu*neighMult + pixels[b]*tarMult;
			if(blu<0){
				blu = 0;
			}
			else if(blu > 255){
				blu = 255;
			}
			pixelsAlt[b] = blu;

		}
	}


	//Make output filename
	char *init = "images/output/";
	char *fileEnd = "_sharpen.bmp";
	char *underScore = "_";
	char *conPath = basename(path);
	conPath[strcspn(conPath, ".")] = '\0';
	convertedPath = malloc(strlen(init)+strlen(conPath)+strlen(fileEnd)+1);
	strcpy(convertedPath, init);
	strcat(convertedPath, conPath);
	strcat(convertedPath, fileEnd);

	// Create a new file named newImage and set the path to images/converted.bmp
	FILE *newImage;
	newImage = fopen(convertedPath,"wb");

	// write data to new file.
	putBMP(&header, pixelsAlt, newImage);

	//close the open image
	fclose(newImage);

	// Print success!
	printf("\nSuccess! Output: %s\n", convertedPath);

	return 0;
}

//sums the R, G, *or* B values of the neighboring pixels (left/right) on the same row
int sumVal(unsigned char *array, int index){
	int sum = array[index-3] + array[index] + array[index+3];
	return sum;
}
