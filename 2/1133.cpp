#include <cstdio>
#include <cmath>
#include <algorithm>
#define pi 3.1415926535898
using namespace std;

struct point {
	int x;
	int y;
	int w;
};

inline double dist(struct point p0, struct point p1)
{
	double dx = p1.x - p0.x;
	double dy = p1.y - p0.y;
	return sqrt(dx * dx + dy * dy);
}

inline double dist(struct point p0, double cx, double cy)
{
	double dx = cx - p0.x;
	double dy = cy - p0.y;
	return sqrt(dx * dx + dy * dy);
}

int maxorz(point p[], int n, int r)
{
	int sum, ans = 0;
	int i, j, k;
	double dis, cx, cy;

	for (i = 0; i < n; i++)
		ans = max(ans, p[i].w);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			dis = dist(p[i], p[j]);
			if (i == j || dis > 2 * r)
				continue;
			sum = p[i].w + p[j].w;
			if (dis == 2 * r || dis == 0) {
				cx = (p[i].x + p[j].x) / 2.0;
				cy = (p[i].y + p[j].y) / 2.0;
			} else {
				double cosa = dis / 2 / r;
				double sina = sqrt(1 - cosa * cosa);
				double dx = (p[j].x - p[i].x) * r / dis;
				double dy = (p[j].y - p[i].y) * r / dis;
				cx = p[i].x + dx * cosa - dy * sina;
				cy = p[i].y + dx * sina + dy * cosa;
			}
			for (k = 0; k < n; k++) {
				if (k == i || k == j)
					continue;
				if (dist(p[k], cx, cy) <= r)
					sum += p[k].w;
			}
			ans = max(ans, sum);
		}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int cas;
	int n, r, i;
	point p[50];

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &p[i].x);
			scanf("%d", &p[i].y);
			scanf("%d", &p[i].w);
		}
		scanf("%d", &r);
		printf("%d\n", maxorz(p, n, r));
	}

	return 0;
}
