#include <stdio.h>
#include <stdlib.h>

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	return gcd(m, n % m);
}

int main(int argc, char* argv[])
{
	int x0, y0;
	int x1, y1;
	int dx, dy;

	scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
	if (x0 == x1 && y0 == y1) {
		printf("0\n");
	} else {
		dx = abs(x1 - x0);
		dy = abs(y1 - y0);
		printf("%d\n", gcd(dx, dy) - 1);
	}

	return 0;
}
