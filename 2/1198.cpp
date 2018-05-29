#include <cstdio>
#include <cstdlib>
using namespace std;

int a[101];
int v[100001];
bool c[100001] = {true};

int main(int argc, char *argv[])
{
	int n, u, s = 0;
	int i, j;
	int ans = 0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= s; j++) {
			u = j + a[i];
			if (u <= s && !c[u] && c[j] && v[j] != i) {
				c[u] = true;
				v[u] = i;
				ans++;
			}
			u = abs(j - a[i]);
			if (!c[u] && c[j] && v[j] != i) {
				c[u] = true;
				v[u] = i;
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
