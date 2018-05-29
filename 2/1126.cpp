#include <cstdio>
#include <algorithm>
using namespace std;

int h[5001];
int l[5001];
int r[5001];

int main(int argc, char* argv[])
{
	int n, i;
	int tmp;
	int sum = 0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", h + i);

	l[1] = h[1];
	for (i = 2; i <= n; i++)
		l[i] = max(l[i-1], h[i]);

	r[n] = h[n];
	for (i = n - 1; i >= 1; i--)
		r[i] = max(r[i+1], h[i]);

	for (i = 2; i < n; i++) {
		tmp = min(l[i-1], r[i+1]);
		if (tmp > h[i])
			sum += (tmp - h[i]);
	}
	printf("%d\n", sum);

	return 0;
}
