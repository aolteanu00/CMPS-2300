
#include <stdio.h> 
#include <stdlib.h> /*The functions malloc and free and sizeof for managing memory dynamically are in stdlib.h so we need to include this too*/

int main(void){ 
    int *ptr; /*Ok, so ptr is a pointer to an int. Great, but we I don't see any ints anywhere for it to point to, so what's the point? Pun intended?*/
    ptr = malloc(sizeof(int)); /*malloc requests some amount of memory from the operating system. If it succeeds, it returns the address of where that memory block starts. Here we are asking for an int worth of memory*/
    *ptr = 70; /*This is ok now, because ptr points to memory we have reserved for this program via malloc*/
    *(ptr + 1) = 12; /*You might get away with this (I do on my machine) but it is NOT OK. We've only asked for one int worth of memory, but we're moving over by one int worth of space and writing there. NEVER DO THIS. Try replacing '1' with 3000 and you'll likely crash in a very ugly way. What if we want to store 2 ints now?*/
    free(ptr); /*This gives memory back to the operating system that we allocated with malloc. Now ptr points to meaningless invalid memory again*/
    ptr = malloc(2*sizeof(int)); /*Now we allocate 2 int-sizes worth of memory. */
    ptr[1] = 12; /*ok, we can do this, and I'm using array syntax to remind you that pointers and arrays are the same. This is the same as saying *(ptr + 1) = 12; */
    
    struct WeirdStruct {/* Let's define a struct that takes up a weird amount of memory -- this one will need space for 3 ints, a pointer to a character, a double, and an array of 3 ints*/
           int x;
           int y;
           int z;
           char *c;
           double d;
           int numbers[3];
           };
    struct WeirdStruct *WeirdPtr = malloc(sizeof(struct WeirdStruct)); /*This is ok. Now WeirdPtr points to a struct of size WeirdThing*/
    WeirdPtr->x = 10;
    WeirdPtr->y = 20;
    WeirdPtr->z = 30;/*These are numbers. Just as an example*/
	return 0; 
}
