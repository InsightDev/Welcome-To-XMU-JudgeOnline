#include <stdio.h>

int a[948][1001];
int v[1001][1001];

int check(int *p, int m)
{
	for (int i = 2; i <= m; i++)
		if (p[i] - p[i-1] != 1)
			return 0;
	return 1;
}

int count(int m)
{
	int i, j, k;

	for (j = 1; j <= m; j++)
		a[0][j] = j;
	i = 0;
	do {
		i++;
		k = 0;
		for (j = 2; j <= m; j += 2)
			a[i][++k] = a[i-1][j];
		for (j = 1; j <= m; j += 2)
			a[i][++k] = a[i-1][j];
	} while (!check(a[i], m));
	return i;
}

int main(int argc, char *argv[])
{
	int n, m, r;
	int i, j, k;

	while (scanf("%d %d", &n, &m) != EOF) {
		for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &v[i][j]);
		r = count(m);
		scanf("%d", &k);
		scanf("%d %d", &i, &j);
		printf("%d\n", v[i][a[k%r][j]]);
	}

	return 0;
}
