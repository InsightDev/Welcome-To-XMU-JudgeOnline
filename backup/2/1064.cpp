#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
using namespace std;

int a[12], b[12];
int l[4096][12];
int f[4096][12];
int c[4096][12];

int main(int argc, char *argv[])
{
	int n, m, i, j;
	int s, t, beg;
	int ans = inf;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);
	for (i = 0; i < n; i++)
		scanf("%d", b + i);

	m = 1 << n;
	for (s = 0; s < m; s++)
	for (i = 0; i < n; i++)
		c[s][i] = inf;
	
	for (i = 0; i < n; i++) {
		s = 1 << i;
		l[s][i] = a[i];
		f[s][i] = a[i] + b[i];
		c[s][i] = f[s][i];
	}

	for (s = 1; s < m; s++) {
		for (i = 0; i < n; i++) {
			if (c[s][i] == inf)
				continue;
			for (j = 0; j < n; j++) {
				if (s & (1 << j))
					continue;
				t = s | (1 << j);
				beg = max(l[s][i] + a[j], f[s][i]);
				if (c[t][j] > c[s][i] + beg + b[j]) {
					c[t][j] = c[s][i] + beg + b[j];
					l[t][j] = l[s][i] + a[j];
					f[t][j] = beg + b[j];
				}
			}
		}
	}

	for (i = 0; i < n; i++)
		ans = min(ans, c[m - 1][i]);
	printf("%d\n", ans);

	return 0;
}
