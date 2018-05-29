#include <stdio.h>
#include <string.h>

int a[300][300];
int b[300];
int n, m;

int calculate()
{
	int i, j, k, l;
	int sum, cnt = 0;

	for (i = 0; i < n; i++) {
		memset(b, 0, sizeof(b));
		for (j = i; j < n; j++) {
			l = j - i + 1;
			if (l > m)
				break;
			for (k = 0; k < m; k++)
				b[k] += a[j][k];
			if (l % 2)
				continue;
			sum = 0;
			for (k = 0; k < l - 1; k++)
				sum += b[k];
			for (k = l - 1; k < m; k++) {
				sum += b[k];
				if (sum << 1 == l * l)
					cnt += 1;
				sum -= b[k-l+1];
			}				
		}
	}
	return cnt;
}

int main(int argc, char* argv[])
{
	int i, j;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
		scanf("%d", &a[i][j]);
	printf("%d\n", calculate());

	return 0;
}
