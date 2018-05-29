#include <stdio.h>

int main(int argc, char* argv[])
{
	int a[100][100];
	int b[100][100];
	int c[100][100] = {0};
	int n, m, q;
	int i, j, k;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
		scanf("%d", &a[i][j]);
	scanf("%d %d", &m, &q);
	for (i = 0; i < m; i++)
	for (j = 0; j < q; j++)
		scanf("%d", &b[i][j]);

	for (i = 0; i < n; i++)
	for (j = 0; j < q; j++)
	for (k = 0; k < m; k++)
		c[i][j] += a[i][k] * b[k][j];

	for (i = 0; i < n; i++) {
		printf("%d", c[i][0]);
		for (j = 1; j < q; j++)
			printf(" %d", c[i][j]);
		printf("\n");
	}

	return 0;
}
