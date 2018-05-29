#include <set>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	int n, m, i;
	int cnt;
	char s[21];
	set<string> st[100];
	map<string, int> mp;
	set<string>::iterator it;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		while (m--) {
			scanf("%s", s);
			st[i].insert(s);
			mp[s]++;
		}
	}

	for (i = 0; i < n; i++) {
		cnt = 0;
		for (it = st[i].begin(); it != st[i].end(); it++)
			if (mp[*it] == 1)
				cnt++;
		printf("%d\n", cnt);
	}

	return 0;
}
