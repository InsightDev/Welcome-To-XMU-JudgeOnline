#include <cstdio>
using namespace std;

int a[100001];
int c[100001];
int n;

inline int lowbit(int t)
{
	return t & (t ^ (t - 1));
}

int sum(int end)
{
	int sum = 0;
	while (end > 0) {
		sum += c[end];
		end -= lowbit(end);
	}
	return sum;
}

int plus(int pos, int num)
{
	while (pos <= n) {
		c[pos] += num;
		pos += lowbit(pos);
	}
}

int main(int argc, char *argv[])
{
	int m, i, j, s, d;
	char ch;

	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", a + i);
		a[i] %= 2;
		plus(i, a[i]);
	}

	scanf("%d", &m);
	while (m--) {
		scanf(" %c %d %d", &ch, &i, &j);
		if (ch == 'P') {
			s = (a[i] + j) % 2;
			d = s - a[i];
			plus(i, d);
			a[i] = s;
		} else {
			printf("%d\n", j - i + 1 - (sum(j) - sum(i - 1)));
		}
	}

	return 0;
}
