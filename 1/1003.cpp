#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int n, i, j, k;
	int a[1000];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[k])
				k = j;
		if (k != i)
			swap(a[k], a[i]);
	}

	printf("%d", a[0]);
	for (i = 1; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}
