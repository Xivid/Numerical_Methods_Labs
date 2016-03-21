#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double p11(double x)
{
    return x*x;
}
int main()
{
    double a, b, N, eps, h, T1 = 0, T2 = 0, R1 = 0, R2 = 0, C1 = 0, C2 = 0, S1 = 0, S2 = 0, (*f)(double), s;
    int k, m, i, ii;

    printf("Input a, b, N, ¦Å:\n");
    scanf("%lf%lf%lf%lf", &a, &b, &N, &eps);
    f = p11;
    h = (b - a) / N;
    m = 1;
    T1 = 0.5 * h * (f(a) + f(b));
    printf("T1 = %lf\n", T1);
    //getchar();
    for(i = 2; i <= N; i++)
    {
        ii = (1 << (i-1));
        s = 0;
        for(k = 1; k <= ii; k++)
            s += f(a + ((double)k - 0.5) * h);
        T2 = 0.5 * T1 + 0.5 * h * s;
        printf("T2 = %lf\n", T2);
//getchar();
        S2 = 1.0/3 * (4 * T2 - T1);
        printf("S2 = %lf\n", S2);
//getchar();
        printf("m = %d\n", m );
        if(m != 1)
        {
            C2 = 1.0/15 * (16 * S2 - S1);
            printf("C2 = %lf\n", C2);
        }
        else if(m != 2)
        {
            R2 = 1.0/63 * (64 * C2 - C1);
            printf("R2 = %lf\n", R2);
        }
        else if(m != 3 && fabs(R2 - R1) < eps)
            break;
//getchar();
        R1 = R2;
        C1 = C2;
        S1 = S2;
        T1 = T2;
        h = h / 2;
        m = m + 1;
    }
    return 0;
}
