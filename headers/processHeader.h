
// takes Header, array, file, and 0 or 1 to decide to print
takeBMPfile(struct BitMapHeader *HeaderInfo, unsigned char **array, FILE *file, int print){
	
	memset(HeaderInfo, 0, sizeof(tagHeader));
	
	fseek(file, 0, SEEK_SET);

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
	
	*array = (unsigned char*) malloc(HeaderInfo->Size);
	
	fseek(file, HeaderInfo->Offset, SEEK_SET);
	fread(*array, HeaderInfo->Size, 1, file);
	
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
