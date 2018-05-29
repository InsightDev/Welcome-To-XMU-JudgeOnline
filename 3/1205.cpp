#include <stdio.h>

int c[1000] = { 1 };

int main(int argc, char* argv[])
{
	int n, g;
	int v, i;
	int s = 0;

	scanf("%d %d", &n, &g);
	while (n--) {
		scanf("%d", &v);
		for (i = g; i >= v; i--)
			c[i] += c[i-v];
	}

	for (i = 1; i <= g; i++)
		s += c[i];
	printf("%d\n", s);

	return 0;
}
