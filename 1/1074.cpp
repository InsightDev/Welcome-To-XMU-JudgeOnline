#include <stdio.h>
#include <limits.h>

int a[100][100];
int b[100];
int c[100];
int n;

int prim()
{
	int s, t, i, j;
	int sum = 0;

	b[0] = 1;
	for (i = 1; i < n; i++) {
		c[i] = a[0][i];
		b[i] = 0;
	}
	for (i = 1; i < n; i++) {
		s = INT_MAX;
		t = 0;
		for (j = 1; j < n; j++) {
			if (!b[j] && c[j] < s) {
				s = c[j];
				t = j;
			}
		}
		b[t] = 1;
		sum += s;
		for (j = 1; j < n; j++)
			if (!b[j] && a[t][j] < c[j])
				c[j] = a[t][j];
	}
	return sum;
}

int main(int argc, char *argv[])
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	printf("%d\n", prim());

	return 0;
}
