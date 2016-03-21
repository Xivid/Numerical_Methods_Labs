#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
const double e = 2.718281828L;
const double pi = 3.1415926536L;
double lagrange(double x[], double fx[], int n, double X){
    double y = 0, l;
    int k, j;
    for(k = 0; k <= n; ++k){
        l = 1.0;
        for(j = 0; j <= n; ++j) if(j != k)
            l *= (X - x[j]) / (x[k] - x[j]);
        y += l * fx[k];
    }
    return y;
}

int main(){
    int i, j, k, n;
    double *x, *fx, X, h;
    x = (double*)malloc(sizeof(double) * 100);
    fx = (double*)malloc(sizeof(double) * 100);
    
    //Testing for the lagrange function
    printf("Input n(number of points - 1): ");
    scanf("%d", &n);
    printf("Input x[] and fx[]: \n");
    for(i = 0; i <= n; ++i) scanf("%lf %lf", x + i, fx + i);
    printf("Input X: \n");
    scanf("%lf", &X);
    printf("Pn(%lf) = %lf\n", X, lagrange(x, fx, n, X));
    
    /*
    //Problem 1(1)
    n = 20; //5, 10
    h = 10.0 / n;
    for(i = 0; i <= n; ++i) {
        x[i] = -5.0 + i * h;
        fx[i] = 1.0 / (1 + x[i]*x[i]);
    }
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 0.75, lagrange(x, fx, n, 0.75), 0.75, 1.0/(1+0.75*0.75));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 1.75, lagrange(x, fx, n, 1.75), 1.75, 1.0/(1+1.75*1.75));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 2.75, lagrange(x, fx, n, 2.75), 2.75, 1.0/(1+2.75*2.75));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 3.75, lagrange(x, fx, n, 3.75), 3.75, 1.0/(1+3.75*3.75));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 4.75, lagrange(x, fx, n, 4.75), 4.75, 1.0/(1+4.75*4.75));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, 1.0 / (1 + X*X));
    }
    */
    /*
    //Problem 1(2)
    n = 20; //5, 10
    h = 2.0 / n;
    for(i = 0; i <= n; ++i) {
        x[i] = -1.0 + i * h;
        fx[i] = pow(e, x[i]);
    }
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", -0.95, lagrange(x, fx, n, -0.95), -0.95, pow(e, -0.95));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", -0.05, lagrange(x, fx, n, -0.05), -0.05, pow(e, -0.05));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 0.05, lagrange(x, fx, n, 0.05), 0.05, pow(e, 0.05));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 0.95, lagrange(x, fx, n, 0.95), 0.95, pow(e, 0.95));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, pow(e, X));
    }
    */
    /*
    //Problem 2(1)
    n = 5; //5, 10
    h = 2.0 / n;
    for(i = 0; i <= n; ++i) {
        x[i] = -1.0 + i * h;
        fx[i] = 1.0 / (1 + x[i]*x[i]);
    }
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", -0.95, lagrange(x, fx, n, -0.95), -0.95, 1.0/(1+(-0.95)*(-0.95)));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", -0.05, lagrange(x, fx, n, -0.05), -0.05, 1.0/(1+(-0.05)*(-0.05)));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 0.05, lagrange(x, fx, n, 0.05), 0.05, 1.0/(1+0.05*0.05));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 0.95, lagrange(x, fx, n, 0.95), 0.95, 1.0/(1+0.95*0.95));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, 1.0 / (1 + X*X));
    }
    */
    /*
    //Problem 2(2)
    n = 20; //5, 10
    h = 2.0 / n;
    for(i = 0; i <= n; ++i) {
        x[i] = -1.0 + i * h;
        fx[i] = pow(e, x[i]);
    }
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", -4.75, lagrange(x, fx, n, -4.75), -4.75, pow(e, -4.75));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", -0.25, lagrange(x, fx, n, -0.25), -0.25, pow(e, -0.25));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 0.25, lagrange(x, fx, n, 0.25), 0.25, pow(e, 0.25));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 4.75, lagrange(x, fx, n, 4.75), 4.75, pow(e, 4.75));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, pow(e, X));
    }
    */
    /*
    //Problem 3(1)
    n = 20; //5, 10
    for(i = 0; i <= n; ++i) {
        x[i] = cos((2*i + 1) * pi / (2 * (n + 1)));
        fx[i] = 1.0 / (1 + x[i]*x[i]);
    }
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", -0.95, lagrange(x, fx, n, -0.95), -0.95, 1.0/(1+(-0.95)*(-0.95)));
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", -0.05, lagrange(x, fx, n, -0.05), -0.05, 1.0/(1+(-0.05)*(-0.05)));
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", 0.05, lagrange(x, fx, n, 0.05), 0.05, 1.0/(1+0.05*0.05));
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", 0.95, lagrange(x, fx, n, 0.95), 0.95, 1.0/(1+0.95*0.95));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %.8lf || f(%lf) = %.8lf\n", X, lagrange(x, fx, n, X), X, 1.0 / (1 + X*X));
    }
    */
    /*
    //Problem 3(2)
    n = 20; //5, 10
    for(i = 0; i <= n; ++i) {
        x[i] = cos((2*i + 1) * pi / (2 * (n + 1)));
        fx[i] = pow(e, x[i]);
    }
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", -0.95, lagrange(x, fx, n, -0.95), -0.95, pow(e, -0.95));
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", -0.05, lagrange(x, fx, n, -0.05), -0.05, pow(e, -0.05));
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", 0.05, lagrange(x, fx, n, 0.05), 0.05, pow(e, 0.05));
    printf("Pn(%lf) = %.10lf || f(%lf) = %.10lf\n", 0.95, lagrange(x, fx, n, 0.95), 0.95, pow(e, 0.95));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, pow(e, X));
    }
    */
    /*
    //Problem 4(1)
    n = 2;
    x[0] = 1; fx[0] = 1;
    x[1] = 4; fx[1] = 2;
    x[2] = 9; fx[2] = 3;
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 5.0, lagrange(x, fx, n, 5), 5.0, sqrt(5));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 50.0, lagrange(x, fx, n, 50), 50.0, sqrt(50));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 115.0, lagrange(x, fx, n, 115), 115.0, sqrt(115));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 185.0, lagrange(x, fx, n, 185), 185.0, sqrt(185));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, sqrt(X));
    }
    */
    /*
    //Problem 4(2)
    n = 2;
    x[0] = 36; fx[0] = 6;
    x[1] = 49; fx[1] = 7;
    x[2] = 64; fx[2] = 8;
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 5.0, lagrange(x, fx, n, 5), 5.0, sqrt(5));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 50.0, lagrange(x, fx, n, 50), 50.0, sqrt(50));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 115.0, lagrange(x, fx, n, 115), 115.0, sqrt(115));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 185.0, lagrange(x, fx, n, 185), 185.0, sqrt(185));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, sqrt(X));
    }
    */
    /*
    //Problem 4(3)
    n = 2;
    x[0] = 100; fx[0] = 10;
    x[1] = 121; fx[1] = 11;
    x[2] = 144; fx[2] = 12;
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 5.0, lagrange(x, fx, n, 5), 5.0, sqrt(5));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 50.0, lagrange(x, fx, n, 50), 50.0, sqrt(50));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 115.0, lagrange(x, fx, n, 115), 115.0, sqrt(115));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 185.0, lagrange(x, fx, n, 185), 185.0, sqrt(185));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, sqrt(X));
    }
    */
    ///*
    //Problem 4(4)
    n = 2;
    x[0] = 169; fx[0] = 13;
    x[1] = 196; fx[1] = 14;
    x[2] = 225; fx[2] = 15;
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 5.0, lagrange(x, fx, n, 5), 5.0, sqrt(5));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 50.0, lagrange(x, fx, n, 50), 50.0, sqrt(50));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 115.0, lagrange(x, fx, n, 115), 115.0, sqrt(115));
    printf("Pn(%lf) = %lf || f(%lf) = %lf\n", 185.0, lagrange(x, fx, n, 185), 185.0, sqrt(185));
    printf("\n");
    for(i = 0; i <= n; ++i) {
        X = x[i];
        printf("Pn(%lf) =  %lf || f(%lf) = %lf\n", X, lagrange(x, fx, n, X), X, sqrt(X));
    }
    //*/
    free(x);
    free(fx);
    return 0;
}
