#include <stdio.h>

int f[1001][8193];
int c[1001];
int v[1001];
int x[1001];

int main(int argc, char *argv[])
{
	int n, m, i, j;
	int cnt = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", c + i);
	for (i = 1; i <= n; i++)
		scanf("%d", v + i);

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			f[i][j] = f[i-1][j];
			if (c[i] <= j && f[i-1][j-c[i]] + v[i] > f[i][j])
				f[i][j] = f[i-1][j-c[i]] + v[i];
		}
	}

	j = m;
	for (i = n; i >= 1; i--) {
		if (f[i][j] != f[i-1][j]) {
			cnt++;
			x[i] = 1;
			j -= c[i];
		}
	}

	printf("%d\n", cnt);
	for (i = 1; i <= n; i++) {
		if (x[i]) {
			printf("%d", i);
			printf("%c", --cnt ? ' ' : '\n');
		}
	}

	return 0;
}
