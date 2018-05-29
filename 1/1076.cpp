#include <cstdio>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, l;
} e[200000];

int p[100001];
int r[100001];
int n, m;

int cmp(const struct edge& e0, const struct edge& e1)
{
	return e0.l < e1.l;
}

int find(int u)
{
	int y = u;
	int z = u;
	int w;
	while (p[y] != 0)
		y = p[y];
	while (p[z] != 0) {
		w = p[z];
		p[z] = y;
		z = w;
	}
	return y;
}

void unio(int u, int v)
{
	if (r[u] >= r[v]) {
		p[v] = u;
		if (r[u] == r[v])
			r[u]++;
	} else {
		p[u] = v;
	}
}

int kruskal()
{
	int i, u, v;
	int cst = 0;
	int cnt = 0;

	sort(e, e + m, cmp);
	for (i = 0; i < m; i++) {
		u = find(e[i].u);
		v = find(e[i].v);
		if (u != v) {
			cst += e[i].l;
			if (++cnt == n - 1)
				return cst;
			unio(u, v);
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int i;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].l);
	printf("%d\n", kruskal());

	return 0;
}
