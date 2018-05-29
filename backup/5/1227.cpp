#include <cstdio>
#include <cstring>
using namespace std;

int a[51][51];
int s[51][51];
int t[51][51];
int n;

void power(int r)
{
	if (r == 0) {
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i][j] = i == j ? 1 : 0;
		return;
	}
	power(r / 2);
	memset(t, 0, sizeof(t));
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++)
		t[i][j] = (t[i][j] + s[i][k] * s[k][j]) % 9973;
	memcpy(s, t, sizeof(t));	
	if (r % 2) {
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
			t[i][j] = (t[i][j] + s[i][k] * a[k][j]) % 9973;
		memcpy(s, t, sizeof(t));
	}
}

int main(int argc, char *argv[])
{
	int m, k, i, j;
	int ans = 0;

	scanf("%d %d %d", &n, &m, &k);
	while (m--) {
		scanf("%d %d", &i, &j);
		a[i][j] = 1;
	}

	power(k - 1);
	
    for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		ans = (ans + s[i][j]) % 9973;
	printf("%d\n", ans);

	return 0;
}
