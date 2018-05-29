#include <stdio.h>

int c[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int is_leap(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int search(int y, int m)
{
	if (m != 2)
		return c[m];
	else
		return is_leap(y) ? 29 : 28;
}

int main(int argc, char* argv[])
{
	int n, i;
	int y, m, d;

	scanf("%d", &n);
	while (n--) {
		scanf("%d/%d/%d", &y, &m, &d);
		for (i = 1; i < m; i++)
			d += search(y, i);
		printf("%d\n", d);
	}

	return 0;
}
