#include <stdio.h>
#include <math.h>

void mp(); //function definitions
void trap();
void simps();
int main()

{
    printf("METHOD \t\tN\t ESTIMATE \t ABSOLUTE PERCENT ERROR\n");
    mp();
    trap(); //FUNCTION CALL
    simps();
    
    FILE *pipei = popen("gnuplot -persist", "w"); //for plotting all the midpoint method results
    fprintf(pipei, "set title \"ABSOLUTE PERCENT ERRORS VS NUMBER OF SUBINTERVALS BY MIDPOINT METHOD\"\n");
    fprintf(pipei, "set xlabel \"NUMBER OF SUBINTERVALS\"\n");
    fprintf(pipei, "set ylabel \"ABSOLUTE PERCENT ERRORS\"\n");
    fprintf(pipei, "set grid\n");
    fprintf(pipei, "plot 'mp1.txt' with lines\n");

    FILE *pipe = popen("gnuplot -persist", "w");  //for plotting all the trapezoidal method results
    fprintf(pipe, "set title \"ABSOLUTE PERCENT ERRORS VS NUMBER OF SUBINTERVALS BY TRAPEZOIDAL METHOD\"\n");
    fprintf(pipe, "set xlabel \"NUMBER OF SUBINTERVALS\"\n");
    fprintf(pipe, "set ylabel \"ABSOLUTE PERCENT ERRORS\"\n");
    fprintf(pipe, "set grid\n");
    fprintf(pipe, "plot 'trap1.txt' with lines\n");

    FILE *pipeu = popen("gnuplot -persist", "w"); //for plotting all the simpsons method results
    fprintf(pipeu, "set title \"ABSOLUTE PERCENT ERRORS VS NUMBER OF SUBINTERVALS BY SIMPSONS METHOD\"\n");
    fprintf(pipeu, "set xlabel \"NUMBER OF SUBINTERVALS\"\n");
    fprintf(pipeu, "set ylabel \"ABSOLUTE PERCENT ERRORS\"\"\n");
    fprintf(pipeu, "set grid\n");
    fprintf(pipeu, "plot 'simp1.txt' with lines\n");

    
}

void mp() //midpoint method function
{
    double a, s, ae;
    for (int j=2; j<11; j++) //POWER OF 2
    {
        int n=pow(2,j); //NUMBER OF INTERVALS
        a=0; //VALUE OF COUNTER HAS TO BE UPDATED EVERY ITERATION
        double x=M_PI/(n*2);
        for (int i=1; i<2*n; i+=2)
        {
            
            a=a+sin(i*x); //UPDATING VALUE OF COUNTER
             
        }
    s=a/n*M_PI;
    ae=fabs((2-s));
    printf("MIDPOINT\t%d\t %lf\t% lf\n",n,s,ae);
    FILE* data1=fopen("mp1.txt","a+");
    fprintf(data1,"%d\t%f\n",n,ae);

    }
   
}


void trap() //trapezoidal method
{
    double a2, s2,ae2;
    int  n2, j2=2;
    
    while (j2<11) //POWER OF 2
    {
        n2=pow(2,j2); //NUMBER OF INTERVALS
        a2=0; //VALUE OF COUNTER HAS TO BE UPDATED EVERY ITERATION
        double x2=M_PI/n2;
        for (int i=0; i<n2; i++)
        {
                
            if (i==0 || i==M_PI)
            {
                a2=a2+sin(i*x2); //UPDATING VALUE OF COUNTER
            }
            else
            {
                a2=a2 + 2*sin(i*x2); //UPDATING VALUE OF COUNTER ALTERNATIVELY
            }
        }
        s2=a2/n2*M_PI/2;
        ae2=fabs((2-s2));
        printf("TRAPEZOID  \t%d\t %lf\t %lf\n",n2,s2,ae2);
        FILE* data2=fopen("trap1.txt","a+");
        fprintf(data2,"%d\t%f\n",n2,ae2);

        j2++;
    }
   
}

void simps() //simpsons method
{
    double a3, s3,ae3;
    int  n3, j3=2;
    
    while (j3<11) //POWER OF 2
    {
        n3=pow(2,j3); //NUMBER OF INTERVALS
        a3=0; //VALUE OF COUNTER HAS TO BE UPDATED EVERY ITERATION
        double x3=M_PI/n3;
        for (int i=0; i<n3; i++)
        {
                
            if (i==0 || i==M_PI)
            {
                a3=a3+sin(i*x3); //UPDATING VALUE OF COUNTER FOR ENDING VALUES
            }
            else if (i%2==0)
            {
                a3=a3 + 2*sin(i*x3); //UPDATING VALUE OF COUNTER FOR EVEN VALUES OF INTERVALS
            }
            else if (i%2!=0)
            {
                a3=a3 + 4*sin(i*x3); //UPDATING VALUE OF COUNTER FOR ODD VALUES OF INTERVALS
            }
        }
        s3=a3/n3*M_PI/3;
        ae3=fabs((2-s3));
        printf("SIMPSONS  \t%d\t %lf\t %lf\n",n3,s3,ae3);
        FILE* data3=fopen("simp1.txt","a+");
        fprintf(data3,"%d\t%f\n",n3,ae3);
     
        j3++;
    }
   
}

