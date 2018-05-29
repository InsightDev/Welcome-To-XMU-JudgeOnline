#include <stdio.h>

int a[500000];
int b[500000];

long long merge(int l, int m, int r)
{
	int k = l;
	int i = l;
	int j = m + 1;
	long long cnt = 0;

	while (i <= m && j <= r) {
		if (a[i] > a[j]) {
			cnt += (m - i + 1);
			b[k++] = a[j++];
		} else {
			b[k++] = a[i++];
		}
	}
	while (i <= m)
		b[k++] = a[i++];
	while (j <= r)
		b[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = b[i];
	return cnt;
}

long long count(int l, int r)
{
	if (l >= r)
		return 0;
	long long x, y, z;
	int m = (l + r) >> 1;
	x = count(l, m);
	y = count(m + 1, r);
	z = merge(l, m, r);
	return x + y + z;
}

int main(int argc, char* argv[])
{
	int n, i;

	scanf("%d", &n);
	while (n != 0) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("%lld\n", count(0, n - 1));
		scanf("%d", &n);
	}

	return 0;
}
