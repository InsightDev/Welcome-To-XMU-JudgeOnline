#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[10001];
char* p[10000];

int cmp(const char* p0, const char* p1)
{
	return strcmp(p0, p1) < 0;
}

int len(const char* p0, const char* p1)
{
	int k = 0;
	while (*p0++ == *p1++)
		k++;
	return k;
}

int main(int argc, char *argv[])
{
	int n, i, tmp;
	int ans = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", s + i);
		p[i] = s + i;
	}
	s[n] = '\0';

	sort(p, p + n, cmp);

	for (i = 1; i < n; i++) {
		tmp = len(p[i-1], p[i]);
		if (tmp > ans)
			ans = tmp;
	}
	printf("%d\n", ans);

	return 0;
}
