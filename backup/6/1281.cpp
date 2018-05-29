#include <cstdio>
#include <iostream>
using namespace std;

int a[100001];
int n;

int count(int des)
{
	int sum = 0;
	int i, c = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] > des)
			return -1;
		if (sum + a[i] > des) {
			c++;
			sum = a[i];
			continue;
		}
		sum += a[i];
	}
	return c + 1;
}

int main(int argc, char *argv[])
{
	int m;
	int i;
	int low = 1;
	int high = 1000000000;
	int ans = high;

	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	while (low <= high)
	{
		int mid = (low + high) / 2;
		int cnt = count(mid);
		if (cnt == -1) {
			low = mid + 1;
		} else if (cnt <= m) {
			ans = min(ans, mid);
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	printf("%d\n", ans);	

	return 0;
}
