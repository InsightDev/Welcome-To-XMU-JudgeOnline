#include <cstdio>
#include <iostream>
#define inf 0x3fffffff
using namespace std;

int d[65536][16];
int a[16][16];

int main(int argc, char *argv[])
{
	int n, m, s, t;
	int i, j;
	int ans = inf;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);

	m = 1 << n;
	for (s = 0; s < m; s++)
	for (i = 0; i < n; i++)
		d[s][i] = inf;
	for (i = 0; i < n; i++)
		d[1 << i][i] = 0;
	
	for (s = 1; s < m; s++) {
		for (i = 0; i < n; i++) {
			if (d[s][i] == inf)
				continue;
			for (j = 0; j < n; j++) {
				if (s & (1 << j))
					continue;
				t = s | (1 << j);
				d[t][j] = min(d[t][j], d[s][i] + a[i][j]);
			}
		}
	}
	for (i = 0; i < n; i++)
		ans = min(ans, d[m - 1][i]);
	printf("%d\n", ans);

	return 0;
}
