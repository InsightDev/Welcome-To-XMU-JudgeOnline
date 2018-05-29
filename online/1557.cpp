#include <stdio.h>
#include <string.h>

char a[100][105];
char b[100][105];

int check(int n, char* t)
{
	for (int i = 0; i < n; i++) {
		if (!strstr(a[i], t))
			return 1;
		if (!strstr(b[i], t))
			return 1;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int n, i, j;
	char t[10001];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", a[i]);
		for (j = 0; j < n; j++)
			b[j][i] = a[i][j];
	}
	scanf("%s", t);

	if (check(n, t))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
