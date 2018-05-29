#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int n, i;
	int a[8];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		a[i] = i + 1;

	do {
		printf("%d", a[0]);
		for (i = 1; i < n; i++)
			printf(" %d", a[i]);
		printf("\n");
	} while (next_permutation(a, a + n));

	return 0;
}
