# ppm-encode-decode
A project that encodes a message into the binary data of a .ppm file without changing how the picture looks, then decodes it and prints it to the terminal.

# details
This program was written in the context of a sophmore level computer science course project.  

Long story short, this is a fun C program that takes a .ppm picture file, encodes a text string (defined in driver.c), then re-loads the file, printing the encoded text to the terminal.  An encoded image will look visually identical to the non-encoded version.

The message is encoded by storing the .ppm's rgb values in a representative 2D array, then stripping the least significant binary digits off and replacing with '0'.  The individual letters of the message are then converted to their respective binary values.  Then, each modified binary digit in the array is replaced with the binary digits of each letter in the message to be encoded, and the modified .ppm is created.  The decoder will take this file and convert the least significant binary digits of each rgb value into their respective ascii characters, printing the resulting message to the terminal.

A makefile is included and set up to open the image named test-image.ppm for encoding /decoding.  To see the test message defined in driver.c, you just need to type 'make run' in the command line.

# limitations and future plans
Currently, this project works very well within the scope of the original assignment, and received full marks.  In the bigger picture, so to speak, I have plans to improve this project and make it more useful.  I plan on separating the encoder / decoder in driver.c so it doesn't perform both operations on the same image, allowing a user to choose what they want to do.  I will also add a menu display so the user can encode a message of their choice without having to edit driver.c  Finally, I plan on implementing run time improvements, and perhaps to simplify the code a bit.  

This readme will be updated at the project progresses.
