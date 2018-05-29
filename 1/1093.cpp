#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f[1001][1001];
char a[1002];
char b[1002];

int main(int argc, char *argv[])
{
	int n, m, i, j, k;

	scanf("%s", a + 1);
	scanf("%s", b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);

	for (i = 1; i <= n; i++)
		f[i][0] = i;
	for (j = 1; j <= m; j++)
		f[0][j] = j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			f[i][j] = f[i-1][j-1] + (a[i] == b[j] ? 0 : 1);
			f[i][j] = min(f[i][j], min(f[i-1][j], f[i][j-1]) + 1);
			if (i >= 2 && a[i-1] == b[j]) {
				for (k = j - 1; k >= 1; k--) {
					if (b[k] == a[i]) {
						f[i][j] = min(f[i][j], f[i-2][k-1] + j - k);
						break;
					}
				}
			}
			if (j >= 2 && b[j-1] == a[i]) {
				for (k = i - 1; k >= 1; k--) {
					if (a[k] == b[j]) {
						f[i][j] = min(f[i][j], f[k-1][j-2] + i - k);
						break;
					}
				}
			}
		}
	}
	printf("%d\n", f[n][m]);

	return 0;
}
