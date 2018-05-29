#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int a[14], s[14], b[14];
int cnt = 0;

int check(int k)
{
	for (int i = 1; i < k; i++)
		if (abs(a[k] - a[i]) == k - i)
			return 0;
	return 1;
}

void recur(int k, int n)
{
	if (k > n) {
		cnt++;
		if (cnt == 1)
			memcpy(s + 1, a + 1, n * sizeof(int));
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i])
			continue;
		b[i] = 1;
		a[k] = i;
		if (check(k))
			recur(k + 1, n);
		b[i] = 0;
	}
}

int main(int argc, char *argv[])
{
	int n, i;

	scanf("%d", &n);
	recur(1, n);

	printf("%d\n", cnt);
	if (cnt != 0)
		for (i = 1; i <= n; i++)
			printf("%d %d\n", i, s[i]);

	return 0;
}
