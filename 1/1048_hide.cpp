#include <cstdio>
#include <iostream>
using namespace std;

int a[220101];
int b[220101];
int total;

void search(int h, int w)
{
	int hh, ww, sh, sw, k, i;
	long long tmp, area=0;

	for (i = 0; i < total; i++) {
		if (h >= a[i] && w >= b[i]) {
			k = min(h/a[i], w/b[i]);
			sh = k * a[i];
			sw = k * b[i];
			tmp=(long long)sh*sw;
			if (tmp > area) {
				area = tmp;
				hh = sh;
				ww = sw;
			} else if (tmp == area && sh < hh) {
				hh = sh;
				ww = sw;
			}
		}
		if (h >= b[i] && w >= a[i]) {
			k = min(h/b[i],w/a[i]);
			sh = k * b[i];
			sw = k * a[i];
			tmp=(long long)sh*sw;
			if (tmp > area) {
				area = tmp;
				hh = sh;
				ww = sw;
			} else if (tmp == area && sh < hh) {
				hh = sh;
				ww = sw;
			}
		}
	}
	if (area == 0)
		printf("No solution!\n");
	else
		printf("%d %d\n", hh, ww);
}

int main(int argc, char* argv[])
{
	int n, m, t, cas = 1;
	int h, w, k = 0;

	for (n = 1; n <= 707; n++) {
		t = 500000 / n;
		for (m = n + 1; m <= t; m += 2) {
			a[k] = (m + n) * (m - n);
			if (a[k] > 1000000)
				break;
			b[k++] = 2 * m * n;
		}
	}
	total = k;

	scanf("%d %d", &h, &w);
	while (h || w) {
		printf("Case %d:\n", cas++);
		search(h, w);
		scanf("%d %d", &h, &w);
	}

	return 0;
}
