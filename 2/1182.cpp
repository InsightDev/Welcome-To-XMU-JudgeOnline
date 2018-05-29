#include <stdio.h>

char s[16][17];

int main(int argc, char *argv[])
{
	int n, m, i, j;
	int r0, c0;
	int r1, c1;
	char ch = '1';

	scanf("%d %d", &n, &m);
	r0 = 0;
	r1 = n - 1;
	c0 = 0;
	c1 = m - 1;
	while (r0 <= r1 && c0 <= c1) {
		for (i = r0; i <= r1; i++)
			s[i][c0] = s[i][c1] = ch;
		for (j = c0; j <= c1; j++)
			s[r0][j] = s[r1][j] = ch;
		ch++;
		r0++;
		r1--;
		c0++;
		c1--;
	}
	for (i = 0; i < n; i++)
		printf("%s\n", s[i]);

	return 0;
}
