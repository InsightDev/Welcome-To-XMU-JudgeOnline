#include <stdio.h>
#include <limits.h>
#include <string.h>

int a[100][100];
int b[100];

int cal(int n)
{
	int i, j, k;
	int sum, ans;

	ans = INT_MIN;
	for (i = 0; i < n; i++) {
		memset(b, 0, sizeof(b));
		for (j = i; j < n; j++) {
			sum = 0;
			for (k = 0; k < n; k++) {
				b[k] += a[j][k];
				if (sum > 0)
					sum += b[k];
				else
					sum = b[k];
				if (sum > ans)
					ans = sum;
			}
		}
	}
	return ans;
}

int main(int argc, char* argv[])
{
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		scanf("%d", &a[i][j]);
	printf("%d\n", cal(n));

	return 0;
}
