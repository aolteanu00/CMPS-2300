#include <stdio.h>

int main(void){
    if(2>1){
             printf("We can branch with if statements\n");/*an If statement looks like: if(boolean condition){ code to execute if true }*/
             }
    else{
         printf("This is code that will never execute because is an 'else' following an 'if' that always executes\n");
         }
    int x=0;
    while(x <= 100){ /* <= means 'less than or equal to'*/
            printf("%d ",x); /*execute until the condition is false*/
            x++; /*++ means 'increase this variable by 1'*/
            }

    while(!x){ /*if we try to evaluate a number as a boolean value, 0 means true, 1 means false, so this means 'while x is not 0'*/
             printf("%d ",x);
             }

    for(x = 0;x<10;x++){ /*for is a quick way to iterate: in C, the first statement is executed at the beginning of the for loop, the second is the condition that tells you when to stop executing, and the third statement is executed after every iteration*/
          printf("We're in a for loop now: x = %d\n", x);
          }

    return 0;
}
