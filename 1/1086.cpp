#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double a[50000][10];
bool b[10], c[10];
int n, m;

double average()
{
	int i, j;
	double s = 0;
	for (i = 0; i < n; i++) {
		double t = 0;
		for (j = 0; j < m; j++)
			if (b[j] && a[i][j] > t)
				t = a[i][j];
		s += t;
	}
	return s / n;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	double t, s = 0;

	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
		scanf("%lf%%", &a[i][j]);

	for (i = 0; i < m - k; i++)
		b[i] = 0;
	for (i = m - k; i < m; i++)
		b[i] = 1;

	do {
		t = average();
		if (t > s) {
			s = t;
			memcpy(c, b, m);
		}
	} while (next_permutation(b, b + m));

	for (i = 0; i < m; i++)
		if (c[i])
			printf("%d%c", i, --k ? ' ' : '\n');
	printf("%.2f%%\n", s);

	return 0;
}
