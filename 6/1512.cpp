#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[6][4];
char a[4], b[4], c[4];

void search()
{
	int x[6] = { 0, 1, 2, 3, 4, 5 };
	int i;

	do {
		for (i = 0; i < 3; i++) {
			a[i] = s[x[i]][0];
			b[i] = s[x[i]][1];
			c[i] = s[x[i]][2];
		}
		if (!strcmp(a, s[x[3]]) &&
			!strcmp(b, s[x[4]]) &&
			!strcmp(c, s[x[5]])) {
			for (i = 0; i < 3; i++)
				printf("%s\n", s[x[i]]);
			return;
		}
	} while (next_permutation(x, x + 6));
	printf("0\n");
}

int main(int argc, char* argv[])
{
	int i;

	for (i = 0; i < 6; i++)
		scanf("%s", s[i]);
	search();

	return 0;
}
