#include <stdio.h>
#include <string.h>

int a[9][9];
int r[9][10];
int c[9][10];
int b[9][10];

int check()
{
	int i, j;

	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	memset(b, 0, sizeof(b));
	for (i = 0; i < 9; i++)
	for (j = 0; j < 9; j++)
	{
		if (r[i][a[i][j]])
			return 0;
		if (c[j][a[i][j]])
			return 0;
		if (b[i/3*3+j/3][a[i][j]])
			return 0;
		r[i][a[i][j]] = 1;
		c[j][a[i][j]] = 1;
		b[i/3*3+j/3][a[i][j]] = 1;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int n, i, j, k;

	scanf("%d", &n);
	for (k = 1; k <= n; k++) {
		for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			scanf("%d", &a[i][j]);
		printf("Case %d:\n", k);
		if (check())
			printf("Yes!\n");
		else
			printf("No!\n");
	}

	return 0;
}
