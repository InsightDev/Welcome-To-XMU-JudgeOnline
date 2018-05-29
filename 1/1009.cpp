#include <math.h>
#include <stdio.h>

int is_prime(int num)
{
	if (num < 2)
		return 0;

	int m = sqrt(num);
	for (int i = 2; i <= m; i++)
		if (num % i == 0)
			return 0;
	return 1;
}

void search(int k, int n, int num)
{
	if (k == n) {
		printf("%d\n", num);
		return;
	}
	for (int i = 1; i < 10; i++) {
		int tmp = num * 10 + i;
		if (is_prime(tmp))
			search(k + 1, n, tmp);
	}
}

int main(int argc, char* argv[])
{
	int n;

	scanf("%d", &n);
	search(0, n, 0);

	return 0;
}
