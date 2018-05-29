#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	void set(int i, int t, unsigned s) {
		this->i = i;
		this->t = t;
		this->s = s;
	}
	int i, t;
	unsigned s;
} p[150000];
int x[50000];

bool cmp(const struct node& a, const struct node& b)
{
	return a.s != b.s ? a.s < b.s : a.t < b.t;
}

int main(int argc, char* argv[])
{
	int n, m, i;
	int k = 0;
	int z = 0;
	unsigned a, b, c, d;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		p[k++].set(i, 0, (a << 24) | (b << 16) | (c << 8) | d);
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		p[k++].set(i, 2, (a << 24) | (b << 16) | (c << 8) | d);
	}
	for (i = 0; i < m; i++) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		p[k++].set(i, 1, (a << 24) | (b << 16) | (c << 8) | d);
	}

	sort(p, p + k, cmp);
	for (i = 0; i < k; i++) {
		if (p[i].t == 1)
			x[p[i].i] = z > 0;
		else if (p[i].t == 0)
			z += 1;
		else
			z -= 1;
	}
	for (i = 0; i < m; i++)
		printf("%s\n", x[i] ? "yes" : "no");

	return 0;
}
