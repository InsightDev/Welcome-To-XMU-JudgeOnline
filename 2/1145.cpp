#include <stdio.h>

int r[101];
int p[1000000];

int main(int argc, char* argv[])
{
	int n, m, c;
	int i, j, k, s;

	scanf("%d %d %d", &n, &m, &c);
	while (m--) {
		scanf("%d %d", &i, &j);
		r[i] = j;
	}

	for (i = 0; i < n; i++)
		p[i] = 1;

	k = 0;
	while (c--) {
		scanf("%d", &s);
		p[k] += s;
		if (p[k] > 100) {
			p[k] = 100;
			break;
		}
		if (r[p[k]])
			p[k] = r[p[k]];
		if (p[k] == 100)
			break;
		k = (k + 1) % n;
	}

	for (i = 0; i < n; i++)
		printf("Position of player %d is %d.\n", i + 1, p[i]);

	return 0;
}
