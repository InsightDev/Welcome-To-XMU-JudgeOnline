#include <queue>
#include <cstdio>
#include <cctype>
using namespace std;

char s[100005];
int cu[26];
int cl[26];

int main(int argc, char* argv[])
{
	int i, x, y, ans = 0;
	priority_queue<int, vector<int>, greater<int> > que;

	scanf("%s", s);
	for (i = 0; s[i]; i++) {
		if (isupper(s[i]))
			cu[s[i]-'A']++;
		else
			cl[s[i]-'a']++;
	}
	for (i = 0; i < 26; i++) {
		if (cu[i])
			que.push(cu[i]);
		if (cl[i])
			que.push(cl[i]);
	}

	if (que.size() == 1) {
		ans = que.top();
	} else {
		while (que.size() > 1) {
			x = que.top();
			que.pop();
			y = que.top();
			que.pop();
			ans += (x + y);
			que.push(x + y);
		}
	}
	printf("%d\n", ans);

	return 0;
}
