#include <stdio.h>
#include <string.h>

char* add(char *a, char *b)
{
	static char c[1002];
	int x, y, r = 0;
	int n = strlen(a);
	int m = strlen(b);
	int i = n - 1;
	int j = m - 1;
	int k = (n > m ? n : m) + 1;
	c[k] = '\0';
	while (i >= 0 || j >= 0) {
		x = i >= 0 ? a[i--] - '0' : 0;
		y = j >= 0 ? b[j--] - '0' : 0;
		c[--k] = (x + y + r) % 10 + '0';
		r = (x + y + r) / 10;
	}
	if (r != 0)
		c[--k] = r + '0';
	return c + k;
}

int main(int argc, char *argv[])
{
	char a[1002];
	char b[1002];

	scanf("%s %s", a, b);
	printf("%s\n", add(a, b));

	return 0;
}
