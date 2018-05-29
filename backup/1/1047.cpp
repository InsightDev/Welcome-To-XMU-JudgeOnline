#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int n, i;
	int cas = 1;
	int a[100];

	scanf("%d", &n);
	while (n) {
		for (i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		for (i = 1; i < n; i++)
			if (a[i] % a[0])
				break;
		printf("Case %d:\n", cas++);
		printf("%s\n", i == n ? "Yes" : "No");
		scanf("%d", &n);
	}

	return 0;
}
