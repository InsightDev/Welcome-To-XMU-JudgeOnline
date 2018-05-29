#include <stdio.h>
#include <stdlib.h>

#define QS 50000
#define HS 10949
#define N 20
#define S 5
#define C 4

struct node {
	long long num;
	int step, prev;
} que[QS];
int head, tail;

struct hash {
	long long num;
	struct hash* next;
} lst[HS], use[QS];
int si = 0;

int t[N];
int r[N];
int c[N];
long long s[N];
long long o[N][S];
long long z[N][S];
long long u[N][S];
long long all = 1152921504606846975ll;
long long msk = 141898022878445568ll;
long long des = 81084584501968896ll;
long long m15 = 32767ll;


static void hash_init()
{
	int i;
	for (i = 0; i < HS; i++) {
		lst[i].num = -1ll;
		lst[i].next = NULL;
	}
	si = QS;
}

inline int hash_code(long long num) {
	int i, code = 0;
	for (i = 0; i < 4; i++) {
		code += num & m15;
		num >>= 15;
	}
	return code % HS;
}

inline int hash_hash(long long num)
{
	int k = hash_code(num);
	if (lst[k].num == -1ll) {
		lst[k].num = num;
		return 0;
	}
	if (lst[k].num == num)
		return 1;
	struct hash* ptr = lst[k].next;
	while (ptr != NULL) {
		if (ptr->num == num)
			return 1;
		ptr = ptr->next;
	}
	ptr = &use[--si];
	ptr->num = num;
	ptr->next = lst[k].next;
	lst[k].next = ptr;
	return 0;
}

inline int valid(long long n, int k, int q, int x,
		int i, int j, int y, int l, int p)
{
	if (i < 0 || i > 4 || j < 0 || j > 3)
		return 0;
	int g = (i << 2) + j;
	if (o[g][y] == 0 || (n & o[g][y]) != 0)
		return 0;
	long long m = n & z[k][x] | u[q][x];
	if (hash_hash(m))
		return 0;
	que[tail].num = m;
	que[tail].step = l;
	que[tail++].prev = p;
	if ((m & msk) != des)
		return 0;
	return 1;
}

int search(long long w)
{
	long long f, x;
	int i, j, k, l, p;

	hash_init();
	head = 0;
	tail = 0;
	que[tail].num = w;
	que[tail].step = 0;
	que[tail++].prev = -1;
	while (head != tail) {
		w = que[head].num;
		l = que[head].step + 1;
		p = head++;
		f = w;
		for (k = 0; k < N; k++) {
			x = (w >> t[k]) & 7ll;
			if (x == 0ll)
				continue;
			i = r[k];
			j = c[k];
			if (x == 1ll) {
				if (valid(f, k, k - 4, 1, i - 1, j, 1, l, p)
					|| valid(f, k, k + 1, 1, i, j + 2, 3, l, p)
					|| valid(f, k, k + 2, 1, i, j + 2, 1, l, p)
					|| valid(f, k, k + 4, 1, i + 1, j, 1, l, p)
					|| valid(f, k, k - 1, 1, i, j - 1, 3, l, p)
					|| valid(f, k, k - 2, 1, i, j - 2, 1, l, p))
					return l;
			} else if (x == 2ll) {
				if (valid(f, k, k - 4, 2, i - 1, j, 3, l, p)
					|| valid(f, k, k - 8, 2, i - 2, j, 2, l, p)
					|| valid(f, k, k + 1, 2, i, j + 1, 2, l, p)
					|| valid(f, k, k + 4, 2, i + 2, j, 3, l, p)
					|| valid(f, k, k + 8, 2, i + 2, j, 2, l, p)
					|| valid(f, k, k - 1, 2, i, j - 1, 2, l, p))
					return l;
			} else if (x == 3ll) {
				if (valid(f, k, k - 4, 3, i - 1, j, 3, l, p)
					|| valid(f, k, k - 8, 3, i - 2, j, 2, l, p)
					|| valid(f, k, k + 1, 3, i, j + 1, 3, l, p)
					|| valid(f, k, k + 2, 3, i, j + 1, 1, l, p)
					|| valid(f, k, k + 4, 3, i + 1, j, 3, l, p)
					|| valid(f, k, k + 8, 3, i + 1, j, 2, l, p)
					|| valid(f, k, k - 1, 3, i, j - 1, 3, l, p)
					|| valid(f, k, k - 2, 3, i, j - 2, 1, l, p))
					return l;
				if (valid(f, k, k - 5, 3, i - 1, j - 1, 2, l, p)
					|| valid(f, k, k - 5, 3, i - 1, j - 1, 1, l, p)
					|| valid(f, k, k - 3, 3, i - 1, j + 1, 2, l, p)
					|| valid(f, k, k - 3, 3, i - 1, j, 1, l, p)
					|| valid(f, k, k + 5, 3, i, j + 1, 2, l, p)
					|| valid(f, k, k + 5, 3, i + 1, j, 1, l, p)
					|| valid(f, k, k + 3, 3, i, j - 1, 2, l, p)
					|| valid(f, k, k + 3, 3, i + 1, j - 1, 1, l, p))
					return l;
			} else if (x == 4ll) {
				if (valid(f, k, k - 4, 4, i - 1, j, 1, l, p)
					|| valid(f, k, k + 1, 4, i, j + 2, 2, l, p)
					|| valid(f, k, k + 4, 4, i + 2, j, 1, l, p)
					|| valid(f, k, k - 1, 4, i, j - 1, 2, l, p))
					return l;
			}
			w &= z[k][x];
		}
	}
	return -1;
}

int main(int argc, char* argv[])
{
	int i, j, k, m;
	long long w, x;

	for (k = 0; k < N; k++) {
		r[k] = k / C;
		c[k] = k % C;
		t[k] = k * 3;
		s[k] = 7ll << t[k];
	}
	for (k = 0; k < N; k++) {
		i = r[k];
		j = c[k];
		o[k][3] = s[k];
		z[k][3] = all - s[k];
		u[k][3] = 3ll << t[k];
		if (j < 3) {
			o[k][1] = s[k] + s[k+1];
			z[k][1] = all - o[k][1];
			u[k][1] = (1ll << t[k]) | (1ll << t[k+1]);
		}
		if (i < 4) {
			o[k][2] = s[k] + s[k+4];
			z[k][2] = all - o[k][2];
			u[k][2] = (2ll << t[k]) | (2ll << t[k+4]);
		}
		if (i < 4 && j < 3) {
			o[k][4] = s[k] + s[k+1] + s[k+4] + s[k+5];
			z[k][4] = all - o[k][4];
			u[k][4] = (4ll << t[k]) | (4ll << t[k+1])
					| (4ll << t[k+4]) | (4ll << t[k+5]);
		}
	}

	scanf("%d", &m);
	while (m--) {
		w = 0ll;
		for (i = 0; i < N; i++) {
			scanf("%lld", &x);
			if (x == 4)
				x = 0;
			else if (!x)
				x = 4;
			w |= (x << t[i]);
		}
		if ((i = search(w)) != -1)
			printf("%d\n", i);
		else
			printf("Impossible\n");
	}

	return 0;
}
