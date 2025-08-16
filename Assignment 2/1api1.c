// C program to generate random numbers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// Driver program
int main (void)
{
  float x, y, circ, piest, ea, d1, d2;
  int a = 0, b = 0, j;  //a=number of darts positioned inside the circle, b=total number of darts
  printf( "Enter a value of log(N):");
  scanf("%d", &j);
  printf ("VALUE OF N\t ESTIMATE OF PI\t APPROX ERROR\n");

  srand (3141592653);   //common seeding value to ensure uniformity
  
  for (int i = 0; i < pow (10, j); i++) //for loop that generates the values taken by N
  {
          
    x = (float) rand () / (RAND_MAX); //generating random number in (0,1) for X coordinate of dart
    y = (float) rand () / (RAND_MAX); //generating random number in (0,1) for Y coordinate of dart


    circ = pow (x, 2) + pow (y, 2);
    if (circ <= 1)    //checking condition for dart within circle
      {
       a++;  //every time a dart falls inside the circle we add one to the circle dart count
       b++;  //every time a dart falls inside the circle we add one to the total dart count
      }

    else
      {
       b++;  //every time a dart falls outside the circle we add one to the total dart count
      }
    piest = (float) 4 *a / b; //approximating the value of pi for the URV
    ea = fabs (piest - M_PI) / M_PI * 100;    //Approximate error of value calculated from the standard value of pi
    d1 = piest;   //this variable stores the values of pi approximation in every iteration and prints the final value alone through the printf function below
    d2 = ea;  //this variable stores the values of approximate error in every iteration and prints the final value alone through the printf function below

      }
  printf ("10^%d\t\t %f \t %f\n", j, d1, d2);
  return 0;

}
