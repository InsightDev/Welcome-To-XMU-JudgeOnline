#include <cstdio>
#include <algorithm>
using namespace std;

int f[1001][1001];
int a[1001];
int b[1001];

int main(int argc, char* argv[])
{
	int n, m, t, i, j;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (i = 1; i <= m; i++)
			scanf("%d", b + i);

		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);

		for (i = 1; i <= n; i++)
			f[i][0] = f[i-1][0] + a[i];
		for (j = 1; j <= m; j++)
			f[0][j] = f[0][j-1] + b[j];

		for (i = 1; i <= n; i++) {
			for (j = 1; j <= m; j++) {
				int t0 = f[i-1][j] + a[i];
				int t1 = f[i][j-1] + b[j];
				int t2 = f[i-1][j-1] + abs(a[i]-b[j]);
				f[i][j] = min(min(t0, t1), t2);
			}
		}
		printf("%d\n", f[n][m]);
	}

	return 0;
}
