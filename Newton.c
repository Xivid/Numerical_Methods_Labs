#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//double f(double x) { return cos(x) - x; }
//double df(double x) { return -sin(x) - 1; }
//double f(double x) { return pow(2.718281828, -x) - sin(x); }
//double df(double x) { return -pow(2.718281828, -x) - cos(x); }
//double f(double x) { return x - pow(2.718281828, -x); }
//double df(double x) { return 1 + pow(2.718281828, -x); }
//double f(double x) { return x*x - 2*x*pow(2.718281828, -x) + pow(2.718281828, -2*x); }
//double df(double x) { return 2*x + 2*x*pow(2.718281828, -x) - 2*pow(2.718281828, -x) - 2*pow(2.718281828, -2*x); }
double f(double x) {return (231*pow(x, 6) - 315*pow(x, 4) + 105*pow(x, 2) - 5) / 16.0;}
double df(double x) {return (231*6*pow(x, 5) - 315*4*pow(x, 3) + 210*x) / 16.0;}

int main()
{
    int n = 1, flag = 0;
    int N; //Maximum iteration times
    double x0, x1, Tol, F, DF, eps1, eps2;
    printf("Initial root:\n");
    scanf("%lf", &x0);
    printf("e1, e2:\n");
    scanf("%lf%lf", &eps1, &eps2);
    printf("Input maximum iteration times N:\n");
    scanf("%d", &N);

    while (n <= N)
    {
        F = f(x0);
        DF = df(x0);
        if (fabs(F) < eps1)
        {
            printf("x0 = %.6lf\n", x0);
            flag = 1;
            break;
        }
        if (fabs(DF) < eps2)
            break;

        x1 = x0 - F / DF;
        Tol = fabs(x1 - x0);
        if(Tol < eps1)
        {
            printf("x1 = %.6lf\n", x1);
            flag = 1;
            break;
        }
        ++n, x0 = x1;
    }
    if(!flag)
        printf("Failed\n");
    else
    	printf("n = %d\n", n);
    return 0;
}
