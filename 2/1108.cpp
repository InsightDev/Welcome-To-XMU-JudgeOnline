#include <cstdio>
using namespace std;

int x[6000];
int s[600][6000];
int c[600];
int a[600];
int n, m;

int count(int i)
{
	int j, tc = 0;
	for (j = 0; j < c[i]; j++)
		if (!x[s[i][j]])
			tc++;
	return tc;
}

int main(int argc, char *argv[])
{
	int i, j, k = 0;
	int mc, tc, mi;
	int cnt = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &c[i]);
		for (j = 0; j < c[i]; j++)
			scanf("%d", &s[i][j]);
	}

	while (cnt != n) {
		mc = 0;
		for (i = 0; i < m; i++) {
			tc = count(i);
			if (tc > mc) {
				mc = tc;
				mi = i;
			}
		}
		for (j = 0; j < c[mi]; j++)
			x[s[mi][j]] = 1;
		cnt += mc;
		a[k++] = mi;
	}

	printf("%d\n", k);
	printf("%d", a[0]);
	for (i = 1; i < k; i++)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
