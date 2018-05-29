#include <math.h>
#include <stdio.h>

struct point {
	int x;
	int y;
} p[55];

double cala(struct point& p0, struct point& p1, struct point& p2)
{
	double x1 = p1.x - p0.x;
	double y1 = p1.y - p0.y;
	double x2 = p2.x - p0.x;
	double y2 = p2.y - p0.y;
	return (x1 * y2 - x2 * y1) / 2;
}

int main(int argc, char *argv[])
{
	int n, i;
	double area = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	for (i = 2; i < n; i++)
		area += cala(p[0], p[i-1], p[i]);
	printf("%.1f\n", fabs(area));

	return 0;
}
