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
  
   //common seeding value to ensure uniformity
  for (int j = 2; j < 8; j++)  //for  plotting values from 100 to 10^8
  {  srand (3141592653);
      for (int i = 0; i < pow(10,j); i++) //for loop that generates the values taken by N
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
      FILE* data=fopen("estimate_pi.txt","a+");  //this inputs all the final values of approximation for a given number of tries to a file
      fprintf(data,"%d\t%f\n",j,d1);

      FILE* data2=fopen("aerror_pi.txt","a+");  //this inputs all the final approximate errors for a given number of tries to a file
      fprintf(data2,"%d\t%f\n",j,d2);
  }
    


    FILE *pipe = popen("gnuplot -persist", "w");    //this plots the  graph using GNUPLOT for  values of approximation vs iterations
    fprintf(pipe, "set title \"PI APPROXIMATION VS ITERATIONS\"\n");
    fprintf(pipe, "set xlabel \"ITERATIONS EXPRESSED IN LOG_{10} SCALE\"\n");
    fprintf(pipe, "set ylabel \"CORRESPONDING APPROXIMATION OF PI\"\n");
    fprintf(pipe, "set grid\n");
    fprintf(pipe, "plot 'estimate_pi.txt' with lines title 'pi estimates', 3.141592653 title 'pi actual' lt  rgb 'green'\n");
 

    FILE *pipe2 = popen("gnuplot -persist", "w");   //this plots the  graph using GNUPLOT for approximate errors vs iterations
    fprintf(pipe2, "set title \"error percent vs ITERATIONS\"\n");
    fprintf(pipe2, "set xlabel \"log of iterations\"\n");
    fprintf(pipe2, "set ylabel \"error percent of pi\"\n");
    fprintf(pipe2, "set grid\n");
    fprintf(pipe2, "plot 'aerror_pi.txt' with lines\n");
    
    
  return 0;

}
