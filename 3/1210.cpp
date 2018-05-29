#include <stdio.h>

int s[100000];
int p[100000];
int w[100000];

int main(int argc, char* argv[])
{
	int n, m, c;
	int i, k;

	scanf("%d", &n);
	while (n--) {
		c = k = 0;
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d", &p[i]);
			while (c < p[i])
				s[k++] = c++;
			w[i] = c - s[--k];
		}
		for (i = 0; i < m; i++)
			printf("%d ", w[i]);
		printf("\n");
	}

	return 0;
}
