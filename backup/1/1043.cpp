#include <stdio.h>
#define HS 701819

struct node {
	void set(int s, int l) {
		this->s = s;
		this->l = l;
	}
	int s;
	int l;
} que[500000];

int h[HS];
int c[HS];
int v[500000];
int p[500000];
int a[30][10];
int o[30];
int z[30];
int n, k;
int index = 0;

inline int hash(int s)
{
	int i = s % HS;

	if (h[i] == 0) {
		h[i] = s;
		return 0;
	}
	if (h[i] == s) {
		return 1;
	}

	int j = c[i];
	while (j > 0) {
		if (v[j] == s)
			return 1;
		j = p[j];
	}
	v[++index] = s;
	j = c[i];
	c[i] = index;
	p[index] = j;
	return 0;
}


inline int finish(int s)
{
	return !(s & (s - 1));
}

int query(int s)
{
	int head = 0;
	int tail = 0;
	int i, j, l, des, org;

	if (finish(s))
		return 0;

	que[tail++].set(s, 0);
	hash(s);

	while (head != tail) {
		l = que[head].l + 1;
		s = que[head++].s;
		for (j = 0; j < k; j++) {
			des = s;
			org = 0;
			for (i = 0; i < n; i++) {
				if ((s & o[i]) && a[i][j] != -1) {
					des &= z[i];
					org |= o[a[i][j]];
				}
			}
			des |= org;
			if (!hash(des)) {
				if (finish(des))
					return l;
				que[tail++].set(des, l);
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int m, s, i, j, u;

	scanf("%d %d %d", &n, &m, &k);
	s = (1 << n) - 1;
	for (i = 0; i < n; i++) {
		o[i] = 1 << i;
		z[i] = s - o[i];
	}
	for (i = 0; i < n; i++)
	for (j = 0; j < k; j++)
		a[i][j] = -1;

	while (m--) {
		scanf("%d %d %d", &i, &j, &u);
		a[i][u] = j;
	}
	printf("%d\n", query(s));

	return 0;
}
