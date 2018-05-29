#include <stdio.h>

int a[100][100];
int b[100][100];
int c[100][100];

int main(int argc, char *argv[])
{
	int m, n, p;
	int i, j, k;

	scanf("%d %d %d", &m, &n, &p);
	for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
	for (j = 0; j < p; j++)
		scanf("%d", &b[i][j]);
	
	for (i = 0; i < m; i++)
	for (j = 0; j < p; j++)
	for (k = 0; k < n; k++)
		c[i][j] += a[i][k] * b[k][j];

	for (i = 0; i < m; i++) {
		for (j = 0; j < p; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}

	return 0;
}
