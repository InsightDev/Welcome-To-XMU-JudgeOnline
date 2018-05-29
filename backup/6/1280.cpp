#include <cstdio>
#include <iostream>
using namespace std;

int a[100001];

int main(int argc, char *argv[])
{
	int n, i;
	int ans = 0;
	int s = 0;
	int cas;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		s = 0;
		ans = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			s ^= a[i];
		}
		if (s == 0) {
			printf("0\n");
			continue;
		}

		for (i = 1; i <= n; i++) {
			int t = s ^ a[i];
			if (t == 0)
				ans++;
			else if (a[i] > t)
				ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}
