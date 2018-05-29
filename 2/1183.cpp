#include <stdio.h>
#include <stdlib.h>

int x[] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
int y[] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
int a[501][501];
int c[501][501];

int main(int argc, char *argv[])
{
	int n, m, u, v;
	int i, j, k;
	int sx, sy;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
		scanf("%d", &a[i][j]);

	for (u = 2; u < n; u++)
	for (v = 2; v < m; v++)
	{
		k = 0;
		sx = 0;
		sy = 0;
		for (i = -1; i <= 1; i++)
		for (j = -1; j <= 1; j++)
		{
			sx += a[u+i][v+j] * x[k];
			sy += a[u+i][v+j] * y[k++];
		}
		c[u][v] = abs(sx) + abs(sy);
		if (c[u][v] > 255)
			c[u][v] = 255;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (i == 1 || i == n || j == 1 || j == m)
				printf("%d ", a[i][j]);
			else
				printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	return 0;
}
