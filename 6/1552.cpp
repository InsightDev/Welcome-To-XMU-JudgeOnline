#include <set>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
	int n, m;
	set<unsigned> st;
	unsigned a, b, c, d;

	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		st.insert((a << 24) | (b << 16) | (c << 8) | d);
	}
	while (m--) {
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		if (st.find((a << 24) | (b << 16) | (c << 8) | d) == st.end())
			printf("no\n");
		else
			printf("yes\n");
	}

	return 0;
}
