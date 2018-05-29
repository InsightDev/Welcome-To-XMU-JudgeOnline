#include <stdio.h>

int check(int n, int k)
{
	int c = 0;

	while (n) {
		if (!(n & 1))
			c = 0;
		else if (++c == k)
			return 1;
		n >>= 1;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int c, n, k;

	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &n, &k);
		if (check(n, k))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
