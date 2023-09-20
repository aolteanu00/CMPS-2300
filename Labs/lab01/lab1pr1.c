#include <stdio.h>
#include <stdlib.h>

int main(void){
  /* Initialize weekday variables */
  printf("Enter 7 numbers corresponding with active system time for each day of the week, respectively:\n");
  int day0;
  scanf("%d", &day0);
  int day1;
  scanf("%d", &day1);
  int day2;
  scanf("%d", &day2);
  int day3;
  scanf("%d", &day3);
  int day4;
  scanf("%d", &day4);
  int day5;
  scanf("%d", &day5);
  int day6;
  scanf("%d", &day6);

  /* Initialize array */
  int x[7];
  x[0] = day0;
  x[1] = day1;
  x[2] = day2;
  x[3] = day3;
  x[4] = day4;
  x[5] = day5;
  x[6] = day6;

  double timeTotal = day0 + day1 + day2 + day3 + day4 + day5 + day6;
  printf("Your system has been active for %f minutes this week.\n", timeTotal);

  double performanceRate = (double)timeTotal / 10080;
  performanceRate = performanceRate * 100;
  printf("Your system has a weekly performance rate of %f%%.\n", performanceRate);

  double avgTime = timeTotal / 7;
  printf("Your system's daily average operating time is %f minutes/day.\n", avgTime);

  int dayLow = x[0];
  int dayHigh = x[0];
  int i;

  for (i = 0; i < 7; i++){
    if (x[i] < dayLow) {
      dayLow = x[i];
    }

    if (x[i] > dayHigh) {
      dayHigh = x[i];
    }
  }

  printf("Your system's longest runtime this week was %d minutes.\n", dayHigh);
  printf("Your system's shortest runtime this week was %d minutes.\n", dayLow);

  return 0;
}
