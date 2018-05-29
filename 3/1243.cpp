#include <stdio.h>
#include <limits.h>

int c[200][200];
int a[10000];

int main(int argc, char *argv[])
{
	int n, m;
	int i, j, k;
	int sum, ans;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		scanf("%d", &c[i][j]);

	for (k = 1; k <= n; k++)
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		if (c[i][k] + c[k][j] < c[i][j])
			c[i][j] = c[i][k] + c[k][j];

	ans = INT_MAX;
	for (k = 1; k <= n; k++) {
		sum = 0;
		for (i = 1; i <= m; i++)
			sum += c[a[i]][k];
		if (sum < ans)
			ans = sum;
	}
	printf("%d\n", ans);

	return 0;
}
