#include <stdio.h>

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
char s[1000][1001];
int n, m;

int dfs(int u, int v)
{
	int i, j, k, c = 0;

	if (s[u][v] == '*')
		c += 1;
	s[u][v] = '#';
	for (k = 0; k < 4; k++) {
		i = u + dr[k];
		j = v + dc[k];
		if (i >= 0 && i < n && j >= 0 && j < m && s[i][j] != '#')
			c += dfs(i, j);
	}
	return c;
}

int main(int argc, char* argv[])
{
	int i, j;

	while (scanf("%d %d", &n, &m) == 2) {
		int u = -1;
		int v = -1;
		for (i = 0; i < n; i++) {
			scanf("%s", s[i]);
			if (u != -1)
				continue;
			for (j = 0; j < m; j++) {
				if (s[i][j] == 'X') {
					u = i;
					v = j;
					break;
				}
			}
		}
		printf("%d\n", dfs(u, v));
	}

	return 0;
}
