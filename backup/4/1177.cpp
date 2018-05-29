#include <cstdio>
using namespace std;

int f[16][16];

int main(int argc, char *argv[])
{
	int n, i, j;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		f[i][1] = 1;
		f[i][i] = 1;
		for (j = 2; j < i; j++)
			f[i][j] = f[i-1][j] + f[i-1][j-1];
	}

	for (i = 1; i <= n; i++)
	for (j = 1; j <= i; j++)
		f[n-i+1][n-j+1] = f[i][j];

	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		printf("%d%c", f[i][j], j == n ? '\n' : ' ');

	return 0;
}
