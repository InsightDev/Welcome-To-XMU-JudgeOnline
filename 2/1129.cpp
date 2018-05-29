#include <stdio.h>
#include <limits.h>

struct point {
	int x;
	int y;
} p[1005];

int c[1005];
int b[1005];

int check(const point& p0, const point& p1, const point& p2)
{
	int x1 = p1.x - p0.x;
	int y1 = p1.y - p0.y;
	int x2 = p2.x - p0.x;
	int y2 = p2.y - p0.y;
	return (x1 * y2 - x2 * y1 == 0)
		&& (x1 * x2 > 0 || y1 * y2 > 0);
}

int main(int argc, char *argv[])
{
	int n, m;
	int i, j, k;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	scanf("%d %d", &p[0].x, &p[0].y);

	m = 0;
	for (i = 1; i <= n; i++) {
		if (!b[i]) {
			b[i] = 1;
			c[++m] = 1;
			for (j = i + 1; j <= n; j++) {
				if (!b[j] && check(p[0], p[i], p[j])) {
					b[j] = 1;
					c[m]++;
				}
			}
		}
	}

	for (i = 1; i <= k; i++)
		b[i] = INT_MAX;
	for (i = 1; i <= m; i++)
	for (j = k; j >= c[i]; j--)
		if (b[j-c[i]] != INT_MAX && b[j-c[i]] + 1 < b[j])
			b[j] = b[j-c[i]] + 1;

	if (b[k] != INT_MAX)
		printf("%d\n", b[k]);
	else
		printf("-1\n");

	return 0;
}
