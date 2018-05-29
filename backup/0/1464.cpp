#include <cstdio>

int d[201][201];

int main(int argc, char* argv[])
{
	int n, m, t;
	int i, j;

	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &d[i][j]);
		while (m--) {
			scanf("%d %d", &i, &j);
			printf("%d\n", d[i][n] + j);
		}
	}

	return 0;
}
