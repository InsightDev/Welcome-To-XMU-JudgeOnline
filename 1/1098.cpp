#include <stdio.h>
#include <stdlib.h>

int b[21];
int c[21];
int n;

int check(int k)
{
	int i;
	for (i = 1; i < k; i++)
		if (abs(c[k] - c[i]) == k - i)
			return 0;
	return 1;
}

int queen(int k)
{
	if (k > n)
		return 1;
	for (int i = 1; i <= n; i++) {
		if (b[i])
			continue;
		b[i] = 1;
		c[k] = i;
		if (check(k) && queen(k + 1))
			return 1;
		b[i] = 0;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int i;

	scanf("%d", &n);
	queen(1);

	for (i = 1; i <= n; i++)
		printf("%d %d\n", i, c[i]);

	return 0;
}
