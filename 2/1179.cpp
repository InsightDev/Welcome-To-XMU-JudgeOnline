#include <cstdio>
#include <cctype>
#include <cstring>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

struct fruit {
	char src[21];
	char des[21];
} f[10000];

int cmp(const struct fruit& f0, const struct fruit& f1)
{
	return strcmp(f0.des, f1.des) < 0;
}

void process(char *src, char *des)
{
	for (int i = 0; src[i]; i++)
		des[i] = tolower(src[i]);
	des[strlen(src)] = '\0';
}

int main(int argc, char *argv[])
{
	int n, i;
	set<string> st;

	scanf("%d", &n);
	i = 0;
	while (n--) {
		scanf("%s", f[i].src);
		process(f[i].src, f[i].des);
		if (st.find(f[i].des) == st.end()) {
			st.insert(f[i].des);
			i++;
		}
	}

	n = i;
	sort(f, f + n, cmp);
	for (i = 0; i < n; i++)
		printf("%s\n", f[i].src);

	return 0;
}
