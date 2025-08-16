
#include <stdio.h>//for x=1 we change values similarly for x=2
#include <math.h>
double error (double t) //function for error absolute
{
   double e;
   e = fabs(t - 0.841345) ;
   return e;
}
double error2 (double t) //function for error absolute
{
   double e;
   e = fabs(t - 0.97725) ;
   return e;
}

double midpoint(double a, double b) //function to calculate the midpoint of interval
{
   double bisect;
   bisect = (a+b)/2.0;
   return bisect;
}
double f(double x) //function definition
{
   double y;
   y = exp((-1)*x*x/2);
   return y;
}
int main()
{
   printf("Erf(1)\n");
   double i,a,b,c;
   double x;
   x = 1.0000;
   double dx;
   for(int j = 4;j<=1024;j=j*2){ //for different values of n
   dx = (x+4.000000)/j;
   double area = 0.0000;
   i = -4.000000;
   for(int k =1;k<=j;k++) //for loop to calculate the integral following the algorithm
       
   {
      a = i;
      b = i +dx;
      c = midpoint(a,b);
      area = area + dx*f(c);
      i = i + dx;
   }
   area = area*(1/sqrt(2*(M_PI)));
   printf("The area enclosed is %lf\n",area);
   double et;
   et = error(area);
   printf("The error is %lf\n",et);
   }
   printf("Erf(2)\n");
  

   x = 2.0000;
   
   for(int j = 4;j<=1024;j=j*2){ //for different values of n
   double dx = (x+4.000000)/j;
   double area = 0.0000;
   double i = -4.000000;
   for(int k =1;k<=j;k++) //for loop to calculate the integral following the algorithm
       
   {
      a = i;
      b = i +dx;
      c = midpoint(a,b);
      area = area + dx*f(c);
      i = i + dx;
   }
   area = area*(1/sqrt(2*(M_PI)));
   printf("The area enclosed is %lf\n",area);
   double et;
   et = error2(area);
   printf("The error is %lf\n",et);
   }
}




