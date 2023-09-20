#include <stdio.h>

void PrintHello(){/*I'm defining an external function, above the place where I call it in the program. No arguments, no return value, it just executes the printf line*/
	printf("Hello, world!\n");
	return;
}

int add(int x, int y){/*Takes two integers, x, y, adds them and returns the result*/
	return x + y;
}

void SetEqualFive(int x){
	x = 5;
	return;
}

int main(void){
	int z;
	int p=5; /*Declare two integers, z is undefined to start with, p is initialized to 5*/
	char c = 'a'; /*Define a character variable and set it to 'a'*/
	double d = 1.25; /*Define a double variable and set it to 1.0*/
	PrintHello(); /*I call my Hello World function to print Hello World*/
	printf("Add p and d is %d\n", add(p,d)); /*Print out the value of calling my add function on p and d, and display it as an integer*/
	z=2; /*set z = 2*/
	printf("z has been set to %d\n", z); /*print out the value of z formatted as an integer*/
	SetEqualFive(z); /*call my function which takes z, and sets it equal to 5*/
	printf("after calling SetEqualFive on z, it's still %d\n", z); /*The value of z here doesn't change -- if i pass a variable to a function the function can't change the variable directly, I'm just passing the number that 'z' happens to be at the time, which is '2'*/
    return 0;
}
