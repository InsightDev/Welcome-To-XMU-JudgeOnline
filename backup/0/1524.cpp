#include <cstdio>
#include <cassert>

char s[500001];
char t[500001];
int c[10] = {0};

/*
5 2
20902
*/

int main(int argc, char* argv[])
{
	int n, k, i, j;

	scanf("%d %d %s", &n, &k, s);
	for (i = 0; i < n; i++)
		c[s[i] - '0'] += 1;
	for (i = 0; i < 10 && k; i++) {
		for (j = 0; c[i] && k && j < n; j++) {
			if (s[j] - '0' == i) {
				s[j] = 'x';
				c[i]--;
				k--;
			}
		}
	}

	j = 0;
	for (i = 0; i < n; i++)
		if (s[i] != 'x')
			t[j++] = s[i];
	printf("%s\n", t);

	return 0;
}
