#include <stdio.h>

int a[10001];
int b[10001];

int main(int argc, char *argv[])
{
	int n, i, j, k;
	long long sma, smb;
	long long tmp, ans = 0ll;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (i = 1; i <= n; i++)
		scanf("%d", b + i);

	tmp = 0ll;
	for (k = n - 1; k >= 1; k--) {
		tmp += a[k+1] * b[k+1];
		ans += tmp;
	}
	tmp = 0ll;
	for (j = 2; j <= n; j++) {
		tmp += a[j-1] * b[j-1];
		ans += tmp;
	}

	sma = smb = 0ll;
	for (j = 2; j <= n; j++) {
		sma += a[j - 1];
		smb += b[j - 1];
		ans += sma * b[j] + smb * a[j];
	}
	printf("%lld\n", ans);

	return 0;
}
