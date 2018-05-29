#include <cstdio>
#include <vector>
using namespace std;

struct node {
	node(int num, int val) {
		this->num = num;
		this->val = val;
	};
	int num;
	int val;
};

vector<node> nt[40001];
vector<node> qt[40001];
int d[40001];
int p[40001];
int a[10001];
bool b[40001];
bool v[40001];

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

void tarjan(int u)
{
	b[u] = true;
	vector<node>::iterator it;
	for (it = nt[u].begin(); it != nt[u].end(); it++) {
		if (!b[it->num]) {
			d[it->num] = d[u] + it->val;
			tarjan(it->num);
			p[it->num] = u;
		}
	}
	v[u] = true;
	for (it = qt[u].begin(); it != qt[u].end(); it++) {
		if (!v[it->num] || a[it->val])
			continue;
		a[it->val] = d[u] + d[it->num] - 2 * d[find(it->num)];
	}
}

int main(int argc, char *argv[])
{
	int n, m, i;
	int u, v, len;

	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d %d %d", &u, &v, &len);
		nt[u].push_back(node(v, len));
		nt[v].push_back(node(u, len));
	}

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &u, &v);
		qt[u].push_back(node(v, i));
		qt[v].push_back(node(u, i));
	}

	tarjan(1);
	for (i = 1; i <= m; i++)
		printf("%d\n", a[i]);

	return 0;
}
