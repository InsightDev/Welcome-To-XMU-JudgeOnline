#include <stdio.h>

int a[1000];
int b[1000];
int c[1000];
int d[1000];
int n;

void calculate()
{
	c[0] = 1;
	d[0] = 1;
	for (int i = 1; i < n; i++) {
		c[i] = 0;
		d[i] = 0;
		for (int j = 0; j < i; j++) {
			if (c[j] && a[j] <= i && i <= b[j]) {
				c[i] = 1;
				d[i] += d[j];
				d[i] %= 9227465;
			}
		}
	}
	if (c[n-1])
		printf("%d\n", d[n-1]);
	else
		printf("Impossible\n");
}

int main(int argc, char *argv[])
{
	int cas, i;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		for (i = 0; i < n - 1; i++)
			scanf("%d %d", &a[i], &b[i]);
		calculate();
	}

	return 0;
}
