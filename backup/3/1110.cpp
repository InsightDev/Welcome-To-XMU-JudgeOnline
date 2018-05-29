#include <cstdio>
#include <cstdlib>
using namespace std;

int a[500][3];
int x[101];
int n, m;

int csat()
{
	int i0, i1, i2;
	int v0, v1, v2;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		i0 = abs(a[i][0]);
		i1 = abs(a[i][1]);
		i2 = abs(a[i][2]);
		v0 = a[i][0] > 0 ? x[i0] : !x[i0];
		v1 = a[i][1] > 0 ? x[i1] : !x[i1];
		v2 = a[i][2] > 0 ? x[i2] : !x[i2];
		if (v0 || v1 || v2)
			cnt++;
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	int c, ans;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	for (j = 0; j < 3; j++)
		scanf("%d", &a[i][j]);

	for (i = 1; i <= n; i++)
		x[i] = rand() % 2;
	ans = csat();

	while (true) {
		k = 0;
		for (i = 1; i <= n; i++) {
			x[i] ^= 1;
			c = csat();
			if (c > ans) {
				ans = c;
				k = i;
			}
			x[i] ^= 1;
		}
		if (k)
			x[k] ^= 1;
		else
			break;
	}

	printf("%d\n", ans);
	for (i = 1; i < n; i++)
		printf("%d ", x[i]);
	printf("%d\n", x[n]);

	return 0;
}
