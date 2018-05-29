#include <stdio.h>
#include <string.h>

struct node {
	int num;
	int mod;
	int pre;
} q[3000000];

bool x[100000];
bool b[10];

void output(int i)
{
	if (i < 0)
		return;
	output(q[i].pre);
	printf("%d", q[i].num);
}

void search(int n)
{
	int i;
	int head = 0;
	int tail = 0;

	for (i = 1; i < 10; i++) {
		if (!b[i])
			continue;
		if (i % n == 0) {
			printf("%d\n", i);
			return;
		}
		x[i % n] = true;
		q[tail].num = i;
		q[tail].mod = i % n;
		q[tail++].pre = -1;
	}
	while (head != tail) {
		int mod = q[head].mod;
		int pre = head++;
		for (i = 0; i < 10; i++) {
			if (!b[i])
				continue;
			q[tail].num = i;
			q[tail].mod = (mod * 10 + i) % n;
			q[tail].pre = pre;
			if (q[tail].mod == 0) {
				output(tail);
				printf("\n");
				return;
			}
			if (x[q[tail].mod])
				continue;
			tail++;
		}
	}
	printf("-1\n");
}

int main(int argc, char* argv[])
{
	int n, m, i;

	scanf("%d %d", &n, &m);
	while (n >= 0 || m >= 0) {
		memset(x, false, sizeof(x));
		memset(b, true, sizeof(b));
		while (m--) {
			scanf("%d", &i);
			b[i] = false;
		}
		search(n);
		scanf("%d %d", &n, &m);
	}

	return 0;
}
