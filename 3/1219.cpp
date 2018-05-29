#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct node {
	int num;
	int pre;
	char chr;
} que[100000];

int msk[10000];

void output(int i)
{
	if (i == -1)
		return;
	output(que[i].pre);
	printf("%c", que[i].chr);
}

void search(int* a, int n, int m)
{
	int i, num, res, pre;
	int head = 0;
	int tail = 0;
	char chr;

	sort(a, a + n);
	for (i = 0; i < n; i++) {
		if (a[i] == 0)
			continue;
		if (a[i] % m == 0) {
			printf("%d\n", a[i]);
			return;
		}
		que[tail].pre = -1;
		que[tail].num = a[i] % m;
		msk[que[tail].num] = 1;
		que[tail++].chr = a[i] + '0';
	}
	while (head != tail) {
		num = que[head].num;
		chr = que[head].chr;
		pre = head++;
		for (i = 0; i < n; i++) {
			res = (num * 10 + a[i]) % m;
			if (msk[res])
				continue;
			msk[res] = 1;
			que[tail].pre = pre;
			que[tail].num = res;
			que[tail++].chr = a[i] + '0';
			if (res == 0) {
				output(--tail);
				printf("\n");
				return;
			}
		}
	}
	printf("Mission Impossible\n");
}

int main(int argc, char* argv[])
{
	int n, m, i;
	int a[10];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	search(a, n, m);

	return 0;
}
