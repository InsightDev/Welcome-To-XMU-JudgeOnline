#include <cstdio>
#include <cstring>

char t[11];
char s[11];

int eval(int i, int j, int n)
{
	if (n == 0)
		return 1;
	if (s[i] == t[j])
		return eval(i + 1, j + 1, n - 1);

	int x, y;
	for (x = 1; x < n; x++)
		if (s[i + x] == t[j])
			break;
	for (y = 1; y < n; y++)
		if (t[j + y] == s[i])
			break;

	if (x == n || y == n || x + y != n)
		return 0;
	if (!eval(i, j + y, x))
		return 0;
	if (!eval(i + x, j, y))
		return 0;
	return 1;
}

int main(int argc, char* argv[])
{
	int n, l;

	scanf("%d", &n);
	while (n) {
		scanf("%s", t);
		l = strlen(t);
		while (n--) {
			scanf("%s", s);
			if (eval(0, 0, l))
				printf("YES\n");
			else
				printf("NO\n");
		}
		scanf("%d", &n);
	}

	return 0;
}
