/*Comments start with the slash and asterisk combo
 *and end with the reverse -- they can be as many lines as you want */
#include <stdio.h> /* stdio.h is a library with 'standard input/output' functions, like printf*/

int main(void){ /*I am defining the main function (entry point into the program). It returns an integer or 'int', and takes no values as input (void). The curly brace starts the function definition*/
	printf("Hello, world!"); /*I am calling a function from the stdio.h library called 'printf', giving it one input, the fixed string "Hello, world!", and it's a statement so it ends with a semicolon*/
	return 0; /*My main function has to return an 'int', I'm returning 0 because the default is to return 0 for success*/
}/*End the function definition*/
