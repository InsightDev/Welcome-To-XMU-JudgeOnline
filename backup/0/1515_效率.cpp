#include <cstdio>

int t[100000];

int main(int argc, char* argv[])
{
	int n, m, i, k = 0;
	long long l = 1;
	long long r, z, s;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		if (t[i] > k)
			k = t[i];
	}

	r = (long long)k * m;
	while (l <= r) {
		s = 0;
		z = (l + r) / 2;
		for (i = 0; i < n; i++)
			s += z / t[i];
		if (s < m)
			l = z + 1;
		else
			r = z - 1;
	}
	printf("%lld\n", l);

	return 0;
}
