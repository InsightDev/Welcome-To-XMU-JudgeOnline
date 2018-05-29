#include <stdio.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int v[6] = { 500, 100, 50, 10, 5, 1 };
int p[6];

int main(int argc, char *argv[])
{
	int n, c, i, k;

	scanf("%d", &n);
	for (i = 0; i < 6; i++)
		scanf("%d", p + i);

	i = 0;
	c = 0;
	n = 1000 - n * 25;
	while (n && i < 6) {
		k = MIN(p[i], n / v[i]);
		n -= k * v[i];
		c += k;
		i += 1;
	}
	printf("%d\n", n ? -1 : c);

	return 0;
}
