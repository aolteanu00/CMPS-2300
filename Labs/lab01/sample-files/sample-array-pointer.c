#include <stdio.h>
#include <stdlib.h>

void SetEqualFive(int x){/*These are here to refer to at the end*/
     x = 5;
     return;
     }

void SetEqualFivePointer(int *x){
     *x = 5;
     return;
     }
void MakePointerNull(int **x){
     *x = NULL;
     return;
     }

int main(void){
    int x[20]; /*x is an array of integers of length 20*/
    x[0] = 5; /*set the first element in x to 1*/
    x[19] = 20; /*set the last element in x to 1*/
    char c[10] = "Hello"; /*c is an array of characters, or a string*/
    c[0] = 'B';
    c[5] = 'w';
    c[6] = '\0';/*Now instead of 'Hello' it says 'Bellow'. C strings are terminated with the NULL character, which is represented \0. This is how C knows to stop reading a string. When I initialized the array, C automatically put the null character there after the 'o' but I overwrote null, so I need to put it back*/
    printf("We have changed our string to %s\n", c);


    int z = 1;
    int *p; /*if we put a star in front of the name of a variable as we declare it, we are declaring a different type of variable. p is a 'pointer' that points to something of type 'int'. It stores the memory address of some area in memory that's the size of an 'int'. */
    p = &z; /*&z means 'the address of x', so p is a pointer, it points to a place in memory. Where? At first it was undefined, after this line it's whatever the address reserved for the variable 'z' is*/
    printf("p is a pointer pointing to z, the value of p is %d\n", *p); /* in normal code we can read a star before a variable out loud as 'the value of p' and an ampersand as 'the address of p'. Here we are printing out the value of p, which should be 1, since p points to z*/
    printf("p is a pointer pointing to z, the address that p is pointing to is %d\n",p); /* if you print out p itself, it's a weird memory address that isn't helpful*/
    p = x; /*Now p is pointing to the beginning of the block of memory for the array 'x'*/
    printf("p is pointing to the value %d\n",*p);
    printf("If we push 19 units of int memory past 'p', we can see the value %d\n", *(p+19)); /*Arrays are just a handy way of having a pointer to a starting address and a block of reserved memory after that starting address. Earlier, we reserved 20 'int's worth of memory for the array 'x', so the array 'x' is really just an address of the beginning, x[0], and we know that it's got 19 more slots of size int after that*/
    *p = 200; /*We can change the value of p. Remember, right now p is pointing to the array x, so changing the value of p is changing the first slot in the array x, or x[0]*/
    *(p + 3) = 13; /*This is the same as saying x[3] = 13*/

    /*Okay, let's try to write a function that changes the value of any integer to 5. Look at our old friend, z, it's 1 right now.*/
    printf("z = %d\n", z);
    SetEqualFive(z); /*Try number one. We did this last time and it didn't work. I would hope it still doesn't.*/
    printf("z = %d\n", z); /*nope*/
    SetEqualFivePointer(&z); /*Okay, this time what's happening? This function takes a pointer to an integer, i.e. an address of an int, which is why I'm giving it &z (remember that means 'the address of z') and then goes into memory and changes the thing it's pointing to so that it's 5*/
    printf("z = %d\n", z); /*Great!*/
    z = 100; /*Let's try a different way*/
    printf("Now z = %d\n",z);
    p = &z; /*Now p points to z again*/
    SetEqualFivePointer(p); /*This sets whatever int p's pointing to to be 5*/
    printf("Success! z = %d\n",z);


    /*OK, ready to have your mind blown?*/
    int **DoublePtr;/*DoublePtr points to a pointer to an int. Or, if you prefer, it's a pointer to something of type 'array of ints'. Why would someone ever do something this horrible?*/
    int y[10][10]; /*This is the same sort of thing, it's a 2D array or a matrix*/
    int *ptr; /*Here's a new pointer. Suppose I wanted make it point to the null memory address, keyword NULL, but within a function: If I pass ptr to a function, the address it's pointing to isn't changing ever. That's a problem.*/
    printf("This should be nonzero if ptr is the same as NULL: %d\n", ptr==NULL);
    MakePointerNull(&ptr); /*Ok, so I'll write a function that takes a pointer to a pointer, pass it the address of this pointer, and it can change what my pointer is pointing to -- now it's pointing to the special keyword NULL, which represents the empty/no memory address*/
    printf("This should be nonzero if ptr is the same as NULL: %d\n", ptr==NULL); /*cool. This idea might be helpful for your assignment*/
	return 0;
}
