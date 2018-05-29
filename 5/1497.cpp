#include <stdio.h>

int s[100001];

int main(int argc, char* argv[])
{
	int n, m, i;
	int l, r, p;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", s + i);

	scanf("%d", &m);
	while (m--) {
		scanf("%d", &i);
		l = 1;
		r = n;
		while (l <= r) {
			p = (l + r) / 2;
			if (s[p] == i) {
				printf("%d\n", p);
				break;
			}
			if (i < s[p])
				r = p - 1;
			else
				l = p + 1;
		}
	}

	return 0;
}
