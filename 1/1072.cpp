#include <stdio.h>

int f[31][31];

int dp(int n, int m)
{
	int i, j, k, t;

	for (i = 1; i <= n; i++)
		f[i][1] = i;
	for (j = 2; j <= m; j++) {
		for (i = j; i <= n; i++) {
			f[i][j] = 0;
			for (k = j - 1; k < i; k++) {
				t = f[k][j-1] * (i - k);
				if (t > f[i][j])
					f[i][j] = t;			
			}
		}
	}
	return f[n][m];
}

int main(int argc, char *argv[])
{
	int n, i, t;
	int s = 0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		t = dp(n, i);
		if (t > s)
			s = t;
	}
	printf("%d\n", s);

	return 0;
}
