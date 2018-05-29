#include <stdio.h>
#include <string.h>

bool c[30][2][30][2];
int l[30];
int r[30];
int n;

bool check(int v)
{	
	for (int u = 0; u < v; u++)
		if (!c[u][r[u]][v][r[v]])
			return false;
	return true;
}

bool search(int k)
{
	if (k == n)
		return true;
	for (int i = 0; i < 2; i++) {
		l[k] = i;
		r[k] = i ^ 1;
		if (check(k) && search(k + 1))
			return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	int m, u, v;
	int i, j;
	char s, t;

	scanf("%d %d", &n, &m);
	while (n || m) {
		memset(c, 1, sizeof(c));
		while (m--) {
			scanf("%d%c %d%c", &u, &s, &v, &t);
			i = s == 'h' ? 0 : 1;
			j = t == 'h' ? 0 : 1;
			c[u][i][v][j] = false;
			c[v][j][u][i] = false;
		}
		l[0] = 1;
		r[0] = 0;
		if (search(1)) {
			for (i = 1; i < n; i++)
				printf("%d%c ", i, l[i] ? 'w' : 'h');
			printf("\n");
		} else {
			printf("bad luck\n");
		}
		scanf("%d %d", &n, &m);
	}

	return 0;
}
