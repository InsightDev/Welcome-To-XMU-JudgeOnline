#include <stdio.h>

int p[1001];
int s[1001];
int c[1001][1000];

int eval(int m)
{
	int q[1000];
	int head = 0;
	int tail = 0;
	int i, k, n = 0;

	for (i = 1; i <= m; i++)
		if (p[i] == 0)
			q[tail++] = i;
	while (head != tail) {
		k = q[head++];
		n = n + 1;
		for (i = 0; i < s[k]; i++)
			if (--p[c[k][i]] == 0)
				q[tail++] = c[k][i];
	}
	return n != m;
}

int main(int argc, char* argv[])
{
	int m, i, j, k;

	scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		scanf("%d", &p[i]);
		for (j = 0; j < p[i]; j++) {
			scanf("%d", &k);
			c[k][s[k]++] = i;
		}
	}
	printf("%s\n", eval(m) ? "yes" : "no");

	return 0;
}
