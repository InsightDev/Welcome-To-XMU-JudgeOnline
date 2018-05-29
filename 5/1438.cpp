#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	map<string, int>::iterator it;
	map<string, int>::iterator rm;
	map<string, int> mp;
	string st[3];
	char s[11];
	int n, i;

	scanf("%d", &n);
	while (n--) {
		for (i = 0; i < 3; i++) {
			scanf("%s", s);
			it = mp.find(s);
			if (it == mp.end())
				mp[s] = 1;
			else
				it->second++;
		}
	}

	for (i = 0; i < 3; i++) {
		rm = mp.begin();
		it = mp.begin();
		for (it++; it != mp.end(); it++)
			if ((it->second > rm->second) ||
				(it->second == rm->second &&
					it->first < rm->first))
				rm = it;
		st[i] = rm->first;
		mp.erase(rm);
	}
	sort(st, st + 3);
	printf("%s %s %s\n", st[0].c_str(),
			st[1].c_str(), st[2].c_str());

	return 0;
}
