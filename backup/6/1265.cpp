#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

#define base(c) (c > '9' ? (c > 'Z' ? 'a' : 'A') : '0')
#define loop(c) (c > '9' ? 26 : 10)

int main(int argc, char *argv[])
{
	int n, r, l, b, i;
	string s;

	cin >> s >> n;
	while (n--) {
		r = 1;
		i = s.size() - 1;
		while (r && i >= 0) {
			b = base(s[i]);
			l = loop(s[i]);
			r = (s[i] - b + 1) / l;
			s[i] = b + (s[i] - b + 1) % l;
			i--;
		}
		if (r) {
			char b = base(s[0]);
			s.insert(s.begin(), s[0] > '9' ? b : b + 1);
		}
		printf("%s\n", s.c_str());
	}

	return 0;
}
