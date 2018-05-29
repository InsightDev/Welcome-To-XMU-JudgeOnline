#include <cstdio>
using namespace std;

struct point {
	int x;
	int y;
} s[20], t[20];

bool a[401][401];
int n, m, p, q, r, c;
int num = 0;

void dfs(int i, int j)
{
	if (a[i][j])
		return;
	num++;
	a[i][j] = true;
	for (int k = 0; k < p; k++) {
		int u = (t[k].x << 1) - i;
		int v = (t[k].y << 1) - j;
		if (u >= 1 && u <= n && v >= 1 && v <= m)
			dfs(u, v);
	}
}

int main(int argc, char *argv[])
{
	int i;

	scanf("%d %d %d %d %d %d", &n, &m, &p, &q, &r, &c);
	for (i = 0; i < p; i++)
		scanf("%d %d", &t[i].x, &t[i].y);
	for (i = 0; i < q; i++)
		scanf("%d %d", &s[i].x, &s[i].y);

	for (i = 0; i < q; i++)
		dfs(s[i].x, s[i].y);

	printf("%lf\n", (double)num / (n * m));
	printf("%s\n", a[r][c] ? "Yes" : "No");

	return 0;
}
