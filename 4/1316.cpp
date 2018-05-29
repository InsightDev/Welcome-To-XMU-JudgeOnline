#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int w;
	int v;
	double p;
} s[100000];

int comp(const struct node& s0, const struct node& s1)
{
	return s0.p > s1.p;
}

int main(int argc, char* argv[])
{
	int n, m;
	int i, k;
	double c = 0;

	scanf("%d %d", &m, &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &s[i].w, &s[i].v);
		s[i].p = (double)s[i].v / s[i].w;
	}

	sort(s, s + n, comp);
	for (i = 0; m && i < n; i++) {
		k = min(m, s[i].w);
		c += k * s[i].p;
		m -= k;
	}
	printf("%.6f\n", c);

	return 0;
}
