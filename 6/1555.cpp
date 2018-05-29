#include <stdio.h>

int a[50][50];

int main(int argc, char* argv[])
{
	int n, q;
	int i, j, k;

	scanf("%d %d", &n, &q);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);

	for (k = 0; k < n; k++)
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		if (!a[i][j])
			a[i][j] = a[i][k] && a[k][j];

	while (q--) {
		scanf("%d %d", &i, &j);
		printf("%d\n", a[i][j]);
	}

	return 0;
}
