#include <stdio.h>
int main(void){
	struct Birthday { /*Sometimes we want to collect a bunch of data together as some arbitrary structure instead of using the given data types*/
	unsigned int day; /*We're using special types of ints called 'unsigned' ints because we don't ever want these values to be negative*/
	unsigned int month;
	unsigned int year;
    };
    /*Ok we've defined the 'Birthday struct'. Let's make one*/
    struct Birthday mybirthday;
    /*great.*/
    mybirthday.day = 1;
    mybirthday.month = 1;
    mybirthday.year = 1950;
    /*Now we've set some values... but usually the interesting thing about structs is we can refer to one big struct with one small pointer*/
    struct Birthday *ptr; /*ptr is a variable with type 'pointer to a Birthday struct'*/
    ptr = &mybirthday;
    /*Now the variable ptr points to the mybirthday struct*/
    (*ptr).day = 2; /*this says 'go to the value of ptr (which is a Birthday struct), then use the dot operator to access its day variable*/
    ptr->day = 1; /*change it back -- this is a more convenient way to do the above since it comes up a lot -- we use the 'arrow' to access the member variables of the struct that 'ptr' points to.*/
    
	
	typedef struct Birthday Birthday;/*typedef defines a new type -- the first thing it takes is a current type that's annoying to type (struct Birthday), and the second is the name of the new type*/
	Birthday *yourbirthday; /*this looks a little nicer*/
	yourbirthday->day = 2;
	yourbirthday->month = 2;
	yourbirthday->year = 1960;
	/*and now we have a shortcut*/
	
	
    return 0;
}

