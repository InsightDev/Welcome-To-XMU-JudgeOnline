#include <vector>
#include <cstdio>
#include <climits>
using namespace std;

vector<int> nt[40001];

int dfs(int u)
{
	vector<int>::iterator it;
	unsigned minv = INT_MAX;
	unsigned maxv = 0;
	unsigned temp;

	if (nt[u].size() == 0)
		return 0;

	for (it = nt[u].begin(); it != nt[u].end(); it++) {
		temp =  dfs(*it);
		if (temp > maxv)
			maxv = temp;
		if (temp < minv)
			minv = temp;
	}
	if (maxv + 2 > minv + nt[u].size() + 1)
		return maxv + 2;
	else
		return minv + nt[u].size() + 1;
}

int main(int argc, char* argv[])
{
	int n, i, j, k;

	scanf("%d", &n);
	for (k = 1; k < n; k++) {
		scanf("%d %d", &i, &j);
		nt[i].push_back(j);
	}
	printf("%d\n", dfs(1));

	return 0;
}
