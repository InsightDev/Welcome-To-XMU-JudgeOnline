#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int n, m, a, i, j;
	char s[10];

	scanf("%d %d", &a, &n);
	for (i = 0; i < n; i++) {
		sprintf(s, "%d", a + i);
		m = (i + 1) / strlen(s);
		for (j = 0; j < m; j++)
			printf("%s", s);
		m = (i + 1) % strlen(s);
		for (j = 0; j < m; j++)
			printf("%c", s[j]);
		printf("\n");
	}

	return 0;
}
