#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
using namespace std;

int d[32768][10];
int a[10][10];
int c[15];
int p[15];
int m, n;

void floyd()
{
	int i, j, k;
	for (k = 0; k < m; k++)
	for (i = 0; i < m; i++)
	for (j = 0; j < m; j++)
		a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main(int argc, char *argv[])
{
	int r, i, j;
	int s, t, maxs;
	int ans = inf;

	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++)
		scanf("%d", c + i);
	for (i = 0; i < m; i++)
	for (j = 0; j < m; j++)
		scanf("%d", &a[i][j]);
	scanf("%d", &r);
	while (r--) {
		scanf("%d %d", &i, &j);
		p[j] |= (1 << i);
	}

	floyd();
	maxs = 1 << n;
	for (s = 0; s < maxs; s++)
	for (i = 0; i < m; i++)
		d[s][i] = inf;
	d[0][0] = 0;

	for (s = 0; s < maxs; s++) {
		for (i = 0; i < m; i++) {
			if (d[s][i] == inf)
				continue;
			for (j = 0; j < n; j++) {
				if (s & (1 << j) || p[j] & ~s)
					continue;
				t = s | (1 << j);
				d[t][c[j]] = min(d[t][c[j]], d[s][i] + a[i][c[j]]);
			}
		}
	}

	for (i = 0; i < m; i++)
		ans = min(ans, d[maxs-1][i]);
	printf("%d\n", ans == inf ? -1 : ans);

	return 0;
}
