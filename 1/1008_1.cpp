#include <stdio.h>
#include <ctype.h>

int c[] = { 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712 };

const char* s[] = { "1", "", "", "2413", "13524", "246135",
		"1357246", "15863724", "136824975", "1368a59247",
		"13579b2468a", "1358ac6b2794", "13529cad468b7" };

int main(int argc, char* argv[])
{
	int n, i;

	scanf("%d", &n);
	printf("%d\n", c[n-1]);
	if (c[n-1]) {
		for (i = 0; s[n-1][i]; i++) {
			if (isdigit(s[n-1][i]))
				printf("%d %c\n", i + 1, s[n-1][i]);
			else
				printf("%d %d\n", i + 1, s[n-1][i] - 'a' + 10);
		}
	}

	return 0;
}
