#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	node(int s, int t, int v) {
		if (s > t)
			swap(s, t);
		this->s = s;
		this->t = t;
		this->v = v;
	}
	int s, t, v;
} *l[100];

int d[100];

int cmp(const struct node *p0, const struct node *p1)
{
	return p0->s < p1->s;
}

int main(int argc, char *argv[])
{
	int n, j, i = 0;
	int s, t, v;
	int a, b, ans = 0;

	scanf("%d %d %d", &a, &b, &n);
	while (n--) {
		scanf("%d %d %d", &s, &t, &v);
		l[i] = new node(s, t, v);
		if (a <= l[i]->s && l[i]->t <= b)
			i++;
	}
	n = i;

	sort(l, l + n, cmp);
	for (i = 0; i < n; i++) {
		d[i] = l[i]->v;
		for (j = 0; j < i; j++)
			if (l[i]->s >= l[j]->t)
				d[i] = max(d[i], d[j] + l[i]->v);
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans);

	return 0;
}
