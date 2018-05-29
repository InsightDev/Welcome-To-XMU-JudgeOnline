#include <stdio.h>

int p[1000];
int r[1000];

int find(int u)
{
	int y = u;
	int z = u;
	int w;
	while (p[y] != -1)
		y = p[y];
	while (p[z] != -1) {
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

int main(int argc, char *argv[])
{
	int n, m, u, v, i;
	int cas, cnt;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			p[i] = -1;
			r[i] = 0;
		}
		cnt = 0;
		for (i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			u = find(u);
			v = find(v);
			if (u != v) {
				unio(u, v);
				cnt++;
			}
		}
		printf("%d\n", m - cnt);
	}

	return 0;
}
