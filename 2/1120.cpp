#include <cstdio>
#include <algorithm>
using namespace std;

int a[100000];

int main(int argc, char *argv[])
{
	int n, s;
	int i, j, k;

	scanf("%d %d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	sort(a, a + n);

	i = 0;
	j = n - 1;
	while (i < j) {
		s = a[i] + a[j];
		if (s == k)
			break;
		else if (s < k)
			i++;
		else
			j--;
	}
	printf("%s\n", i < j ? "Yes" : "No");

	return 0;
}
