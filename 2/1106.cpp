#include <stdio.h>
#include <limits.h>

int d[1048576] = { 0, 0 };
int l[1048576];
int p[1048576];
int q[1048576];
int b[1048576];
int a[20][20];
int z[20];
int n;

void output(int s)
{
	if (s < 0)
		return;
	output(p[s]);
	printf("%d ", l[s]);
}

void tsp()
{
	int s, t, i, j;
	int head = 0;
	int tail = 0;
	int m = 1 << n;

	for (i = 2; i < m; i++)
		d[i] = INT_MAX;
	l[1] = 0;
	p[1] = -1;
	b[1] = 1;
	q[tail++] = 1;

	while (head != tail) {
		s = q[head++];
		b[s] = 0;
		for (j = 1; j < n; j++) {
			if (s & z[j])
				continue;
			if (d[s] == INT_MAX)
				continue;
			t = s | z[j];
			if (d[t] > d[s] + a[l[s]][j]) {
				d[t] = d[s] + a[l[s]][j];
				l[t] = j;
				p[t] = s;
				if (!b[t]) {
					b[t] = 1;
					q[tail++] = t;
				}
			}
		}
	}
	printf("%d\n", d[m-1] + a[l[m-1]][0]);
	output(m - 1);
	printf("\n");
}

int main(int argc, char *argv[])
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	for (i = 0; i < n; i++)
		z[i] = 1 << i;
	tsp();

	return 0;
}
