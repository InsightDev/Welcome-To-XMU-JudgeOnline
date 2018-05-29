#include <stdio.h>

long long c[19];

int cal(long long x, long long y)
{
	if (x == 0)
		return 0;

	int i, r;
	long long v = 1ll;
	for (i = 1; i <= 18; i++) {
		v *= 10;
		c[i] = (v - 1) / x;
	}
	for (i = 18; i >= 2; i--) {
		c[i] -= c[i-1];
	}

	v = 0ll;
	for (i = 1; i <= 18; i++) {
		if (y < c[i] * i)
			break;
		y -= c[i] * i;
		v += c[i] * x;
	}
	r = y % i;
	v += y / i * x;
	if (r == 0)
		return v % 10;
	v += x;
	i -= r;
	while (i--)
		v /= 10;
	return v % 10;
}

int main(int argc, char *argv[])
{
	int x, y;

	scanf("%d %d", &x, &y);
	printf("%d\n", cal(x, y));

	return 0;
}
