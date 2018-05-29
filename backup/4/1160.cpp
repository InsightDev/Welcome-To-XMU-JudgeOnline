#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int i;
	int l;
} a[101];

vector<int> nt[101];
int l[101];
int v[101];

void dfs(int u)
{
	vector<int>::iterator it;
	for (it = nt[u].begin(); it != nt[u].end(); it++) {
		if (v[*it] || l[u] > l[*it])
			continue;
		v[*it] = 1;
		dfs(*it);
	}
}

int cmp(const struct node &n0, const struct node &n1)
{
	return n0.l < n1.l;
}

int main(int argc, char *argv[])
{
	int n, m, i, j;
	int ans = 0;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &l[i]);
		a[i].l = l[i];
		a[i].i = i;
	}
	while (m--) {
		scanf("%d %d", &i, &j);
		nt[i].push_back(j);
		nt[j].push_back(i);
	}

	sort(a + 1, a + n + 1, cmp);
	for (i = 1; i <= n; i++) {
		if (!v[a[i].i]) {
			v[a[i].i] = 1;
			dfs(a[i].i);
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
