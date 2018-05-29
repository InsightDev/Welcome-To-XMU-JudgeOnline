#include <cstdio>
#include <queue>
#define inf 0xffff
using namespace std;

struct point {
	point() {}
	point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x;
	int y;
} p[301];

int x[] = {-1, 0, 1, 0};
int y[] = {0, 1, 0, -1};
int a[102][102];
int d[102][102];
int z[301][301];
int w[301];
int v[301];
int r, c;
int n = -1;

int prim()
{
	int i, j, s, t;
	int len = 0;
	for (i = 0; i <= n; i++)
		w[i] = z[0][i];
	for (i = 1; i <= n; i++) {
		s = inf;
		t = 0;
		for (j = 1; j <= n; j++) {
			if (!v[j] && w[j] < s) {
				s = w[j];
				t = j;
			}
		}
		len += s;
		v[t] = 1;
		for (j = 1; j <= n; j++)
			if (!v[j] && w[j] > z[t][j])
				w[j] = z[t][j];
	}
	return len;
}

void bfs(int u, int v)
{
	int i, j, k;
	queue<point> que;
	for (i = 1; i <= r; i++)
	for (j = 1; j <= c; j++)
		d[i][j] = a[i][j] == 3 ? inf : -1;
	d[u][v] = 0;
	que.push(point(u, v));
	while (!que.empty()) {
		point p = que.front();
		que.pop();
		u = p.x;
		v = p.y;
		for (k = 0; k < 4; k++) {
			i = u + x[k];
			j = v + y[k];
			if (d[i][j] == -1) {
				d[i][j] = d[u][v] + 1;
				que.push(point(i, j));
			}
		}
	}
}

int process()
{
	int i, j;
	for (i = 1; i <= r; i++)
		d[i][0] = d[i][c+1] = inf;
	for (j = 1; j <= c; j++)
		d[0][j] = d[r+1][j] = inf;
	for (i = 0; i <= n; i++) {
		bfs(p[i].x, p[i].y);
		for (j = 0; j <= n; j++) {
			if (d[p[j].x][p[j].y] == -1)
				return -1;
			z[i][j] = d[p[j].x][p[j].y];
		}
	}
	return prim();
}

int main(int argc, char *argv[])
{
	int i, j;

	scanf("%d %d", &r, &c);
	for (i = 1; i <= r; i++) {
		for (j = 1; j <= c; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1 || a[i][j] == 2) {
				p[++n].x = i;
				p[n].y = j;
			}
		}
	}

	int ans = process();
	if (ans == -1)
		printf("Can't Achieve!\n");
	else
		printf("%d\n", ans);

	return 0;
}
