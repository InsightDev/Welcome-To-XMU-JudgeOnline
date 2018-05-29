#include <stdio.h>

int a[5002];

int check(int n)
{
	int i, j, r;

	for (i = 1; i <= n; i++) {
		r = 1;
		for (j = 1; j <= n; j++) {
			if (i != j) {
				r *= a[j];
				r %= a[i];
				if (!r)
					return 1;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	int n, i, cas;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			scanf("%d", a + i);
		if (check(n))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
