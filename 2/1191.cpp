#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
	int n, m, v, c = 0;
	char s[6];
	map<int, int> mp;
	map<int, int>::iterator it;

	scanf("%d %d", &n, &m);

	while (n--) {
		scanf("%d", &v);
		mp[v]++;
	}

	while (m--) {
		scanf("%s", s);
		if (!strcmp(s, "RICH")) {
			it = --mp.end();
			printf("%d\n", it->first + c);
			if (!--it->second)
				mp.erase(it);
		} else if (!strcmp(s, "POOR")) {
			it = mp.begin();
			printf("%d\n", it->first + c);
			if (!--it->second)
				mp.erase(it);
		} else if (!strcmp(s, "ADD")) {
			scanf("%d", &v);
			mp[v - c]++;
		} else {
			scanf("%d", &v);
			c += v;
		}
	}

	return 0;
}
