#include <stdio.h>
#include <string.h>

char s[10000][15];

int main(int argc, char *argv[])
{
	int n, m, cnt;
	int i, k;
	char str[15];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

	scanf("%d", &m);
	while (m--) {
		scanf("%d %s", &k, str);
		cnt = 0;
		for (i = 0; i < k; i++)
			if (strcmp(s[i], str) >= 0)
				cnt++;
		printf("%d\n", cnt);
	}

	return 0;
}
