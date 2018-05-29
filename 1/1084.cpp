#include <cstdio>
#include <algorithm>
using namespace std;

int a[100001];
int b[100001];

void heapify(int i, int m)
{
	int k = i;
	if (i * 2 + 0 <= m && a[i * 2 + 0] < a[k])
		k = i * 2 + 0;
	if (i * 2 + 1 <= m && a[i * 2 + 1] < a[k])
		k = i * 2 + 1;
	if (k != i) {
		swap(a[i], a[k]);
		heapify(k, m);
	}
}

int main(int argc, char *argv[])
{
	int n, m, k, i;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", a + i);

	for (i = k / 2; i >= 1; i--)
		heapify(i, k);

	for (i = 1; i < k; i++)
		b[i] = -1;
	b[k] = a[1];
	for (i = k + 1; i <= n; i++) {
		if (a[1] < a[i]) {
			a[1] = a[i];
			heapify(1, k);
		}
		b[i] = a[1];
	}

	scanf("%d", &m);
	while (m--) {
		scanf("%d", &i);
		printf("%d %d\n", i, b[i]);
	}

	return 0;
}
