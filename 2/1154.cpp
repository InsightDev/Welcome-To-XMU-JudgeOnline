#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;

int main(int argc, char *argv[])
{
	set<string> set0;
	set<string> set1;
	set<string>::iterator it;
	char s[21];
	int cnt = 0;

	scanf("%s", s);
	while (strcmp(s, "0")) {
		set0.insert(s);
		scanf("%s", s);
	}

	scanf("%s", s);
	while (strcmp(s, "0")) {
		set1.insert(s);
		scanf("%s", s);
	}

	for (it = set0.begin(); it != set0.end(); it++)
		if (set1.find(*it) != set1.end())
			cnt++;
	printf("%d\n", cnt);

	return 0;
}
