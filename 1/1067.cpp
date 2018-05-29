#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;

struct node {
	node(int num, int cap) {
		this->num = num;
		this->cap = cap;
	}
	int num;
	int cap;
};

vector<node> nt[100001];
int c[100001];
int b[100001];
int p[100001];
int n;

void print(int i)
{
	if (i != 0) {
		print(p[i]);
		printf("%d%c", i, i == n ? '\n' : ' ');
	}
}

void vspfa()
{
	int i, u;
	int minc;
	queue<int> que;
	vector<node>::iterator it;

	for (i = 2; i <= n; i++) {
		c[i] = 0;
		b[i] = 0;
	}
	c[1] = INT_MAX;
	b[1] = 1;
	que.push(1);
	while (!que.empty()) {
		u = que.front();
		que.pop();
		b[u] = 0;
		for (it = nt[u].begin(); it != nt[u].end(); it++) {
			minc = min(c[u], it->cap);
			if (c[it->num] < minc) {
				c[it->num] = minc;
				p[it->num] = u;
				if (!b[it->num]) {
					b[it->num] = 1;
					que.push(it->num);
				}
			}
		}
	}
	if (c[n])
		print(n);
	else
		printf("-1\n");
}

int main(int argc, char *argv[])
{
	int m, u, v, z;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &u, &v, &z);
		nt[u].push_back(node(v, z));
		nt[v].push_back(node(u, z));
	}
	vspfa();

	return 0;
}
