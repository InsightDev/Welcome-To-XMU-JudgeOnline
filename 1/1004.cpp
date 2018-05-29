#include <stdio.h>

int a[1000000];
int b[1000000];

void merge(int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r)
		b[k++] = a[i] < a[j] ? a[i++] : a[j++];
	while (i <= m)
		b[k++] = a[i++];
	while (j <= r)
		b[k++] = a[j++];

	for (k = l; k <= r; k++)
		a[k] = b[k];
}

void mergesort(int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	mergesort(l, m);
	mergesort(m + 1, r);
	merge(l, m, r);
}

int main(int argc, char* argv[])
{
	int n, i;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	mergesort(0, n - 1);

	printf("%d", a[0]);
	for (i = 1; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
