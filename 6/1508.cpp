#include <stdio.h>

int f[1001][1001];
int s[1001][1001];

int main(int argc, char* argv[])
{
	int n, i, j;
	int l = 1;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &f[i][i]);

	for (i = 1; i <= n; i++)
	for (j = i; j <= n; j++)
		s[i][j] = s[i][j-1] + f[j][j];

	while (++l <= n) {
		for (i = 1; i <= n; i++) {
			j = i + l - 1;
			if (j > n)
				break;
			if (f[i+1][j] < f[i][j-1])
				f[i][j] = s[i][j] - f[i+1][j];
			else
				f[i][j] = s[i][j] - f[i][j-1];
		}
	}
	printf("%d %d\n", f[1][n], s[1][n] - f[1][n]);

	return 0;
}
