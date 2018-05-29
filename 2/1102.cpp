#include <stdio.h>
#include <string.h>

bool b[1000001] = { 1 };
int c[1000001];

int cal(int* a)
{
	int i, j;
	int m = 0;
	int s = 0;

	memset(b + 1, 0, 1000000);
	for (i = 1; i <= 100; i++) {
		if (!a[i])
			continue;
		m += i * a[i];
		memset(c + 1, 0, m * sizeof(int));
		for (j = 0; j <= m - i; j++) {
			if (b[j] && !b[j+i] && c[j] < a[i]) {
				b[j+i] = 1;
				c[j+i] = c[j] + 1;
				s++;
			}
		}
	}
	return s;
}

int main(int argc, char *argv[])
{
	int n, v;
	int a[101];

	while (scanf("%d", &n) != EOF) {
		memset(a, 0, sizeof(a));
		while (n--) {
			scanf("%d", &v);
			a[v]++;
		}
		printf("%d\n", cal(a));
	}

	return 0;
}
