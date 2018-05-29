#include <cstdio>
#include <string>
using namespace std;

char s[1000005];
char t[1000005];

int count(string src, string des)
{
	int ans = 0;
	int len = des.size();
	int idx = src.find(des);
	while (idx != -1) {
		ans++;
		idx = src.find(des, idx + len);
	}
	return ans;
}

int main(int argc, char *argv[])
{
	int cas;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%s", s);
		scanf("%s", t);
		printf("%d\n", count(s, t));
	}

	return 0;
}
