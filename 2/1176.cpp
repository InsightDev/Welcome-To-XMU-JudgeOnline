#include <stdio.h>

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int a[10][10];
int n, m;

void search(int u, int v)
{
	int i, j, k;

	a[u][v] = 0;
	for (k = 0; k < 8; k++) {
		i = u + dr[k];
		j = v + dc[k];
		if (i >= 0 && i < n && j >= 0 && j < m && a[i][j])
			search(i, j);
	}
}

int main(int argc, char* argv[])
{
	int i, j;
	int count = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
		scanf("%d", &a[i][j]);

	for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
	{
		if (!a[i][j])
			continue;
		count += 1;
		search(i, j);
	}
	printf("%d\n", count);

	return 0;
}
