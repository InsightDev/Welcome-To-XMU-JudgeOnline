#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int cal_rp(string sn)
{
	unsigned idx;
	int a, b, c = 0;

	reverse(sn.begin(), sn.end());

	if (sn.find("jszxoier", 0) == string::npos)
		return -1;

	idx = sn.find("cow");
	while (idx != string::npos)
	{
		sn.replace(idx, 3, "bird");
		idx = sn.find("cow", idx + 4);
	}

	a = count(sn.begin(), sn.end(), 'r');
	b = count(sn.begin(), sn.end(), 'p');

	idx = sn.find("rp");
	while (idx != string::npos)
	{
		c++;
		idx = sn.find("rp", idx + 2);
	}

	return 5 * a + 5 * b + 20 * c;
}

int main(int argc, char* argv[])
{
	int n, tmp;
	int rp = -1;
	string rs;
	char s[3001];

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);

		if ((tmp = cal_rp(s)) == -1)
			continue;
		if (tmp > rp || (tmp == rp && strlen(s) < rs.size()))
		{
			rp = tmp;
			rs = s;
		}
	}

	printf("%s\n", rs.c_str());
	printf("%d\n", rp);

	return 0;
}
