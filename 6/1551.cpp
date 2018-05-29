#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int n, i, s = 0;
	int e[1000];
	int a[1000];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", e + i);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	sort(e, e + n);
	sort(a, a + n);
	for (i = 0; i < n; i++)
		s += abs(e[i] - a[i]);
	printf("%d\n", s);
	
	return 0;
}
