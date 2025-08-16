#include <stdio.h>
#include <math.h>

double simps(); //definition

double f(double x)
{
    return exp(-x*x/2);//function
}

void main()
{
    printf("METHOD \t\tN\t ESTIMATE \t ABSOLUTE PERCENT ERROR\n"); //tabulation printing headlines

    simps();
    
}

double  simps()
{
    double a3, s3,ae3,x3;
    int  n3, j3=2;
    printf("Erf(1)\n");
    while (j3<11)//powers of 2 initialisation
    {
        
        n3=pow(2,j3); //number of subintervals
        a3=0;
        double x=1; //higher bound
        double r=0.841345;
        a3=a3+f(-4)+f(x); //summing the function for beginnning and end
        x3=(x+4)/n3; //size of interval
        for (int i=1; i<n3; i++)
        {
            if (i%2==0)   //  even values
            {
                a3=a3 + 2*f(-4+i*x3);
            }
            else if (i%2!=0) //odd values
            {
                a3=a3 + 4*f(-4+i*x3);
            }
        }
        s3=a3*x3/3/pow(2*M_PI,0.5);//summing up
        ae3=fabs((r-s3));//errors ABSOLUTE
        printf("SIMPSONS  \t%d\t %0.12lf\t %0.12lf\n",n3,s3,ae3);//final print
        j3++;
    }
    printf("Erf(2)\n");
    j3=2;
    while (j3<11)//powers of 2 initialisation
    {
        
        n3=pow(2,j3); //number of subintervals
        a3=0;
        double x=2; //higher bound
        double r=0.97725;
        a3=a3+f(-4)+f(x); //summing the function for beginnning and end
        x3=(x+4)/n3; //size of interval
        for (int i=1; i<n3; i++)
        {
            if (i%2==0)   //  even values
            {
                a3=a3 + 2*f(-4+i*x3);
            }
            else if (i%2!=0) //odd values
            {
                a3=a3 + 4*f(-4+i*x3);
            }
        }
        s3=a3*x3/3/pow(2*M_PI,0.5);//summing up
        ae3=fabs((r-s3));//errors ABSOLUTE
        printf("SIMPSONS  \t%d\t %0.12lf\t %0.12lf\n",n3,s3,ae3);//final print
        j3++;
    }
   
}







