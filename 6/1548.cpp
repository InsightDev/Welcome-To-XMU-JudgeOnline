#include <list>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
	int k, i;
	char s[1001];
	list<char> lt;
	list<char>::iterator it, rm;

	scanf("%s %d", s, &k);
	for (i = 0; s[i]; i++)
		lt.push_back(s[i]);

	it = lt.begin();
	while (!lt.empty()) {
		for (i = 1; i < k; i++)
			if (++it == lt.end())
				it = lt.begin();
		printf("%c", *it);
		rm = it++;
		if (it == lt.end())
			it = lt.begin();
		lt.erase(rm);
	}
	printf("\n");

	return 0;
}
