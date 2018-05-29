#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

set<long long> st;
char s[11];
int n;

void cal(char* s, int k, long long a, int i, long long b, int j)
{
	if (j < n) {
		if (i > 0)
			cal(s, k, a / 26, i - 1, b * 26 + a % 26, j + 1);
		if (s[k])
			cal(s, k + 1, a * 26 + s[k] - 'a', i + 1, b, j);
	} else {
		st.insert(b);
	}
}

int main(int argc, char* argv[])
{
	set<long long>::iterator it;

	scanf("%s", s);
	n = strlen(s);
	cal(s, 0, 0, 0, 0, 0);

	for (it = st.begin(); it != st.end(); it++) {
		long long v = *it;
		for (int i = n - 1; i >= 0; i--) {
			s[i] = v % 26 + 'a';
			v /= 26;
		}
		printf("%s\n", s);
	}

	return 0;
}
