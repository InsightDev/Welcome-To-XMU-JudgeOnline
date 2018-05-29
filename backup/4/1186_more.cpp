#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int d[65536][16];
int v[65536];
int a[16][16];
int z[16];
int n;

int dyna()
{
	int m, s, t, i, j;
	int ans = INT_MAX;

	for (i = 0; i < n; i++)
		z[i] = 1 << i;

	m = 1 << n;
	for (s = 1; s < m; s++) {
		v[s] = INT_MAX;
		for (i = 0; i < n; i++)
			d[s][i] = INT_MAX;
	}
	v[1] = 0;
	d[1][0] = 0;
	for (s = 1; s < m; s++) {
		for (i = 0; i < n; i++) {
			if (d[s][i] == INT_MAX)
				continue;
			for (j = 0; j < n; j++) {
				if (s & z[j])
					continue;
				t = s | z[j];
				if (d[t][j] > d[s][i] + a[i][j]) {
					d[t][j] = d[s][i] + a[i][j];
					v[t] = min(v[t], d[t][j] + a[j][0]);
				}
			}
		}
	}
	for (s = 1; s <= m / 2; s++)
		if (v[s] != INT_MAX)
			ans = min(ans, max(v[s], v[(s^(m-1))+1]));
	return ans;
}

int main(int argc, char *argv[])
{
	int i, j, k;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	for (k = 0; k < n; k++)
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	printf("%d\n", dyna());

	return 0;
}
