#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

#define PI 3.1415926535898

double theta = -PI / 3;

void koch(double x0, double y0, double x4, double y4, int n)
{
	if (n == 0) {
		printf("%.10f %.10f\n", x0, y0);
		return;
	}
	double dx = (x4 - x0) / 3;
	double dy = (y4 - y0) / 3;
	double x1 = x0 + dx;
	double y1 = y0 + dy;
	double x2 = x1 + dx * cos(theta) - dy * sin(theta);
	double y2 = y1 + dx * sin(theta) + dy * cos(theta);
	double x3 = x4 - dx;
	double y3 = y4 - dy;
	koch(x0, y0, x1, y1, n - 1);
	koch(x1, y1, x2, y2, n - 1);
	koch(x2, y2, x3, y3, n - 1);
	koch(x3, y3, x4, y4, n - 1);
}

int main(int argc, char *argv[])
{
	int x0, y0, x1, y1, x2, y2, n;

	scanf("%d %d", &x0, &y0);
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d", &n);

	if ((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0) < 0) {
		swap(x1, x2);
		swap(y1, y2);
	}

	koch(x0, y0, x1, y1, n);
	koch(x1, y1, x2, y2, n);
	koch(x2, y2, x0, y0, n);

	return 0;
}
