#include <stdio.h>
#include <string.h>

long long s[100002];

long long expmod(long long a, int m, int n)
{
	if (m == 0)
		return 1;
	long long y = expmod(a, m / 2, n);
	y = y * y % n;
	if (m % 2)
		y = y * a % n;
	return y;
}

int expmod(int a, char m[], int n)
{
	long long ans = 1;
	int l = strlen(m + 1);
	int i = 0;

	s[l] = a % n;
	for (i = l - 1; i >= 1; i--)
		s[i] = expmod(s[i+1], 10, n);
	for (i = l; i >= 1; i--) {
		ans = ans * expmod(s[i], m[i] - '0', n) % n;
		if (ans == 0)
			break;
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int t, a, n;
	char m[10003];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %s %d", &a, m + 1, &n);
		printf("%d\n", expmod(a, m, n));
	}

	return 0;
}
