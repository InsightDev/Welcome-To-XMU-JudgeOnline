#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
#define INT_MAX 0xfffffff

struct node {
	node(int num, int len) {
		this->num = num;
		this->len = len;
	}
	int num;
	int len;
};

vector<node> nt[301];
int w[301][301];
int z[301];
int x[301];
int n;

int spfa(int r, int u, int v)
{
	int i;
	queue<int> que;
	vector<node>::iterator it;

	for (i = 1; i <= n; i++) {
		x[i] = 0;
		z[i] = INT_MAX;
	}
	
	z[u] = 0;
	x[u] = 1;
	que.push(u);
	while (!que.empty()) {
		u = que.front();
		que.pop();
		x[u] = 0;
		for (it = nt[u].begin(); it != nt[u].end(); it++) {
			if (z[it->num] > z[u] + it->len) {
				z[it->num] = z[u] + it->len;
				if (!x[it->num]) {
					x[it->num] = 1;
					que.push(it->num);
				}
			}
		}
	}
	return w[r][v];
}

int main(int argc, char* argv[])
{
	char s[6];
	int q, m, l;
	int i, j, u, v;
	unsigned a, b, c, d;
	map<unsigned, int> mp;

	for (i = 1; i <= 300; i++)
	for (j = 1; j <= 300; j++)
		if (i != j)
			w[i][j] = INT_MAX;

	scanf("%d", &q);
	while (q--) {
		scanf("%s", s);
		if (!strcmp(s, "add")) {
			scanf("%u.%u.%u.%u %d", &a, &b, &c, &d, &m);
			mp[(a << 24) | (b << 16) | (c << 8) | d] = ++n;
			while (m--) {
				scanf("%u.%u.%u.%u %d", &a, &b, &c, &d, &l);
				v = mp[(a << 24) | (b << 16) | (c << 8) | d];
				nt[n].push_back(node(v, l));
				nt[v].push_back(node(n, l));
			}
		} else {
			scanf("%u.%u.%u.%u", &a, &b, &c, &d);
			u = mp[(a << 24) | (b << 16) | (c << 8) | d];
			scanf("%u.%u.%u.%u", &a, &b, &c, &d);
			v = mp[(a << 24) | (b << 16) | (c << 8) | d];
			spfa(v, v, u);
			spfa(u, u, v);
			printf("%d\n", w[u][v]);
			//printf("%d\n", z[u][v]);
		}
	}

	return 0;
}
