#include <stdio.h>

long long s[10];

int main(int argc, char* argv[])
{
	int n, i;
	long long a;
	long long c = 0;

	scanf("%d", &n);
	while (n--) {
		int t[10] = { 0 };
		scanf("%lld", &a);
		do {
			t[a%10]++;
			a /= 10;
		} while (a != 0);
		for (i = 0; i < 10; i++)
			if (t[i]) {
				s[i]++;
			}
	}
	printf("%lld\n", c);

	return 0;
}
