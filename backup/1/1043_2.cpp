#include <cstdio>
#include <queue>
#define hs 701819
using namespace std;

struct node {
	node(int num, int len) {
		this->num = num;
		this->len = len;
	}
	int num;
	int len;
};

struct hash {
	hash() {
		this->num = 0;
		this->next = NULL;
	}
	hash(int num) {
		this->num = num;
		this->next = NULL;
	}
	int num;
	hash *next;
} h[hs];

int a[30][10];
int o[30];
int z[30];
int n, c;

inline int inhash(int num)
{
	int i = num % hs;

	if (h[i].num == 0) {
		h[i].num = num;
		return 0;
	}

	if (h[i].num == num)
		return 1;

	struct hash *ptr = h[i].next;
	while (ptr != NULL) {
		if (ptr->num == num)
			return 1;
		ptr = ptr->next;
	}
	ptr = new hash(num);
	ptr->next = h[i].next;
	h[i].next = ptr;
	return 0;
}

inline int finish(int num)
{
	return !(num & (num - 1));
}

int query(int num)
{
	if (finish(num))
		return 0;

	queue<node> que;
	que.push(node(num, 0));
	inhash(num);

	int i, k, len, des, org;

	while (!que.empty()) {
		num = que.front().num;
		len = que.front().len + 1;
		que.pop();
		for (k = 0; k < c; k++) {
			des = num;
			org = 0;
			for (i = 0; i < n; i++) {
				if ((num & o[i]) && a[i][k] != -1) {
					des &= z[i];
					org |= o[a[i][k]];
				}
			}
			des |= org;
			if (!inhash(des)) {
				if (finish(des))
					return len;
				que.push(node(des, len));
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int m, i, j, k;

	scanf("%d %d %d", &n, &m, &c);
	int all = (1 << n) - 1;
	for (i = 0; i < n; i++) {
		o[i] = 1 << i;
		z[i] = all - o[i];
	}

	for (i = 0; i < n; i++)
	for (k = 0; k < c; k++)
		a[i][k] = -1;

	while (m--) {
		scanf("%d %d %d", &i, &j, &k);
		a[i][k] = j;
	}

	printf("%d\n", query(all));

	return 0;
}
