#include <cstdio>
using namespace std;

int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};
int a[201][201];
int n, m;

inline int bound(int u, int v)
{
	if (u >= 1 && u <= n && v >= 1 && v <= m)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	int u, v;
	int dir = 0;

	scanf("%d %d", &n, &m);
	
	i = 1;
	j = 1;
	a[i][j] = 1;
	for (k = 2; k <= n * m; k++) {
		u = i + x[dir];
		v = j + y[dir];
		if (!bound(u, v) || a[u][v] != 0) {
			dir = (dir + 1) % 4;
			u = i + x[dir];
			v = j + y[dir];
		}
		a[u][v] = k;
		i = u;
		j = v;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("%d", a[i][j]);
			printf("%c", j == m ? '\n' : ' ');
		}
	}

	return 0;
}
