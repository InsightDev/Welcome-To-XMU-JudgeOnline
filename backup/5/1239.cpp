#include <cstdio>
#include <cstdlib>
#define inf 0x3fffffff
using namespace std;

struct point {
	int x;
	int y;
	int t;
};

int d[1048576];
int b[1048576];
int a[20][20];
int z[20];

int search(struct point p[], int n, int cx, int cy)
{
	int s, t, i, j;
	int ms = 1 << n;

	for (i = 0; i < n; i++)
	for (j = 0; j <= i; j++)
		a[i][j] = a[j][i] = abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);

	for (s = 0; s < ms; s++)
		d[s] = inf;
	for (i = 0; i < n; i++) {
		int tmp = abs(cx - p[i].x) + abs(cy - p[i].y);
		if (tmp <= p[i].t)
			d[z[i]] = tmp;
	}

	for (s = 0; s < ms; s++) {
		if (d[s] == inf)
			continue;
		for (i = 0; i < n; i++) {
			if (s & z[i]) {
				for (j = 0; j < n; j++) {
					if (s & z[j])
						continue;
					t = s | z[j];
					if (d[s] + a[i][j] <= p[j].t && d[t] > d[s] + a[i][j])
						d[t] = d[s] + a[i][j];
				}
			}
		}
	}
	return d[ms - 1] == inf ? -1 : d[ms - 1];
}

int main(int argc, char *argv[])
{
	int n, i;
	int x, y;
	int ans;
	point p[20];

	for (i = 0; i < 20; i++)
		z[i] = 1 << i;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].t);
		scanf("%d %d", &x, &y);
		ans = search(p, n, x, y);
		if (ans < 0) {
			printf("NO\n");
		} else {
			printf("YES\n");
			printf("%d\n", ans);
		}
	}

	return 0;
}
