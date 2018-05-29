#include <cstdio>
#include <algorithm>
using namespace std;

int loowater(int* d, int n, int* k, int m)
{
	int i = 0;
	int j = 0;
	int c = 0;
	sort(d, d + n);
	sort(k, k + m);
	while (true) {
		if (d[i] <= k[j]) {
			c += k[j];
			if (++i == n)
				return c;
			if (++j == m)
				return -1;
		} else {
			if (++j == m)
				return -1;
		}
	}
}

int main(int argc, char *argv[])
{
	int d[20000];
	int k[20000];
	int n, m, i, c;

	scanf("%d %d", &n, &m);
	while (n) {
		for (i = 0; i < n; i++)
			scanf("%d", d + i);
		for (i = 0; i < m; i++)
			scanf("%d", k + i);
		c = loowater(d, n, k, m);
		if (c == -1)
			printf("Loowater is doomed!\n");
		else
			printf("%d\n", c);
		scanf("%d %d", &n, &m);
	}

	return 0;
}
