#include <stdio.h>

int a[101][101];
int b[101][101];
int n, m, s;

int find()
{
	int i, j, k, c;
	int ans = 0;

	for (i = 1; i <= n; i++) {
		c = 0;
		for (j = 1; j < s; j++)
			c += b[i][j]; 
		for (j = s; j <= m; j++) {
			c += b[i][j];
			if (!c)
				for (k = j; k > j - s; k--)
					if (a[i][k] > ans)
						ans = a[i][k];
			c -= b[i][j-s+1];
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int cas, i, j;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d %d", &n, &m, &s);
		for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
		for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			scanf("%d", &b[i][j]);
		printf("%d\n", find());
	}

	return 0;
}
