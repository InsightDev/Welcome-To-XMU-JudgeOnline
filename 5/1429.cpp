#include <stdio.h>

int cal(int n, int x)
{
	int l, r, m;
	int z, s;

	if (x == 1)
		return 1;

	l = 1;
	r = n;
	while (l <= r) {
		m = (l + r) / 2;
		s = m;
		z = m;
		while (z >= x && s < n) {
			s = z / x + s;
			z = z / x + z % x;
		}
		if (s < n)
			l = m + 1;
		else
			r = m - 1;
	}
	return l;
}

int main(int argc, char* argv[])
{
	int n, x;

	scanf("%d %d", &n, &x);
	printf("%d\n", cal(n, x));

	return 0;
}
