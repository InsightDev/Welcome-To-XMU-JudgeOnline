#include <cstdio>
#include <algorithm>
using namespace std;

struct point {
	double x;
	double y;
};

struct line {
	point s;
	point t;
} l[10000];

inline double cross_product(point &p0, point &p1, point &p2)
{
	double x1 = p1.x - p0.x;
	double y1 = p1.y - p0.y;
	double x2 = p2.x - p0.x;
	double y2 = p2.y - p0.y;
	return x1 * y2 - x2 * y1;
}

inline int online(point &p0, point &p1, point p)
{
	int minx = min(p0.x, p1.x);
	int maxx = max(p0.x, p1.x);
	int miny = min(p0.y, p1.y);
	int maxy = max(p0.y, p1.y);
	return minx <= p.x && p.x <= maxx && miny <= p.y && p.y <= maxy;
}

inline int intersect(point &p0, point &p1, point &p2, point &p3)
{
	double d0 = cross_product(p2, p3, p0);
	double d1 = cross_product(p2, p3, p1);
	double d2 = cross_product(p0, p1, p2);
	double d3 = cross_product(p0, p1, p3);
	if (d0 * d1 < 0 && d2 * d3 < 0)
		return 1;
	if (d0 == 0 && online(p2, p3, p0)) return 1;
	if (d1 == 0 && online(p2, p3, p1)) return 1;
	if (d2 == 0 && online(p0, p1, p2)) return 1;
	if (d3 == 0 && online(p0, p1, p3)) return 1;
	return 0;
}

int cmp(const struct line &l0, const struct line &l1)
{
	return l0.s.x < l1.s.x;
}

int main(int argc, char *argv[])
{
	int n, i, j;
	int ans = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lf %lf %lf %lf", &l[i].s.x, &l[i].s.y, &l[i].t.x, &l[i].t.y);
		if (l[i].s.x > l[i].t.x)
			swap(l[i].s, l[i].t);
	}

	sort(l, l + n, cmp);

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (l[j].s.x > l[i].t.x)
				break;
			if (intersect(l[i].s, l[i].t, l[j].s, l[j].t))
				ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
