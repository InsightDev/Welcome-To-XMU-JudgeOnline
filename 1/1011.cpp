#include <cstdio>
#include <string>
using namespace std;

int p[100001];

int gcd(int n, int m)
{
	if (!m)
		return n;
	return gcd(m, n % m);
}

int main(int argc, char *argv[])
{
	unsigned i;
	int n, m, c;
	string s;

	scanf("%d %d", &n, &m);
	c = gcd(n, m);
	n /= c;
	m /= c;

	c = n / m;
	do {
		char w = c % 10 + '0';
		s.insert(s.begin(), w);
		c /= 10;
	} while (c);
	s.push_back('.');

	c = n % m;
	do {
		p[c] = s.size();
		c *= 10;
		s.push_back(c / m + '0');
		c %= m;
	} while (c && !p[c]);

	if (c) {
		s.insert(s.begin() + p[c], '(');
		s.push_back(')');
	}
	for (i = 0; i < s.size(); i += 76) {
		string sub = s.substr(i, 76);
		printf("%s\n", sub.c_str());
	}

	return 0;
}
