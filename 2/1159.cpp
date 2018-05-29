#include <cstdio>
#include <algorithm>
using namespace std;

struct crop {
	char name[21];
	int idx, cnt;
	int ftim;
	int ntim;
	int exp;
	double rat;
} c[1005];

int cmp0(const struct crop& c0, const struct crop& c1)
{
	return c0.rat > c1.rat;
}

int cmp1(const struct crop& c0, const struct crop& c1)
{
	return c0.idx < c1.idx;
}

int main(int argc, char *argv[])
{
	int n, m, i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		c[i].idx = i;
		scanf("%s %d %d", c[i].name,
			&c[i].cnt, &c[i].ftim);
		if (c[i].cnt > 1)
			scanf("%d", &c[i].ntim);
		scanf("%d", &c[i].exp);
		c[i].rat = 1.0 * c[i].cnt * c[i].exp /
			(c[i].ftim + (c[i].cnt - 1) * c[i].ntim);
	}
	sort(c, c + n, cmp0);
	sort(c, c + m, cmp1);
	for (i = 0; i < m; i++)
		printf("%s\n", c[i].name);

	return 0;
}
