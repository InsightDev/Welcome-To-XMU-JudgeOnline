#include <set>
#include <string>
#include <cstdio>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	char s[11];
	set<string> st;

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		st.insert(s);
	}
	printf("%d\n", st.size());

	return 0;
}
