#include <stdio.h>

int main(int argc, char *argv[])
{
	int a, b;
	int c = 0;
	int s = 1;

	scanf("%d %d", &a, &b);
	while (a || b) {
		c += (a % 10 + b % 10) % 10 * s;
		a /= 10;
		b /= 10;
		s *= 10;
	}
	printf("%d\n", c);

	return 0;
}
