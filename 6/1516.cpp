#include <cstdio>
#include <algorithm>
using namespace std;

int a[500001];

int eval(int n)
{
	int i, s = 0;

	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++) {
		s += a[i];
		if (s == n - i - 1)
			return s;
		else if (s > n - i - 1)
			return n - i;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	int n, i;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", eval(n));

	return 0;
}
