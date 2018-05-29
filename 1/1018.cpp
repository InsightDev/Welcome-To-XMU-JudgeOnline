#include <stdio.h>
#include <string.h>

int a[4];
int t[4];
int b[4] = { 1, 1, 1, 0 };

void fibonacci(int k, int m)
{
	if (k == 0) {
		a[0] = a[3] = 1 % m;
		a[1] = a[2] = 0 % m;
		return;
	}
	fibonacci(k / 2, m);
	t[0] = (a[0] * a[0] + a[1] * a[2]) % m;
	t[1] = (a[0] * a[1] + a[1] * a[3]) % m;
	t[2] = (a[2] * a[0] + a[3] * a[2]) % m;
	t[3] = (a[2] * a[1] + a[3] * a[3]) % m;
	memcpy(a, t, sizeof(t));
	if (k & 1) {
		t[0] = (a[0] * b[0] + a[1] * b[2]) % m;
		t[1] = (a[0] * b[1] + a[1] * b[3]) % m;
		t[2] = (a[2] * b[0] + a[3] * b[2]) % m;
		t[3] = (a[2] * b[1] + a[3] * b[3]) % m;
		memcpy(a, t, sizeof(t));
	}
}

int main(int argc, char *argv[])
{
	int cas, n, m;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &n, &m);
		if (n < 2) {
			printf("%d\n", n % m);
		} else {
			fibonacci(n - 1, m);
			printf("%d\n", a[0]);
		}
	}

	return 0;
}
