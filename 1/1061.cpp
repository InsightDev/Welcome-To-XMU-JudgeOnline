#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct sched {
	char name[16];
	char beg[6];
	char end[6];
} s[1000];

int x[1000] = { 1 };

int comp(const struct sched& s0, const struct sched& s1)
{
	return strcmp(s0.end, s1.end) < 0;
}

int main(int argc, char *argv[])
{
	int n, i, j;
	int cnt = 1;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s %s %s", s[i].name,
			s[i].beg, s[i].end);
	sort(s, s + n, comp);

	j = 0;
	for (i = 1; i < n; i++) {
		if (strcmp(s[i].beg, s[j].end) >= 0) {
			x[i] = 1;
			cnt++;
			j = i;
		}
	}

	printf("%d\n", cnt);
	for (i = 0; i < n; i++)
		if (x[i])
			printf("%s ", s[i].name);
	printf("\n");

	return 0;
}
