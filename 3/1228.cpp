#include <stdio.h>

struct point {
	double x;
	double y;
	double r;
} p[10];

inline bool check(struct point& p0, double cx, double cy)
{
	double dx = cx - p0.x;
	double dy = cy - p0.y;
	return dx * dx + dy * dy <= p0.r * p0.r;
}

int main(int argc, char *argv[])
{
	int n, i;
	int cnt = 0;
	int tol = 0;
	double x, y;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%lf", &p[i].x);
		scanf("%lf", &p[i].y);
		scanf("%lf", &p[i].r);
	}
	for (x = 0; x <= 1.0; x += 0.002)
	for (y = 0; y <= 1.0; y += 0.002)
	{
		for (i = 0; i < n; i++)
			if (check(p[i], x, y))
				break;
		if (i < n)
			cnt++;
		tol++;
	}
	printf("%lf\n", 1.0 * cnt / tol);

	return 0;
}
