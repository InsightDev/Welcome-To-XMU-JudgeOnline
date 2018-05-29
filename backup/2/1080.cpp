#include <cstdio>
#include <algorithm>
using namespace std;

int a[2000000];

int main(int argc, char *argv[])
{
	int n, i, k;
	int b[2];
	
	scanf("%d", &n);
	n = 2 * n - 2;
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	sort(a, a + n);

	i = 0;
	k = 0;
	while (k < 2 && i < n)
	{
		if (i == n - 1 || a[i] != a[i+1])
			b[k++] = a[i++];
		else
			i += 2;
	}

	if (k)
		printf("%d %d\n", b[0], b[1]);
	else
		printf("poor\n");
	
	return 0;
}
