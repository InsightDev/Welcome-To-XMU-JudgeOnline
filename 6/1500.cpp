#include <stdio.h>
#include <limits.h>

int a[100][100];
int b[100];
int c[100];
int n;

int prim()
{
	int s, t, i, j;
	int sum = 0;

	b[1] = 1;
	for (i = 2; i <= n; i++) {
		c[i] = a[1][i];
		b[i] = 0;
	}
	for (i = 2; i <= n; i++) {
		s = INT_MAX;
		t = 0;
		for (j = 2; j <= n; j++) {
			if (!b[j] && c[j] < s) {
				s = c[j];
				t = j;
			}
		}
		b[t] = 1;
		sum += s;
		for (j = 2; j <= n; j++)
			if (!b[j] && a[t][j] < c[j])
				c[j] = a[t][j];
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int m, i, j, l;

	scanf("%d", &n);
	while (n) {
		m = n * (n - 1) / 2;
		while (m--) {
			scanf("%d %d %d", &i, &j, &l);
			a[i][j] = a[j][i] = l;
		}
		printf("%d\n", prim());
		scanf("%d", &n);
	}

	return 0;
}
