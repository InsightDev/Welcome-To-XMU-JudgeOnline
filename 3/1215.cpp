#include <queue>
#include <cstdio>
#include <climits>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int a[201][201];
int b[201][201];
int d[201][201];
int n, m;

int search()
{
	int i, j, k;
	int si, sj;
	int ni, nj;
	queue<int> qr;
	queue<int> qc;

	for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
		d[i][j] = INT_MAX;
	d[1][1] = 0;
	b[1][1] = 1;
	qr.push(1);
	qc.push(1);
	while (!qr.empty()) {
		si = qr.front();
		sj = qc.front();
		qr.pop();
		qc.pop();
		b[si][sj] = 0;
		for (k = 0; k < 4; k++) {
			ni = si + dr[k];
			nj = sj + dc[k];
			if (ni >= 1 && ni <= n && nj >= 1 && nj <= m
					&& d[ni][nj] > d[si][sj] + a[ni][nj]) {
				d[ni][nj] = d[si][sj] + a[ni][nj];
				if (!b[ni][nj]) {
					qr.push(ni);
					qc.push(nj);
					b[ni][nj] = 1;
				}
			}
		}
	}
	return d[n][m];
}

int main(int argc, char *argv[])
{
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	for (j = 1; j <= m; j++)
		scanf("%d", &a[i][j]);
	printf("%d\n", search());

	return 0;
}
