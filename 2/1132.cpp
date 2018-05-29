#include <stdio.h>

char s[1001];
char t[101];
int v[1000];

int main(int argc, char *argv[])
{
	int n, m, i, j;
	int ans = -1;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", v + i);
	scanf("%s", s);
	scanf("%d", &m);
	scanf("%s", t);

	for (i = 0; i < n - m + 1; i++) {
		for (j = 0; j < m; j++)
			if (t[j] != s[i+j])
				break;
		if (j < m)
			continue;
		int sum = 0;
		for (j = 0; j < m; j++)
			sum += v[i+j];
		if (sum > ans)
			ans = sum;
	}
	printf("%d\n", ans);

	return 0;
}
