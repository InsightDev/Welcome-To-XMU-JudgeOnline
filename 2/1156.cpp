#include <stdio.h>

int a[10001];
int l[10001];
int r[10002];

int main(int argc, char* argv[])
{
	int n, k, i;
	int ans = 0;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	l[0] = 1;
	for (i = 1; i <= n; i++)
		l[i] = l[i-1] * a[i] % 9973;

	r[n+1] = 1;
	for (i = n; i >= 1; i--)
		r[i] = r[i+1] * a[i] % 9973;

	for (i = 1; i <= n - k; i++) {
		ans += l[i-1] * r[i+k+1];
		ans %= 9973;
	}
	printf("%d\n", ans);

	return 0;
}
