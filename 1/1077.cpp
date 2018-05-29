#include <queue>
#include <vector>
#include <cstdio>
#include <climits>
using namespace std;

struct node {
	node(int num, int len) {
		this->num = num;
		this->len = len;
	}
	int num;
	int len;
};

vector<node> nt[100001];
int d[100001];
int b[100001];

int spfa(int n)
{
	int i, u;
	queue<int> que;
	vector<node>::iterator it;

	d[1] = 0;
	b[1] = 1;
	que.push(1);
	for (i = 2; i <= n; i++) {
		d[i] = INT_MAX;
		b[i] = 0;
	}
	while (!que.empty()) {
		u = que.front();
		que.pop();
		b[u] = 0;
		for (it = nt[u].begin(); it != nt[u].end(); it++) {
			if (d[it->num] > d[u] + it->len) {
				d[it->num] = d[u] + it->len;
				if (!b[it->num]) {
					b[it->num] = 1;
					que.push(it->num);
				}
			}
		}
	}
	return d[n] == INT_MAX ? -1 : d[n];
}

int main(int argc, char *argv[])
{
	int n, m;
	int u, v, len;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d %d", &u, &v, &len);
		nt[u].push_back(node(v, len));
		nt[v].push_back(node(u, len));
	}
	printf("%d\n", spfa(n));

	return 0;
}
