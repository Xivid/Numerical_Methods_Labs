#include <cstdio>
#include <cstdlib>
#include <cmath>

double f(double x, double y)
{
	return -y*y;
}

double y(double x)
{
    return 1/(x+1);
}
int main()
{
	double a, b, ya, x0, y0, x1, y1, h, K1, K2, K3, K4;
	int N;
	printf("Input a, b, ya, N:\n");
	scanf("%lf%lf%lf%d", &a, &b, &ya, &N);

	x0 = a, y0 = ya, h = (b-a) / N;
	for (int i = 1; i <= N; ++i)
	{
		K1 = h * f(x0, y0);
		K2 = h * f(x0 + h/2, y0 + K1/2);
		K3 = h * f(x0 + h/2, y0 + K2/2);
		K4 = h * f(x0 + h, y0 + K3);

		x1 = x0 + h;
		y1 = y0 + (K1 + 2*K2 + 2*K3 + K4) / 6;

		printf("x1 = %lf, y1 = %lf, Y1 = %lf, %lf%%\n", x1, y1, y(x1), 100*fabs((y1-y(x1))/y(x1)));
		x0 = x1, y0 = y1;
	}
	return 0;
}
