
// This function grabs a bimtap named 'file' and puts the header information into '*HeaderInfo' and the pixel data in '**array'
grabBMP(struct BitMapHeader *HeaderInfo, unsigned char **array, FILE *file, int print){
	
	//Allocate memory to new header
	memset(HeaderInfo, 0, sizeof(tagHeader));
	
	//Seek to beginning of the file
	fseek(file, 0, SEEK_SET);

	//Read the information from the beginning of the file and put it into our header 
	fread(&HeaderInfo->Signature, 2, 1, file);
	fread(&HeaderInfo->Size, 4, 1, file);
	fread(&HeaderInfo->Reserved1, 2, 1, file);
	fread(&HeaderInfo->Reserved2, 2, 1, file);
	fread(&HeaderInfo->Offset, 4, 1, file);
	fread(&HeaderInfo->HeaderSize, 4, 1, file);
	fread(&HeaderInfo->Width, 4, 1, file);
	fread(&HeaderInfo->Height, 4, 1, file);
	fread(&HeaderInfo->Planes, 2, 1, file);
	fread(&HeaderInfo->BitsPerPixel, 2, 1, file);
	fread(&HeaderInfo->CompressionType, 4, 1, file);
	fread(&HeaderInfo->DataOfImage, 4, 1, file);
	fread(&HeaderInfo->xPixelsPerMeter, 4, 1, file);
	fread(&HeaderInfo->yPixelsPerMeter, 4, 1, file);
	fread(&HeaderInfo->Colors, 4, 1, file);
	fread(&HeaderInfo->ImportantColor, 4, 1, file);
	
	if(HeaderInfo->BitsPerPixel != 24){
		printf("This program is only compatible with 24-bit BMP files.\n Exiting...\n");
		exit(0);
	}
	//Allocate memory for our pixel data array
	*array = (unsigned char*) malloc(HeaderInfo->Size);
	
	//Seek to beginning of the pixel data in the file
	fseek(file, HeaderInfo->Offset, SEEK_SET);
	fread(*array, HeaderInfo->Size, 1, file);
	
	//if the last argument is 1, print all the header info to the screen
	if(print){
		printf("Signature: %d\n", HeaderInfo->Signature);
		printf("Size: %ld\n", HeaderInfo->Size);
		printf("Reserved1: %d\n", HeaderInfo->Reserved1);
		printf("Reserved2: %d\n", HeaderInfo->Reserved2);
		printf("Offset: %ld\n", HeaderInfo->Offset);
		printf("HeaderSize: %ld\n", HeaderInfo->HeaderSize);
		printf("Width: %ld\n", HeaderInfo->Width);
		printf("Height: %ld\n", HeaderInfo->Height);
		printf("Planes: %d\n", HeaderInfo->Planes);
		printf("BitsPerPixel: %d\n", HeaderInfo->BitsPerPixel);
		printf("CompressionType: %ld\n", HeaderInfo->CompressionType);
		printf("DataOfImage: %ld\n", HeaderInfo->DataOfImage);
		printf("xPixelsPerMeter: %ld\n", HeaderInfo->xPixelsPerMeter);
		printf("yPixelsPerMeter: %ld\n", HeaderInfo->yPixelsPerMeter);
		printf("Colors: %ld\n", HeaderInfo->Colors);
		printf("ImportantColor: %ld\n", HeaderInfo->ImportantColor);
	}

}

// This function grabs header information from '*HeaderInfo' and pixel data from '**array', and puts all of that into a bitmap named 'file'
putBMP(struct BitMapHeader *HeaderInfo, unsigned char **array, FILE *file){
		
	fseek(file, 0, SEEK_SET);
	fwrite(&HeaderInfo->Signature, 2, 1, file);
	fwrite(&HeaderInfo->Size, 4, 1, file);
	fwrite(&HeaderInfo->Reserved1, 2, 1, file);
	fwrite(&HeaderInfo->Reserved2, 2, 1, file);
	fwrite(&HeaderInfo->Offset, 4, 1, file);
	fwrite(&HeaderInfo->HeaderSize, 4, 1, file);
	fwrite(&HeaderInfo->Width, 4, 1, file);
	fwrite(&HeaderInfo->Height, 4, 1, file);
	fwrite(&HeaderInfo->Planes, 2, 1, file);
	fwrite(&HeaderInfo->BitsPerPixel, 2, 1, file);
	fwrite(&HeaderInfo->CompressionType, 4, 1, file);
	fwrite(&HeaderInfo->DataOfImage, 4, 1, file);
	fwrite(&HeaderInfo->xPixelsPerMeter, 4, 1, file);
	fwrite(&HeaderInfo->yPixelsPerMeter, 4, 1, file);
	fwrite(&HeaderInfo->Colors, 4, 1, file);
	fwrite(&HeaderInfo->ImportantColor, 4, 1, file);
	
	//Copy all the pixel data from our greyified image array to the new image
	fseek(file, HeaderInfo->Offset, SEEK_SET);
	fwrite(*array, HeaderInfo->Size, 1, file);

}

