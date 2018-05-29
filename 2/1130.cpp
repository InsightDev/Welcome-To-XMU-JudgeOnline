#include <stdio.h>

int p[50001];
int r[50001];

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

int main(int argc, char* argv[])
{
	int n, m, u, v;
	char o;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		u = find(u);
		v = find(v);
		if (u != v)
			unio(u, v);
	}

	scanf("%d", &m);
	while (m--) {
		scanf(" %c %d %d", &o, &u, &v);
		u = find(u);
		v = find(v);
		if (o == 'C') {
			if (u != v)
				unio(u, v);
		} else if (u == v) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}

	return 0;
}
