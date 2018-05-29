#include <stack>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point {
	point(int i, int x, char t) {
		this->i = i;
		this->x = x;
		this->t = t;
	}
	int i;
	int x;
	char t;
} *p[60000];

struct node {
	node(int ci, int cb, int cc) {
		this->ci = ci;
		this->cb = cb;
		this->cc = cc;
	}
	int ci;
	int cb;
	int cc;
};

int z[30000];

int cmp(const point* p0, const point*p1)
{
	return p0->x < p1->x;
}

int main(int argc, char *argv[])
{
	long long ans = 0;
	int n, s, t, i, k = 0;
	int ci, cb, cc;
	char type;
	stack<node> st;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf(" %c %d %d", &type, &s, &t);
		p[k++] = new point(i, s, type);
		p[k++] = new point(i, t, type);
	}
	n <<= 1;
	sort(p, p + n, cmp);

	ci = -1;
	cb = 0;
	cc = 0;
	for (i = 0; i < n; i++) {
		z[p[i]->i]++;
		if (p[i]->t == 'A') {
			if (z[p[i]->i] == 2) {
				ans += cb * cc;
				if (st.empty()) {
					ci = -1;
					cb = 0;
					cc = 0;
				} else {
					node a = st.top();
					st.pop();
					ci = a.ci;
					cb = a.cb + cb;
					cc = a.cc + cc;
				}
			} else {
				if (ci != -1)
					st.push(node(ci, cb, cc));
				ci = p[i]->i;
				cb = 0;
				cc = 0;
			}
		} else if (p[i]->t == 'B') {
			if (z[p[i]->i] == 1)
				cb++;
		} else {
			if (z[p[i]->i] == 1)
				cc++;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
