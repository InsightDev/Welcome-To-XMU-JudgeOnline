#include <cstdio>

int a[1000][1000];
int b[1000][1000];
int c[1000][1000];

int check(int n)
{
	int i, j, k;
	long long t;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		t = 0;
		for (k = 0; k < n; k++)
			t += a[i][k] * b[k][j];
		if (c[i][j] != t % 9997)
			return 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &b[i][j]);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &c[i][j]);
	printf("%s\n", check(n) ? "Yes" : "No");

	return 0;
}
