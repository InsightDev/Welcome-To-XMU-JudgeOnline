#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b, c, d, k, s, t;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	s = b * b - a * c;
	t = 2 * b - a - c;
	if (t == 0 || s % t) {
		printf("no solution\n");
	} else {
		k = s / t;
		if ((d - k) && (c - k) * (c - k) == (b - k) * (d - k))
			printf("%d\n", k);
		else
			printf("no solution\n");
	}

	return 0;
}
