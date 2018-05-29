#include <stdio.h>
#include <string.h>

bool p[1000001];
int a[78498];
int e[78498];
int m;

void process(int n)
{
	int i, k;
	int t, s;

	for (k = 0; k < m; k++) {
		if (a[k] > n)
			break;
		t = n;
		s = 0;
		while (t >= a[k]) {
			s += t / a[k];
			t /= a[k];
		}
		e[k] = s;
	}
	printf("%d", a[0]);
	if (e[0] > 1)
		printf("^%d", e[0]);
	for (i = 1; i < k; i++) {
		printf("*%d", a[i]);
		if (e[i] > 1)
			printf("^%d", e[i]);
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int n, i, k;
	int c = 1;

	memset(p, 1, sizeof(p));
	for (i = 2; i <= 1000; i++) {
		if (!p[i])
			continue;
		k = i * i;
		while (k <= 1000000) {
			p[k] = 0;
			k += i;
		}
	}
	for (i = 2; i < 1000000; i++)
		if (p[i])
			a[m++] = i;

	while (scanf("%d", &n) && n) {
		printf("Case %d:\n", c++);
		process(n);
	}

	return 0;
}
