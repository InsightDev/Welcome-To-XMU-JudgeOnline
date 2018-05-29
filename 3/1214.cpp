#include <stdio.h>

int a[100000];

int main(int argc, char *argv[])
{
	int n, m, i, p;
	int l = 1;
	int r = 0;
	int ans;
	long long c;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", a + i);
		if (a[i] > r)
			r = a[i];
	}
	while (l <= r) {
		c = 0ll;
		p = (l + r) / 2;
		for (i = 0; i < n; i++)
			c += a[i] / p;
		if (c >= m) {
			ans = p;
			l = p + 1;
		} else {
			r = p - 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}
