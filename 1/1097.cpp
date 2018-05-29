#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000000];

int partition(int l, int r)
{
	int i = 0;
	int j = l - 1;
	int k = rand() % (r-l+1);
	swap(a[l+k], a[r]);
	for (i = l; i < r; i++)
		if (a[i] < a[r])
			swap(a[++j], a[i]);
	swap(a[++j], a[r]);
	return j;
}

int select(int l, int r, int k)
{
	int m = partition(l, r);
	int c = m - l + 1;
	if (c > k)
		return select(l, m - 1, k);
	else if (c < k)
		return select(m + 1, r, k - c);
	else
		return a[m];
}

int main(int argc, char* argv[])
{
	int n, k, i;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d\n", select(0, --n, k));

	return 0;
}
