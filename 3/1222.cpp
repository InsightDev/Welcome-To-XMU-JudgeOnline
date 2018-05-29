#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b, c, d;

inline double cal(double x, int o, double y)
{
	switch(o) {
		case 0:
			return x + y;
		case 1:
			return x - y;
		case 2:
			return x * y;
		default:
			return x / y;
	}
}

inline double query(int t, int s)
{
	int i = (s >> 0) & 0x3;
	int j = (s >> 2) & 0x3;
	int k = (s >> 4) & 0x3;
	switch(t) {
		case 0:
			return cal(cal(cal(a, i, b), j, c), k, d);
		case 1:
			return cal(cal(a, i, cal(b, j, c)), k, d);
		case 2:
			return cal(cal(a, i, b), j, cal(c, k, d));
		case 3:
			return cal(a, i, cal(cal(b, j, c), k, d));
		default:
			return cal(a, i, cal(b, j, cal(c, k, d)));
	}
}

int check(int v[])
{
	int t, s;

	sort(v, v + 4);
	do {
		a = v[0]; b = v[1];
		c = v[2]; d = v[3];
		for (t = 0; t < 5; t++)
		for (s = 0; s < 64; s++)
			if (abs(query(t, s) - 24) <= 0.000001)
				return 1;
	} while (next_permutation(v, v + 4));
	return 0;
}

int main(int argc, char *argv[])
{
	int v[4], t, i;

	scanf("%d", &t);
	while (t--) {
		for (i = 0; i < 4; i++)
			scanf("%d", v + i);
		if (check(v))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
