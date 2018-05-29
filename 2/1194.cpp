#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

bool f[1001][1001];

void replace(string &str, const string &src, const string &des)
{
	int len = src.size();	
	int idx = str.find(src);
	while (idx != -1) {
		str.replace(idx, len, des);
		idx = str.find(src, idx + des.size());
	}
}

bool check(char *a, char *b)
{
	int i, j, k;
	int n = strlen(a + 1);
	int m = strlen(b + 1);
	f[0][0] = true;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			f[i][j] = false;
			if (b[j] == '_')
				f[i][j] = f[i - 1][j - 1];
			else if (b[j] == '%')
				for (k = i; !f[i][j] && k >= 0; k--)
					f[i][j] = f[k][j - 1];
			else
				f[i][j] = f[i - 1][j - 1] && (a[i] == b[j]);
		}
	}
	return f[n][m];
}

int main(int argc, char *argv[])
{
	string str;
	char s[1005];
	char t[1005];
	int cas;

	cin >> str;
	replace(str, "%", "0");
	replace(str, "_", "1");
	strcpy(s + 1, str.c_str());

	scanf("%d", &cas);
	while (cas--) {
		cin >> str;
		replace(str, "!%", "0");
		replace(str, "!_", "1");
		strcpy(t + 1, str.c_str());
		printf("%s\n", check(s, t) ? "Yes" : "No");
	}

	return 0;
}
