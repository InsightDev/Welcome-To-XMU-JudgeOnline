#include <map>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
	int n, c;
	char s[31], p[16];
	map<string, string> mp;
	map<string, string>::iterator it;

	scanf("%d", &n);
	while (n--) {
		scanf("%d %s", &c, s);
		if (c == 0) {
			it = mp.find(s);
			if (it != mp.end())
				printf("%s\n", it->second.c_str());
			else
				printf("-1\n");
		} else if (c == 1) {
			it = mp.find(s);
			if (it != mp.end())
				mp.erase(it);
		} else {
			scanf("%s", p);
			mp[s] = p;
		}
	}

	return 0;
}
