#include <stdio.h>

int c[20000];
int a[100];

int main(int argc, char* argv[])
{
	int cas, v;
	int n, m;
	int i, j;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &m, &n);
		v = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", a + i);
			if (a[i] > v)
				v = a[i];
		}
		for (i = 1; i < m + v; i++)
			c[i] = 0xff;

		for (i = 0; i < n; i++)
		for (j = m - 1; j >= 0; j--)
			if (c[j] + 1 < c[j+a[i]])
				c[j+a[i]] = c[j] + 1;

		for (i = m; i < m + v; i++) {
			if (c[i] != 0xff) {
				printf("%d %d\n", i, c[i]);
				break;
			}
		}
	}

	return 0;
}
