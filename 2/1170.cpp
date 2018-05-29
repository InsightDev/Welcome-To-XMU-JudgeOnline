#include <cstdio>
#include <algorithm>
using namespace std;

int d[100001][17];

int main(int argc, char *argv[])
{
	int n, q, i, j;
	int s, t, l = 2;
	int size;

	scanf("%d %d", &n, &q);
	for (i = 1; i <= n; i++)
		scanf("%d", &d[i][0]);

	for (j = 1; l < n; j++) {
		for (i = 1; i <= n - l + 1; i++)
			d[i][j] = max(d[i][j-1], d[i+l/2][j-1]);
		l <<= 1;
	}

	while (q--) {
		scanf("%d %d", &s, &t);
		size = t - s + 1;
		j = 0;
		l = 1;
		while (l * 2 < size) {
			l <<= 1;
			j++;
		}
		printf("%d\n", max(d[s][j], d[t-l+1][j]));
	}

	return 0;
}
