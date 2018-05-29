#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int d[2001][2];
int a[2001];

int main(int argc, char* argv[]) {
	int n, i, j;
	int ans = 0;

	scanf("%d", &n);
	for (i = n; i >= 1; i--)
		scanf("%d", &a[i]);
	for (i = 1; i <= n; i++)
		d[i][0] = d[i][1] = 1;

	for (i = 1; i <= n; i++) {
		for (j = 1; j < i; j++) {
			if (a[i] > a[j])
				d[i][1] = max(d[i][1], d[j][1] + 1);
			if (a[i] < a[j])
				d[i][0] = max(d[i][0], d[j][0] + 1);
		}
	}

	for (i = 1; i <= n; i++)
		ans = max(ans, d[i][0] + d[i][1] - 1);
	printf("%d\n", ans);

	return 0;
}
