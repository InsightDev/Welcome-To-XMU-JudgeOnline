#include <cstdio>
using namespace std;

double a[101][201];

int main(int argc, char *argv[])
{
	int n, i, j, k;
	double r;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		scanf("%lf", &a[i][j]);
	for (i = 1; i <= n; i++)
		a[i][n + i] = 1;

	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			if (i != k) {
				r = a[i][k] / a[k][k];
				for (j = k; j <= 2 * n; j++)
					a[i][j] -= a[k][j] * r;
			}
		}
		r = a[k][k];
		for (j = k; j <= 2 * n; j++)
			a[k][j] /= r;
	}

	for (i = 1; i <= n; i++) {
		for (j = n + 1; j <= 2 * n; j++) {
			printf("%.6f ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
