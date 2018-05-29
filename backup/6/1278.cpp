#include <iostream>
#include <cstdio>
using namespace std;

int a[1001];
int x[1001];
int c[1001][1001];

int main(int argc, char *argv[])
{
	int n, m;
	int i, j;
	int ans = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
		a[i] = x[i];
	}

	while (m--) {
		scanf("%d %d", &i, &j);
		c[i][j] = 1;
	}

	for (j = 2; j <= n; j++) {
		for (i = 1; i < j; i++) {
			if (c[i][j]) {
				a[j] = max(a[j], a[i] + x[j]);
			}
		}
	}

	for (i = 1; i <= n; i++)
		ans = max(ans, a[i]);
	printf("%d\n", ans);

	return 0;
}
