#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct point{
	int x;
	int y;
} p[1000000];

int b[1000000];

int comp(const point& p0, const point& p1)
{
	return p0.x != p1.x ? p0.x > p1.x : p0.y > p1.y;
}

int bank(int k, int i)
{
	int l = 1;
	int r = k;
	while (l < r) {
		int m = (l + r) / 2;
		if (b[m] < p[i].y)
			l = m + 1;
		else
			r = m;
	}
	return r;
}

int main(int argc, char* argv[])
{
	int n, i, k;

	while (scanf("%d",&n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d %d", &p[i].x, &p[i].y);
		sort(p, p + n, comp);
		k = 1;
		b[k] = p[0].y;
		for (i = 1; i < n; i++) {
			if (p[i].y > b[k])
				b[++k] = p[i].y;
			else
				b[bank(k, i)] = p[i].y;
		}
		printf("%d\n", k);
	}

	return 0;
}
