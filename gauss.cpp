#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	double a[10][10], b[10], x[10];
	cout << "Input n: " << endl;
	cin >> n;
	cout << "Input matrix A and vector B: " << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
		cin >> b[i];
	}
	for (int k = 1; k < n; k++)
	{
		int p = k;
		for (int i = k+1; i <= n; i++)
			if (fabs(a[i][k]) > fabs(a[p][k]))
				p = i;
		if (fabs(a[p][k]) < 1e-6)
		{
			cout << "Singular!" << endl;
			exit(0);
		}
		if (p != k)
			for (int i = 1; i <= n; ++i)
			{
				double t = a[p][i]; a[p][i] = a[k][i]; a[k][i] = t;
			}
		for (int i = k+1; i <= n; i++)
		{
			double m = a[i][k] / a[k][k];
			for (int j = k+1; j <= n; j++)
			{
				a[i][j] -= a[k][j] * m;
			}
			b[i] -= b[k] * m;
		}
	}

	if (fabs(a[n][n]) < 1e-6)
	{
			cout << "Singular!" << endl;
			exit(0);
	}

	x[n] = b[n] / a[n][n];
	for (int k = n-1; k > 0; --k)
	{
		x[k] = b[k];
		for (int j = k+1; j <= n; j++)
			x[k] -= a[k][j] * x[j];
		x[k] /= a[k][k];
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << "x[" << i << "] = " << x[i] << endl;
	}
	return 0;
}
