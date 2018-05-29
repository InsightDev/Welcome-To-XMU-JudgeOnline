#include <cstdio>

double smeech()
{
	double p, x, y;
	char ch;

	scanf(" %c", &ch);
	if (ch == '(') {
		scanf("%lf", &p);
		x = smeech();
		y = smeech();
		getchar();
		return p * (x + y) + (1 - p) * (x - y);
	} else {
		ungetc(ch, stdin);
		scanf("%lf", &p);
		return p;
	}
}

int main(int argc, char *argv[])
{
	char s, t;

	scanf(" %c%c", &s, &t);
	while (s != '(' || t != ')') {
		ungetc(t, stdin);
		ungetc(s, stdin);
		printf("%.2f\n", smeech());
		scanf(" %c%c", &s, &t);
	}

	return 0;
}
