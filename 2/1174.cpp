#include <map>
#include <cstdio>
#include <climits>
using namespace std;

char s[50][10];

int main(int argc, char *argv[])
{
	int n, m, d;
	int i, j;
	int maxi;
	int maxs = INT_MIN;
	char c;
	map<char, int> mp;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	
	scanf("%d", &m);
	while (m--) {
		scanf(" %c %d", &c, &d);
		if (mp.find(c) == mp.end() || d > mp[c])
			mp[c] = d;
	}

	for (i = 0; i < n; i++) {
		int sum = 0;
		for (j = 0; s[i][j]; j++) {
			if (mp.find(s[i][j]) != mp.end())
				sum += mp[s[i][j]];
		}
		if (sum > maxs) {
			maxs = sum;
			maxi = i;
		}
	}
	printf("%s\n", s[maxi]);

	return 0;
}
