#include <stdio.h>

int main(int argc, char* argv[])
{
	int a, b, c;

	scanf("%d", &c);
	a = c / 2;
	b = c - a;
	printf("%d %d\n", a, b);

	return 0;
}
