

//Stucture of bitmap header (First 54 bytes of bitmap)

struct BitMapHeader{
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
}tagHeader;
