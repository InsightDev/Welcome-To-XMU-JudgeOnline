#include <cstdio>
#include <vector>
using namespace std;

vector<int> nt[1001];
int s[1001];
int n;

int dfs(int i, int v)
{
	s[i] = v;
	v = v ^ 1;
	vector<int>::iterator it;
	for (it = nt[i].begin(); it != nt[i].end(); it++)
	{
		if (s[*it] > -1 && s[*it] != v)
			return 0;
		if (s[*it] < 0 && !dfs(*it, v))
			return 0;
	}
	return 1;
}

int check()
{
	int i;
	for (i = 1; i <= n; i++)
		if (s[i] < 0 && !dfs(i, 0))
			return 0;
	return 1;
}

int main(int argc, char *argv[])
{
	int cas, m;
	int i, j, k;

	scanf("%d", &cas);
	for (k = 1; k <= cas; k++)
	{
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			s[i] = -1;
			nt[i].clear();
		}
		while (m--)
		{
			scanf("%d %d", &i, &j);
			nt[i].push_back(j);
			nt[j].push_back(i);
		}
		printf("Case %d:\n", k);
		printf("%s\n", check() ? "Yes" : "No");
	}

	return 0;
}
