#include <stdio.h>

struct node {
	int cpx, cpy;
	int cbx, cby;
	int dep, pre;
	char dir;
	void set(int u, int v, int i, int j, int l, int p, char d) {
		cpx = u, cpy = v;
		cbx = i, cby = j;
		dep = l, pre = p;
		dir = d;
	}
} q[1048576];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
char d[] = { 'U', 'R', 'D', 'L' };
bool b[1048576];
char s[30][31];
int n, m;

inline int check(int u, int v)
{
	return u >= 0 && u < n && v >=0 && v < m && s[u][v] != '*';
}

void output(int i)
{
	if (i) {
		output(q[i].pre);
		printf("%c", q[i].dir);
	}
}

void bfs(int cpx, int cpy, int cbx, int cby, int tex, int tey)
{
	int i, j, k, u, v;
	int dep, pre, msk;
	int head = 0;
	int tail = 0;

	b[(cpx << 15) | (cpy << 10) | (cbx << 5) | cby] = true;
	q[tail++].set(cpx, cpy, cbx, cby, 0, -1, 0);
	while (head != tail) {
		cpx = q[head].cpx;
		cpy = q[head].cpy;
		cbx = q[head].cbx;
		cby = q[head].cby;		
		if (cbx == tex && cby == tey) {
			printf("%d\n", q[head].dep);
			output(head);
			printf("\n");
			return;
		}
		dep = q[head].dep + 1;
		pre = head++;
		for (k = 0; k < 4; k++) {
			u = cpx + dr[k];
			v = cpy + dc[k];
			if (check(u, v)) {
				if (u == cbx && v == cby) {
					i = u + dr[k];
					j = v + dc[k];
					if (check(i, j)) {
						msk = (u << 15) | (v << 10) | (i << 5) | j;
						if (!b[msk]) {
							b[msk] = true;
							q[tail++].set(u, v, i, j, dep, pre, d[k]);
						}
					}
				} else {
					msk = (u << 15) | (v << 10) | (cbx << 5) | cby;
					if (!b[msk]) {
						b[msk] = true;
						q[tail++].set(u, v, cbx, cby, dep, pre, d[k]);
					}
				}
			}
		}
	}
	printf("-1\n");
}

int main(int argc, char* argv[])
{
	int i, j;
	int p[2], b[2], e[2];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (j = 0; j < m; j++) {
			if (s[i][j] == 'P')
				p[0] = i, p[1] = j, s[i][j] = '.';
			else if (s[i][j] == 'B')
				b[0] = i, b[1] = j, s[i][j] = '.';
			else if (s[i][j] == 'E')
				e[0] = i, e[1] = j, s[i][j] = '.';
		}
	}
	bfs(p[0], p[1], b[0], b[1], e[0], e[1]);

	return 0;
}
