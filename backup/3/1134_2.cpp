#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char* key = "jszxoier";

int cal_rp(string s)
{
	unsigned k;
	int a, b, c = 0;

	reverse(s.begin(), s.end());

	if (s.find(key, 0) == string::npos)
		return -1;

	k = s.find("cow");
	while (k != string::npos) {
		s.replace(k, 3, "bird");
		k = s.find("cow", k + 4);
	}
	a = count(s.begin(), s.end(), 'r');
	b = count(s.begin(), s.end(), 'p');

	k = s.find("rp");
	while (k != string::npos) {
		c++;
		k = s.find("rp", k + 2);
	}
	return 5 * a + 5 * b + 20 * c;
}

int main(int argc, char* argv[])
{
	int n, t;
	int rp = -1;
	string rs;
	char s[3001];

	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		if ((t = cal_rp(s)) == -1)
			continue;
		if (t > rp || (t == rp && strlen(s) < rs.size())) {
			rp = t;
			rs = s;
		}
	}
	printf("%s\n", rs.c_str());
	printf("%d\n", rp);

	return 0;
}
