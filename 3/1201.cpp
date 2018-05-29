#include <stdio.h>

int f[1001][1001];

int cal(int a[], int n, int m)
{
	int i, j;
	for (i = 1; i <= n; i++)
		f[i][1] = (f[i-1][1] + a[i]) % 9907;
	for (j = 2; j <= m; j++)
	for (i = j; i <= n; i++)
		f[i][j] = (f[i-1][j] + f[i-1][j-1] * a[i]) % 9907;
	return f[n][m];
}

int main(int argc, char *argv[])
{
	int a[1001];
	int n, m, i;
	int cas;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
			scanf("%d", a + i);
		printf("%d\n", cal(a, n, m));
	}

	return 0;
}
