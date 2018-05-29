#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;

char s[100002];
int d[100001];
int b[100001];
int f[100001];
int x[26], y[26];

int main(int argc, char* argv[])
{
	int n, i;
	queue<int> que;

	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (i = 1; i <= n; i++) {
		d[i] = INT_MAX;
		b[i] = x[s[i]-'A'];
		x[s[i]-'A'] = i;
	}
	for (i = n; i >= 1; i--) {
		f[i] = y[s[i]-'A'];
		y[s[i]-'A'] = i;
	}

	d[1] = 1;
	que.push(1);
	while (!que.empty()) {
		i = que.front();
		que.pop();
		if (i > 1 && d[i] + 1 < d[i-1]) {
			d[i-1] = d[i] + 1;
			que.push(i - 1);
		}
		if (i < n && d[i] + 1 < d[i+1]) {
			d[i+1] = d[i] + 1;
			que.push(i + 1);
		}
		if (b[i] && d[i] + 1 < d[b[i]]) {
			d[b[i]] = d[i] + 1;
			que.push(b[i]);
		}
		if (f[i] && d[i] + 1 < d[f[i]]) {
			d[f[i]] = d[i] + 1;
			que.push(f[i]);
		}
	}
	printf("%d\n", d[n] + 1);

	return 0;
}
