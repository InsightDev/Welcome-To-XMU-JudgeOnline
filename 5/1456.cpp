#include <cstdio>
#include <vector>
using namespace std;

vector<int> nt[50001];
int a[50001];
int b[50001];

int dfs(int u)
{
	int sum = 0;
	vector<int>::iterator it;

	b[u] = 1;
	for (it = nt[u].begin(); it != nt[u].end(); it++)
		if (!b[*it])
			sum += dfs(*it);
	return a[u] > sum ? a[u] : sum;
}

int main(int argc, char* argv[])
{
	int n, i, u, v;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &u, &v);
		nt[u].push_back(v);
		nt[v].push_back(u);
	}
	printf("%d\n", dfs(0));

	return 0;
}
