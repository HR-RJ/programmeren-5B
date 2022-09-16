/*literate programming
Requirements
============

The program must show a test image.
The test image must consist of a semi-transparant circle.
Also a semi-transparent chessboard must be visible.
The image must consist of characters, each character denotes a pixel.
The test image must be OK on any screen.

TestSpecs
============

Tests are done visually.
If the program is run, a chessboard with a semi-transparent circle must indeed be visible.
If you're close to the screen the seperate characters must be visible.
These results must hold for any screen resolution and should be tested on at least 3 distict devices a.o. a smartphone.


Design
============

Make a data structure to hold the image.
The data structure is a vector.
Each element of the vector is a row of floats on the screen.
Specifically each row is also a vector, namely a vector of float.
Reason: you can compute with float brightness but not with chars.
(brightness = 1 / blackness)

First draw the circle.
The circle has a certain width.
It is a filled shape between a small and a large radius.
The circle is drawn line by line, by a scanning algorithm. !!!

Originally my image contains 1's.
If a field is white in a figure, it is multiplied by 1 / brightness.
A good value to multiply with is 1/2, 
Why that is the case I forgot, just tried.

Use two nested loops, the outer one fo the rows the inner one for the individual brightness.

Put the origin of the coordinate frame in the middle.
x and y as usual in math, -0.5 <= x <= 0.5,
y somewhere between -0.7 and 0.7, depending on the aspect ratio.


After that draw the chessboard.
The width of one field is called the stride.
by dividing the width of the chessboard by the stride, 
I get the number of fields.
The field number is called crudeX or crudeY.
Determine wether or not crudeX or crudeY are even or odd by the % operator.
White fields are fields where crudeX % 2 == crudeY % 2.


As a last step render the values in the image datastructure to the screen.
As brightnesses use [MNIL+-. ]
Pick a char by using 7 * (1 / brightness) as an index in the char array

*/