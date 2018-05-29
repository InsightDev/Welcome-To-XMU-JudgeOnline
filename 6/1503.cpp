#include <queue>
#include <cstdio>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
char s[1003][1003];

int eval(int n, int m)
{
	int r, c, u, v;
	int a, b, i, j, k;
	int cnt, ans = 0;

	for (r = 0; r < n; r++)
	for (c = 0; c < m; c++)
	{
		if (s[r][c] == '#') {
			for (u = r; u + 1 < n && s[u + 1][c] == '#'; u++)
				;
			for (v = c; v + 1 < m && s[r][v + 1] == '#'; v++)
				;
			queue<int> que;
			que.push(r * m + c);
			s[r][c] = '.';
			cnt = 1;
			while (!que.empty()) {
				i = que.front() / m;
				j = que.front() % m;
				que.pop();
				for (k = 0; k < 4; k++) {
					a = i + dr[k];
					b = j + dc[k];
					if (a >= 0 && a < n && b >= 0 && b < m && s[a][b] == '#') {
						if (a < r || a > u || b < c || b > v)
							return -1;
						que.push(a * m + b);
						s[a][b] = '.';
						cnt += 1;
					}
				}
			}
			if (cnt != (u - r + 1) * (v - c + 1))
				return -1;
			ans += 1;
		}
	}
	return ans;
}

int main(int argc, char* argv[])
{
	int r, c, i;

	scanf("%d %d", &r, &c);
	for (i = 0; i < r; i++)
		scanf("%s", s[i]);
	if ((i = eval(r, c)) == -1)
		printf("Bad placement.\n");
	else
		printf("There are %d ships.\n", i);

	return 0;
}
