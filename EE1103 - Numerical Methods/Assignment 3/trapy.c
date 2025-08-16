#include <stdio.h>
#include <math.h>
//trapezoid
double f(double x) //defining function
{
    //returns f(x)
    double y=exp(-x*x/2); //just inner integrand
    return y;
}
int main()
{
    int n;   //number of intervals
    double x=1;  //value of x as entered by the user

    double s=0.841345;//correct value of erf1
    printf("ERF(1)\n");
    printf("NUMBER OF SUBINTERVALS  ABSOLUTE ERROR   value\n");

     //x1 and x2 are the lower and upper limit, respectively, of each Riemann interval
    double fx1,fx2,fx;
    for (int j=2; j<11; j++)
    {
        n=pow(2,j);
        double i=(x+4)/n,sum=0;  //i=size of each interval
        double x1=-4.0, x2=x1+i;
        while(x2<=x)
        {
            fx1=f(x1); //function value of lower bound
            fx2=f(x2);  //function value of upper bound
            fx=(fx1+fx2)/2*i;  //area of trapezium
            sum+=fx; //updating counter value
            x1=x2; //continuation condition
            x2=x1+i;
        }
    sum = sum /pow(2*M_PI,0.5); //FINAL VALUE OF ERF
    
    double ae=fabs(sum-s); //ABSOLUTE ERROR CALCULATION

    printf("%d\t\t\t %lf \t%lf\n",n,ae,sum);
    
    }
    x=2;  //value of x as entered by the user

    s=0.97725;//correct value of erf1
    printf("ERF(2)\n");
    printf("NUMBER OF SUBINTERVALS  ABSOLUTE ERROR   value\n");


    for (int j=2; j<11; j++)
    {
        n=pow(2,j);
        double i=(x+4)/n,sum=0;  //i=size of each interval
        double x1=-4.0, x2=x1+i;
        while(x2<=x)
        {
            fx1=f(x1); //function value of lower bound
            fx2=f(x2);  //function value of upper bound
            fx=(fx1+fx2)/2*i;  //area of trapezium
            sum+=fx; //updating counter value
            x1=x2; //continuation condition
            x2=x1+i;
        }
    sum = sum /pow(2*M_PI,0.5); //FINAL VALUE OF ERF
    
    double ae=fabs(sum-s); //ABSOLUTE ERROR CALCULATION

    printf("%d\t\t\t %lf \t%lf\n",n,ae,sum);
   
    }
    
}


