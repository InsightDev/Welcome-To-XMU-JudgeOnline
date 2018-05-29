#include <stdio.h>
#include <limits.h>

int a[100][100];
int b[100];
int d[100];
int n;

int dijkstra()
{
	int s, t, i, j;

	d[0] = 0;
	b[0] = 1;
	for (i = 1; i < n; i++) {
		d[i] = a[0][i];
		b[i] = 0;
	}
	for (i = 1; i < n; i++) {
		s = INT_MAX;
		t = 0;
		for (j = 1; j < n; j++) {
			if (!b[j] && d[j] < s) {
				s = d[j];
				t = j;
			}
		}
		b[t] = 1;
		if (t == n - 1)
			return s;
		for (j = 1; j < n; j++)
			if (!b[j] && d[t] + a[t][j] < d[j])
				d[j] = d[t] + a[t][j];
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	printf("%d\n", dijkstra());

	return 0;
}
