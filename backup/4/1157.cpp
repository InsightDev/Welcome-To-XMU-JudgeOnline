#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool a[100][100];
bool b[100][100];
bool v[100];
int c[100];
int n;

int dfs(int u)
{
	int num = 1;
	v[u] = true;
	for (int i = 1; i <= n; i++)
		if (a[u][i] && !v[i])
			num += dfs(i);
	return num;
}

int main(int argc, char *argv[])
{
	int m, i, j;
	int minc = 0xff;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &i, &j);
		a[i][j] = a[j][i] = true;
		b[i][j] = b[j][i] = true;
		c[i]++;
		c[j]++;
	}

	memset(v + 1, 0, n);
	if (dfs(1) < n) {
		printf("0\n");
		return 0;
	}

	for (i = 1; i <= n; i++) {
		memset(v + 1, 0, n);
		memset(a[i] + 1, 0, n);
		if (dfs(i < n ? i + 1 : 1) < n)
			minc = min(minc, c[i]);
		else
			c[i] = 0xff;
		memcpy(a[i] + 1, b[i] + 1, n);
	}

	if (minc == 0xff) {
		printf("No\n");
	} else {
		printf("%d\n", minc + 1);
		for (i = 1; i <= n; i++)
			if (c[i] == minc)
				printf("%d ", i);
		printf("\n");
	}

	return 0;
}
