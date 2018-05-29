#include <cstdio>
#include <queue>
using namespace std;

int x[1000];
int q[50000];

int eval(int n, int k)
{
	int m[1000] = {0};
	int b[10000] = {0};
	int i, j, r, s, t;
	int head = 0;
	int tail = 0;

	for (i = 0; i < k; i++) {
		j = x[i];
		m[i] = 1;
		do {
			m[i] *= 10;
			j /= 10;
		} while (j);
		if (x[i]) {
			if ((r = x[i] % n) == 0)
				return 1;
			b[r] = 1;
			q[tail++] = r;
			q[tail++] = 1;
		}
	}
	while (head != tail) {
		r = q[head++];
		s = q[head++];
		for (i = 0; i < k; i++) {
			t = (r * m[i] + x[i]) % n;
			if (!t)
				return s + 1;
			if (!b[t]) {
				b[t] = 1;
				q[tail++] = t;
				q[tail++] = s + 1;
			}
		}
	}
	return -1;
}

int main(int argc, char* argv[])
{
	int n, k, t;
	int i, j, z;

	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &n, &k);
		for (j = 0; j < k; j++)
			scanf("%d", &x[j]);
		printf("Case %d: ", i);
		if ((z = eval(n, k)) == -1)
			printf("Impossible!\n");
		else
			printf("%d\n", z);
	}

	return 0;
}
