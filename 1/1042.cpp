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

vector<node> nt[100];
int ans = INT_MAX;
int a[100][100];
int b[100];

void dfs(int u, int r, int l, int d)
{
	vector<node>::iterator it;

	if (d >= 2 && a[u][r] != INT_MAX)
		ans = min(ans, l + a[u][r]);

	for (it = nt[u].begin(); it != nt[u].end(); it++) {
		if (!b[it->num] && l + it->len < ans) {
			b[it->num] = 1;
			dfs(it->num, r, l + it->len, d + 1);
			b[it->num] = 0;
		}
	}
}

int main(int argc, char *argv[])
{
	int n, m, l;
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		if (i != j)
			a[i][j] = INT_MAX;

	while (m--) {
		scanf("%d %d %d", &i, &j, &l);
		nt[i].push_back(node(j, l));
		a[i][j] = l;
	}

	for (i = 0; i < n; i++) {
		b[i] = 1;
		dfs(i, i, 0, 0);
		b[i] = 0;
	}
	if (ans != INT_MAX)
		printf("%d\n", ans);
	else
		printf("-1\n");

	return 0;
}
