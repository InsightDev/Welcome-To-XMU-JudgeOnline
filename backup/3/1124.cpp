#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
using namespace std;

int b[102];
int u[102];
int d[102];

int maxsum(int *b, int m)
{
	int sum = 0;
	int ans = -inf;
	for (int i = 1; i <= m; i++) {
		if (sum > 0)
			sum += b[i];
		else
			sum = b[i];
		ans = max(ans, sum);
	}
	return ans;
}

int destroy(int **a, int n, int m)
{
	int i, j, k;
	int ans = -inf;
	u[0] = -inf;
	for (i = 1; i < n; i++) {
		u[i] = u[i-1];
		for (k = 1; k <= m; k++)
			b[k] = 0;
		for (j = i; j >= 1; j--) {
			for (k = 1; k <= m; k++)
				b[k] += a[j][k];
			u[i] = max(u[i], maxsum(b, m));
		}
	}
	d[n+1] = -inf;
	for (i = n; i > 1; i--) {
		d[i] = d[i+1];
		for (k = 1; k <= m; k++)
			b[k] = 0;
		for (j = i; j <= n; j++) {
			for (k = 1; k <= m; k++)
				b[k] += a[j][k];
			d[i] = max(d[i], maxsum(b, m));
		}
	}
	for (i = 1; i < n; i++)
		ans = max(ans, u[i] + d[i+1]);
	return ans;
}

int main(int argc, char *argv[])
{
	int r, c, i, j;
	int *a[101];
	int *b[101];

	scanf("%d %d", &r, &c);
	for (i = 1; i <= r; i++)
		a[i] = new int[c+1];
	for (i = 1; i <= c; i++)
		b[i] = new int[r+1];
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			scanf("%d", &a[i][j]);
			b[j][i] = a[i][j];
		}
	}
	int d1 = destroy(a, r, c);
	int d2 = destroy(b, c, r);
	printf("%d\n", max(d1, d2));

	return 0;
}
