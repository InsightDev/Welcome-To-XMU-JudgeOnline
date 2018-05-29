#include <stdio.h>

int eval(int n, int k)
{
	int v;
	int c = 0;
	int r = n;

	while (k-- >= 0) {
		scanf("%d", &v);
		if (v > n)
			return -1;
		if (v > r) {
			r = n;
			c += 1;
		}
		r -= v;
	}
	return c;
}

int main(int argc, char* argv[])
{
	int n, k, c;

	scanf("%d %d", &n, &k);
	if ((c = eval(n, k)) == -1)
		printf("No Solution\n");
	else
		printf("%d\n", c);

	return 0;
}
