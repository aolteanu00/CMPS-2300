/*
The following code demonstrates the usage of the "*" and "&" operators in C.
We are provided with two functions that have similar scope. Given two interger variables,
these functions will supposedly swap their values. However, upon running swap we will see that the values
of our declared variables do not actually change. Yet if we print the values of the variable WITHIN the swap function,
we will see that it has worked. This discrepency occurs because we are only updating the LOCAL values of these variables
within the function. We are not actually altering the original values we declared.

This is why swap2 is important. Upon running swap2 we will see that printing our originally declared variables does
indeed indicate that they have been swapped. The * and & operators are responsible for this. The * is a pointer that
refers to the physical memory address of a variable, which tells C that this is the place of the specific variable you wish to reference.
The & operator refers to and yields the physical value of this memory address, allowing us to permanently make changes to
our variables and data structures.
*/

void swap(int x, int y)
{
  int temp;
  temp = x;
  x = y;
  y = temp;
  return;
}

void swap2(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
  return;
}

#include <stdio.h>
int main() {
  int a = 5;
  int b = 10;
  printf("Variable a is: %d\n",a);
  printf("Variable b is: %d\n",b);

  swap(a,b);
  printf("We just called the swap function.\n");

  printf("Variable a is: %d\n",a);
  printf("Variable b is: %d\n",b);

  swap2(&a,&b);
  printf("We just called the swap2 function.\n");

  printf("Variable a is: %d\n",a);
  printf("Variable b is: %d\n",b);
  return 0;
}
