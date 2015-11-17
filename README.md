# week2project
Sharpening, Subtracting, and Processing Image Coordinates.
by Michael Chacko and Lucy Zhao		11/14/2015

This program only works with 24-bit bmp files!

Our program allows users to select one of three options to process an image. The options are ‘subtract’, ‘sharpen’ or ‘process’.  ‘Subtract’ allows the user to specify two images and subtract them from each other, ‘sharpen’ magnifies the colors of certain pixels to get a more intensified image, and ‘process’ allows the user to process a specified pixel region of an image.

To subtract two images from each other, you subtract each RGB (red, green, blue color value)  value from each pixel of one image against each RGB value from each pixel of the other image. While this is mostly a straightforward process, you must be careful to properly handle integer ‘wrap-around’. When subtracting two color values, the value of the colors can possibly result in a negative value. This would not result in a valid color value, so this must be accounted for. A good way to account for this is to have the program find the absolute value of the
difference of the color values. Also, be wary of subtracting images of different sizes. Images of different sizes will not scale well against each other.

Image sharpening can be more complex than image subtraction. To sharpen an image, you make each pixel dependant on the pixels it neighbors. One algorithm we researched multiplied each RGB value in each pixel by 9 and added that product to the sum of the negative RGB values of the immediately neighboring pixels. Note that the pixels along the border of the image cannot use this algorithm, as this filter uses neighboring pixel values from all directions.	

To process an image within a specified range of coordinates, our program has the user input a reference corner from which those coordinates will span. It was tricky to find an algorithm that would only process the specified range of coordinates. After some brainstorming, we found that the modulus (remainder) operator was going to work well in this case. As an example, this is the algorithm for when the top right corner is selected as a reference: As our program loops through the pixels,  we exclude any color value that when divided by the full image width, has a remainder greater than or equal to the width of the image minus the inputted x coordinate.
The ability to process an inputted range of coordinates can be very useful when working with images. Even basic actions such as image cropping relies on this ability.
