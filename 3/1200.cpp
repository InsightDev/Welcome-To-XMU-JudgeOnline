#include <math.h>
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
	int n, m, a, b;
	int cas, ans;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		ans = 0;
		m = sqrt(n);
		for (a = 1; a <= m; a++) {
			if (n % a)
				continue;
			b = n / a;
			if (gcd(a, b) == 1)
				ans += 2;
		}
		printf("%d\n", ans);
	}

	return 0;
}
