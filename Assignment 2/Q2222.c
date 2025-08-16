
// C program to generate random numbers
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>

 
// Driver program
int main(void)
{   float U1,U2,E,X,Y; //defining variables
  
    srand(0);   //common seeding value
   
    for(int i = 0; i<pow(10,4); i++){
        U1=(float)  rand()/(RAND_MAX);  //generating random numbers in (0,1)
        U2=(float) rand()/(RAND_MAX);
        E=log(1/U1); //using the uniform random variable1
        X=pow(E,0.5)*cos(2*M_PI*U2); //using the uniform random variable2
        Y=pow(E,0.5)*sin(2*M_PI*U2);
        //printf(" %f \t\t %f\n ", x,y);

        printf("%f\n",X); //instead of opening a file, we copy the values from output to plot in the histogram and edf. this is pretty straightforward.
    }

    return 0; 
  
}



