#include <stdio.h>

int pow3(int n)
{
	long long ans;

	if (n == 0)
		return 1;

	ans = pow3(n >> 1);
	ans *= ans;
	if (n & 1)
		ans *= 3;
	return ans % 199999;
}

int main(int argc, char* argv[])
{
	int n, t, ans;

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = (pow3(n) + 199998) % 199999;
		printf("%d\n", ans);
	}

	return 0;
}
