#include <cstdio>
#include <algorithm>
using namespace std;

int d[1000000];

int main(int argc, char* argv[])
{
	int n, l, i;
	long long s = 0;

	scanf("%d %d", &n, &l);
	for (i = 0; i < n; i++)
		scanf("%d", d + i);
	//sort(d, d + n);

	for (i = 0; i < n; i++)
		s += abs(d[i] - i * l);
	printf("%lld\n", s);

	return 0;
}
