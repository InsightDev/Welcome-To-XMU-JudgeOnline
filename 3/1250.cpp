#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
	int i, w, v;
} a[100];

int main(int argc, char *argv[])
{
	int n, s, i, j, k;
	int cw, cv, tim = 200;

	scanf("%d %d", &n, &s);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &a[i].w, &a[i].v);
		a[i].i = i + 1;
	}

	cw = cv = 0;
	for (k = 0; k < n && cw + a[k].w <= s; k++) {
		cw += a[k].w;
		cv += a[k].v;
	}

	while (k != n && tim--) {
		i = rand() % k;
		j = rand() % (n - k) + k;
		if (cw - a[i].w + a[j].w <= s && a[j].v > a[i].v) {
			cw = cw - a[i].w + a[j].w;
			cv = cv - a[i].v + a[j].v;
			swap(a[i], a[j]);
		}
		j = rand() % (n - k) + k;
		if (cw + a[j].w <= s) {
			cw += a[j].w;
			cv += a[j].v;
			swap(a[k], a[j]);
			k++;
		}
	}

	printf("%d\n%d\n", cv, k);
	for (i = 0; i < k; i++)
		printf("%d ", a[i].i);
	printf("\n");

	return 0;
}
