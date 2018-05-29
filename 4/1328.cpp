#include <stdio.h>

unsigned a[1000000];
unsigned b[1000000];
long long cnt = 0;

void merge(int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (a[j] < a[i]) {
			b[k++] = a[j++];
			cnt += (m - i + 1);
		} else {
			b[k++] = a[i++];
		}
	}
	while (i <= m)
		b[k++] = a[i++];
	while (j <= r)
		b[k++] = a[j++];

	for (k = l; k <= r; k++)
		a[k] = b[k];
}

void mergecount(int l, int r)
{
	if (l < r) {
		int m = (l + r) >> 1;
		mergecount(l, m);
		mergecount(m + 1, r);
		merge(l, m, r);
	}
}

int main(int argc, char* argv[])
{
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%u", a + i);
	mergecount(0, n - 1);
	printf("%lld\n", cnt);

	return 0;
}
