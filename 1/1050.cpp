#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a[101][101];

int floyd(int n)
{
	int i, j, k, ans = 0;

	for (k = 1; k <= n; k++)
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		if (a[i][k] != INT_MAX &&
			a[k][j] != INT_MAX &&
			a[i][k] + a[k][j] < a[i][j])
			a[i][j] = a[i][k] + a[k][j];
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		if (a[i][j] > ans)
			ans = a[i][j];
	return ans;
}

int main(int argc, char** argv) {
	int n, m, i, j;
	int cas = 1;

	scanf("%d %d", &n, &m);
	while (n || m) {
		for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			a[i][j] = i == j ? 0 : INT_MAX;
		while (m--) {
			scanf("%d %d", &i, &j);
			a[i][j] = a[j][i] = 1;
		}
		printf("Case %d:\n", cas++);
		int ans = floyd(n);
		if (ans == INT_MAX)
			printf("Secret.\n");
		else
			printf("%d\n", ans);
		scanf("%d %d", &n, &m);
	}

	return 0;
}
