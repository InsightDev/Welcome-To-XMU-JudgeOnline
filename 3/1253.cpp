#include <cstdio>
#include <cstring>
using namespace std;

long long a[4];
long long t[4];
int e[4] = { 0, 1, 1, 1 };
int mod = 99999997;

void power(long long num)
{
	if (num == 0) {
		a[0] = a[3] = 1;
		a[1] = a[2] = 0;
		return;
	}
	power(num / 2);
	t[0] = (a[0] * a[0] + a[1] * a[2]) % mod;
	t[1] = (a[0] * a[1] + a[1] * a[3]) % mod;
	t[2] = (a[2] * a[0] + a[3] * a[2]) % mod;
	t[3] = (a[2] * a[1] + a[3] * a[3]) % mod;
	memcpy(a, t, sizeof(t));
	if (num % 2) {
		t[0] = (a[0] * e[0] + a[1] * e[2]) % mod;
		t[1] = (a[0] * e[1] + a[1] * e[3]) % mod;
		t[2] = (a[2] * e[0] + a[3] * e[2]) % mod;
		t[3] = (a[2] * e[1] + a[3] * e[3]) % mod;
		memcpy(a, t, sizeof(t));
	}
}

int main(int argc, char *argv[])
{
	long long num;

	while (scanf("%lld", &num) != EOF) {
		if (num == 1) {
			printf("1\n");
			continue;
		}
		power(num - 1);
		printf("%lld\n", (a[0] + a[1] + a[2] + a[3]) % mod);
	}

	return 0;
}
