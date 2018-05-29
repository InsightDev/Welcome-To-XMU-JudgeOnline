#include <stdio.h>
#include <string.h>

int gcd(int n, int m)
{
	if (m == 0)
		return n;
	return gcd(m, n % m);
}

int main(int argc, char *argv[])
{
	int a = 1;
	int b = 1;
	int n, m, c;
	char s[4];

	scanf("%d", &n);
	while (n--) {
		scanf("%d %s", &m, s);
		if (!strcmp(s, "Yes")) {
			if (m == 1) {
				b *= 2;
			} else if (m == 2) {
				a *= 2;
				b *= 5;
			} else {
				b *= 3;
			}
		}
	}
	c = gcd(a, b);
	a /= c;
	b /= c;
	if (a == b)
		printf("0\n");
	else
		printf("%d/%d\n", b - a, b);

	return 0;
}
