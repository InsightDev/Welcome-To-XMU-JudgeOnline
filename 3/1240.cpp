#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(char *s, char *t)
{
	int n = strlen(s);
	int m = strlen(t);
	if (n > m || (n == m && strcmp(s, t) >= 0))
		return atoi(t) - 1;
	return atoi(s);
}

int main(int argc, char *argv[])
{
	char s[1005];
	char t[1005];
	int cas, n, m, i;
	long long num, ans;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%s", s);
		scanf("%s", t);
		n = func(s, t);
		m = atoi(t);
		num = 1 % m;
		ans = num;
		for (i = 1; num && i <= n; i++) {
			num = num * i % m;
			ans = (ans + num) % m;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
