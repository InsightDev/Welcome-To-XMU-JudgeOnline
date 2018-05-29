#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int n, v, i;
	double sum = 0;
	double ans = 0;
	double tmp;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &v);
		sum = sum + v;
		tmp = sum / i;
		if (tmp > ans)
			ans = tmp;
	}
	printf("%d\n", (int)ceil(ans));

	return 0;
}
