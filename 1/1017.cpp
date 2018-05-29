#include <stdio.h>

int a[1025][1025];
int tile = 1;

void chess(int sr, int sc, int dr, int dc, int m)
{
	if (m == 1)
		return;
	int s = m >> 1;
	int t = tile++;

	if (dr < sr + s && dc < sc + s) {
		chess(sr, sc, dr, dc, s);
	} else {
		a[sr + s - 1][sc + s - 1] = t;
		chess(sr, sc, sr + s - 1, sc + s - 1, s);
	}

	if (dr < sr + s && dc >= sc + s) {
		chess(sr, sc + s, dr, dc, s);
	} else {
		a[sr + s - 1][sc + s] = t;
		chess(sr, sc + s, sr + s - 1, sc + s, s);
	}

	if (dr >= sr + s && dc < sc + s) {
		chess(sr + s, sc, dr, dc, s);
	} else {
		a[sr + s][sc + s - 1] = t;
		chess(sr + s, sc, sr + s, sc + s - 1, s);
	}

	if (dr >= sr + s && dc >= sc + s) {
		chess(sr + s, sc + s, dr, dc, s);
	} else {
		a[sr + s][sc + s] = t;
		chess(sr + s, sc + s, sr + s, sc + s, s);
	}
}

int main(int argc, char *argv[])
{
	int n, i, j;
	int m, r, c;

	scanf("%d", &n);
	scanf("%d %d", &r, &c);
	m = 1 << n;

	chess(1, 1, r, c, m);

	for (i = 1; i <= m; i++)
	for (j = 1; j <= m; j++)
		printf("%d%c", a[i][j], j == m ? '\n' : ' ');

	return 0;
}
