#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s[16];
	char t[16];
	int cas = 1;
	int n, i, c;

	scanf("%d", &n);
	while (n) {
		c = 1;
		scanf("%s", t);
		for (i = 1; i < n; i++) {
			scanf("%s", s);
			if (strcmp(s, t)) {
				if (--c == 0) {
					strcpy(t, s);
					c = 1;
				}
			} else {
				++c;
			}
		}
		printf("Case %d:\n", cas++);
		printf("%s\n", t);
		scanf("%d", &n);
	}

	return 0;
}
