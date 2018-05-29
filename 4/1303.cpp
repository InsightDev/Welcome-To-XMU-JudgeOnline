#include <stdio.h>

int main(int argc, char* argv[])
{
	int t, n, a, b, i;
	char c, s[101];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%s", s);
		c = s[0];
		a = b = 0;
		for (i = 1; s[i]; i++) {
			if (s[i] != c) {
				c == '0' ? a++ : b++;
				c = s[i];
			}
		}
		c == '0' ? a++ : b++;
		printf("%d\n", a < b ? a : b);
	}

	return 0;
}
