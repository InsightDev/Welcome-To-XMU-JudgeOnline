#include <set>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
	int n, m, i;
	unsigned a, b, c, d, v;
	set<unsigned> st[32];

	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%u.%u.%u.%u/%d", &a, &b, &c, &d, &i);
		v = (a << 24) | (b << 16) | (c << 8) | d;
		st[i].insert(v >> (32 - i));
	}
	while (m--) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		v = (a << 24) | (b << 16) | (c << 8) | d;
		for (i = 31; i >= 1; i--)
			if (st[i].find(v >> (32 - i)) != st[i].end())
				break;
		printf("%d\n", i);
	}

	return 0;
}
