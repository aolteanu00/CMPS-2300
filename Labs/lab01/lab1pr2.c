/*
First command line asks for input file name.
Second command line asks for output file name.
Third command line asks for the number of days your system has been hypothetically active.
The following command lines will ask for an integer value corresponding with the runtime of each day the system has been active.

NOTE: I was unsure if the assignment is asking to read from an existing file we
hardcode values into, or to have the program create one from scratch and write
to it as well. I assumed the latter for my program and although it still asks
for user input via the terminal, every computation in the program is handled with
values read directly from the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  /*Recieve input file name from user.*/
  printf("Enter input file name:\n");
  char input[50];
  scanf("%s", input);
  printf("Your input file is called: %s\n", input);

  /*Recieve output file name from user*/
  printf("Enter output file name:\n");
  char output[50];
  scanf("%s", output);
  printf("Your output file is called: %s\n", output);

  /*Begin writing user input to empty text file, named after the first command line entry*/
  FILE *fi;
  fi=fopen(input,"w");

  printf("For how many days has your system been active?:\n");
  int runtime;
  scanf("%d", &runtime);

  fprintf(fi, "%d\n", runtime);

  int i;
  int days[runtime];
  printf("Enter corresponding daily runtime values, one per command line.\n");
  for(i = 0; i < runtime; i++) {
    scanf("%d", &days[i]);
    fprintf(fi, "%d\n", days[i]);
  }
  fclose(fi);
  /*File has now been filled with user input. Program may now proceed to reading.*/


  /*Open file for reading and save content to an integer array.*/
  printf("*****COMPUTING RESULTS*****\n");
  fi=fopen(input,"r");
  char arr[runtime];
  int arrInt[runtime];

  /*Declare variables to compute with*/
  double timeTotal;
  double performanceRate;
  double avgTime;

  /*Loop through the file and save each line to a new array as an int.*/
  for(i = 0; i < runtime + 1; i++){
    if(strcmp(arr,"EOF") != 0){
      fgets(arr,runtime,fi);
      int arrNum = atoi(arr);
      arrInt[i] = arrNum;
      /*printf("arrNum right now is: %d\n",arrNum);*/
      /*printf("i is: %d\n", i);*/
      /*printf("arrInt[i] right now is: %d\n",arrInt[i]);*/
      timeTotal = timeTotal + arrInt[i];
    }
    else {
      break;
    }
  }

  int dayLow = arrInt[1];
  int dayHigh = arrInt[1];

  for (i = 1; i < runtime + 1; i++){
    if (arrInt[i] < dayLow) {
      dayLow  arrInt[i];
    }

    if (arrInt[i] > dayHigh + 1) {
      dayHigh = arrInt[i];
    }
  }

  printf("Your system has been active for %f minutes this week.\n", timeTotal);
  performanceRate = (double)timeTotal / 10080;
  performanceRate = performanceRate * 100;
  printf("Your system has a weekly performance rate of %f%%.\n", performanceRate);
  avgTime = timeTotal / 7;
  printf("Your system's daily average operating time is %f minutes/day.\n", avgTime);
  printf("Your system's longest runtime this week was %d minutes.\n", dayHigh);
  printf("Your system's shortest runtime this week was %d minutes.\n", dayLow);

  fclose(fi);
  return 0;
}
