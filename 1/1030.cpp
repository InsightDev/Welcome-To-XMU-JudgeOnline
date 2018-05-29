#include <stdio.h>

int f[1001][1001];
char a[1002];
char b[1002];

int main(int argc, char* argv[])
{
	int n, m, i, j;

	scanf("%d %d", &n, &m);
	scanf("%s", a + 1);
	scanf("%s", b + 1);

	for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
	{
		if (a[i] == b[j])
			f[i][j] = f[i-1][j-1] + 1;
		else if (f[i-1][j] > f[i][j-1])
			f[i][j] = f[i-1][j];
		else
			f[i][j] = f[i][j-1];
	}
	printf("%d\n", f[n][m]);

	return 0;
}
