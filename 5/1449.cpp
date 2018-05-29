#include <stdio.h>
#include <string.h>

int x[100001];
int c[100001][32];

int main(int argc, char* argv[])
{
	int n, m, s, t;
	int i, j, k, v;
	char w[4];

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		k = i - 1;
		scanf("%d", &v);
		x[i] = x[k] ^ v;
		for (j = 0; j < 32; j++) {
			c[i][j] = c[k][j] + (v & 1);
			v >>= 1;
		}
	}

	while (m--) {
		scanf("%s %d %d", w, &s, &t);
		if (strcmp(w, "or") == 0) {
			v = 0;
			for (j = 31; j >= 0; j--) {
				if (c[t][j] == c[s-1][j])
					v = (v << 1) + 0;
				else
					v = (v << 1) + 1;
			}
			printf("%d\n", v);
		} else if (strcmp(w, "and") == 0) {
			v = 0;
			for (j = 31; j >=0; j--) {
				if (c[t][j] - c[s-1][j] == t - s + 1)
					v = (v << 1) + 1;
				else
					v = (v << 1) + 0;
			}
			printf("%d\n", v);
		} else {
			printf("%d\n", x[t] ^ x[s-1]);
		}
	}

	return 0;
}
