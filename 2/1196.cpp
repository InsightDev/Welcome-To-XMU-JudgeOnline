#include <stdio.h>

int main(int argc, char* argv[])
{
	int n, i;
	int a, c, m;
	char s[5001];

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		a = c = m = 0;
		for (i = 0; s[i]; i++) {
			if (s[i] == 'a')
				a += 1;
			else if (s[i] == 'c')
				c += c < a ? 1 : 0;
			else if (s[i] == 'm')
				m += m < c ? 1 : 0;
		}
		printf("%d\n", m);
	}

	return 0;
}