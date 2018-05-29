#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1200][11];

void reverse(int i, int j)
{
	char tmp[11];
	while (i < j) {
		strcpy(tmp, s[i]);
		strcpy(s[i], s[j]);
		strcpy(s[j], tmp);
		i++;
		j--;
	}
}

int main(int argc, char *argv[])
{
	int n, m, i, k;
	char op[9];
	char bk[11];

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%s", s[i]);

	while (n--) {
		scanf("%s", op);
		if (!strcmp(op, "ADD")) {
			scanf("%s", bk);
			strcpy(s[m++], bk);
			continue;
		}
		scanf("%d", &k);
		k = min(k, m);
		if (!strcmp(op, "THROW")) {
			m -= k;
		} else if (!strcmp(op, "BREVERSE")) {
			reverse(0, k - 1);
		} else if (!strcmp(op, "TREVERSE")) {
			reverse(m - k, m - 1);
		} else if (!strcmp(op, "BRT")) {
			reverse(0, m - 1);
			reverse(0, m - k - 1);
		} else {
			reverse(0, m - 1);
			reverse(k, m - 1);
		}
	}

	printf("%d\n", m);
	for (i = 0; i < m; i++)
		printf("%s\n", s[i]);

	return 0;
}
