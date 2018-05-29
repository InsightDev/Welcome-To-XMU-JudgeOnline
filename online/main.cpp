#include <stdio.h>

// x^2+5x^3-2x
// x^2+5x^3-2x+x+5
// -15129x^122+6x

int c[1000];

void process(char* s, int z)
{
	int a, b;
	char x;

	if (sscanf(s, "%dx^%d", &a, &b) == 2)
		c[b] += z * a;
	else if (sscanf(s, "%d%[x]", &a, &x) == 2)
		c[1] += z * a;
	else if (sscanf(s, "x^%d", &b) == 1)
		c[b] += z * 1;
	else if (sscanf(s, "%d", &a) == 1)
		c[0] += z * a;
	else
		c[1] += z * 1;
}

int main(int argc, char* argv[])
{
	char s[64];
	char z = '+';

	while (scanf("%[^+/-\n]", s)) {
		if (z == '+')
			process(s, 1);
		else
			process(s, -1);
		z = getchar();
		if (z != '+' && z != '-')
			break;
	}

	int beg = 1;
	for (int i = 999; i >= 1; i--) {
		if (!c[i])
			continue;

		int a = i * c[i];
		int b = i - 1;
	
		if (a > 0 && !beg)
			printf("+");
		beg = 0;

		printf("%d", a);
		if (b > 1)
			printf("x^%d", b);
		else if (b == 1)
			printf("x");
	}
	printf("\n");

	return 0;
}
