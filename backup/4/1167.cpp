#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	int n, i;
	double ans = 0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		ans += 1.0 * 1 / n;

	printf("%lf\n", ans);

	return 0;
}
