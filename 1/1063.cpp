#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int f[4096][12];
int a[12][12];

int tsp(int n)
{
	int m, s, t, i, j;
	int ans = INT_MAX;

	m = 1 << n;
	for (s = 0; s < m; s++)
	for (i = 0; i < n; i++)
		f[s][i] = INT_MAX;

	f[1][0] = 0;
	for (s = 1; s < m; s++)
	for (i = 0; i < n; i++)
	{
		if (f[s][i] == INT_MAX)
			continue;
		for (j = 0; j < n; j++) {
			if (s & (1 << j))
				continue;
			t = s | (1 << j);
			f[t][j] = min(f[t][j], f[s][i] + a[i][j]);
		}
	}
	for (i = 1; i < n; i++)
		ans = min(ans, f[m-1][i] + a[i][0]);
	return ans;
}

int main(int argc, char *argv[])
{
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	if (n == 1)
		printf("0\n");
	else
		printf("%d\n", tsp(n));

	return 0;
}
