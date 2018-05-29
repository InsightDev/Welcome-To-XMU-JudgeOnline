#include <cstdio>
#include <algorithm>
using namespace std;

int t[1001], d[1001];
int p[1001], s[1001];
int c[1001][1000];

int eval(int n)
{
	int q[1000] = {0};
	int head = 0;
	int tail = 0;
	int ans = 0;
	int i, j, k;

	for (i = 1; i <= n; i++) {
		if (p[i] == 0) {
			d[i] = t[i];
			q[tail++] = i;
		}
	}
	while (head != tail) {
		k = q[head++];
		for (j = 0; j < s[k]; j++) {
			if (d[k] + t[c[k][j]] > d[c[k][j]])
				d[c[k][j]] = d[k] + t[c[k][j]];
			if (--p[c[k][j]] == 0)
				q[tail++] = c[k][j];
		}
	}
	for (i = 1; i <= n; i++) {
		if (p[i] != 0)
			return -1;
		ans = max(ans, d[i]);
	}
	return ans;
}

int main(int argc, char* argv[])
{
	int n, i, j, k;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &t[i]);

	for (i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		for (j = 0; j < p[i]; j++) {
			scanf("%d", &k);
			if (k == i) {
				printf("-1\n");
				return 0;
			}
			c[k][s[k]++] = i;
		}
	}
	printf("%d\n", eval(n));

	return 0;
}
