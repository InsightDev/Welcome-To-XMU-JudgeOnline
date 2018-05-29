#include <math.h>
#include <stdio.h>
#include <string.h>

bool p[1048576];
bool c[46341];

int main(int argc, char *argv[])
{
	int cas, cnt;
	unsigned a, b, l, m, i, k;

	memset(c, true, sizeof(c));
	for (i = 2; i <= 215; i++) {
		k = i * i;
		while (k <= 46340) {
			c[k] = false;
			k += i;
		}
	}

	scanf("%d", &cas);
	while (cas--) {
		scanf("%u %u", &a, &b);
		m = sqrt(b);
		l = b - a + 1;
		memset(p, true, l);
		cnt = a == 1 ? l - 1 : l;
		for (i = 2; i <= m; i++) {
			if (!c[i])
				continue;
			k = ceil((double)a / i) * i;
			if (k < i * i)
				k = i * i;
			while (k <= b) {
				if (p[k - a]) {
					p[k - a] = false;
					cnt--;
				}
				k += i;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
