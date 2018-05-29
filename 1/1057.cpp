#include <cstdio>
using namespace std;

int a[100], h[100];
int s[100], t[100];
int n, cnt;

int recur(int l, int r)
{
	if (l > r)
		return 0;
	int m, i;
	int mv = -1;
	int mc = 0;
	long long sum = 0;
	m = (l + r) / 2;
	for (i = 0; i < n; i++) {
		a[i] = 0;
		h[i] = 0;
		if (m >= s[i]) {
			a[i] = 1 + (m - s[i]) / t[i];
			h[i] = s[i] + (a[i] - 1) * t[i];
			if (h[i] > mv) {
				mv = h[i];
				mc = 1;
			} else if (h[i] == mv) {
				mc++;
			}
		}
		sum += a[i];
	}
	if (sum < cnt)
		return recur(m + 1, r);
	else if (sum - mc >= cnt)
		return recur(l, m - 1);
	for (i = n - 1; i >= 0; i--) {
		if (h[i] == mv) {
			if (sum == cnt)
				break;
			sum--;
		}
	}
	return i + 1;
}

int main(int argc, char *argv[])
{
	int m, c, i;

	scanf("%d %d %d", &n, &m, &c);
	for (i = 0; i < n; i++)
		scanf("%d %d", &s[i], &t[i]);

	cnt = m - c;
	printf("%d\n", recur(1, 1000000000));

	return 0;
}
