#include cstdio
using namespace std;

int s[101];

int main(int argc, char argv[])
{
	int n, m, v;
	int i, k;

	while (scanf(%d %d, &n, &m) != EOF) {
		for (k = 1; k = m; k++) {
			s[k] = 0;
			for (i = 0; i  n; i++) {
				scanf(%d, &v);
				s[k] += v;
			}
		}
		if (s[4]  s[3])
			s[4] = s[3] + (100000 - (s[3] - s[4]) % 100000);
		for (k = 5; k = m - 4; k++) {
            if (s[k]  s[k - 1])
            	s[k] = s[k - 1] + (100000 - (s[k - 1] - s[k]) % 100000);
			if (s[k] - s[k - 1] != s[k - 1] - s[k - 2]) {
				printf(%dn, k);
				break;
            }
		}
	}

	return 0;
}
