#include <cstdio>
#include <algorithm>
using namespace std;

struct job {
	int d;
	int p;
	int t;
};

int f[101][10001];

int cmp(const struct job &j0, const struct job &j1)
{
	return j0.d < j1.d;
}

int sched(struct job a[], int n)
{
	int m, i, j, k;
	sort(a + 1, a + n + 1, cmp);
	m = a[n].d;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			k = min(a[i].d, j);
			if (a[i].t <= k)
				f[i][j] = max(f[i][j], f[i - 1][k - a[i].t] + a[i].p);
		}
	}
	return f[n][m];
}

int main(int argc, char *argv[])
{
	job a[101];
	int n, i;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i].d);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i].p);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i].t);
	printf("%d\n", sched(a, n));

	return 0;
}
