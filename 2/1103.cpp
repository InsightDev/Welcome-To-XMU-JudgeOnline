#include <stdio.h>

int a[10] = { 1, 2, 4, 8, 16 };

void print()
{
	printf("%d", a[0]);
	for (int i = 1; i < 10; i++)
		printf(" %d", a[i]);
	printf("\n");
}

void recur(int k, int s)
{
	if (k == 9) {
		a[k] = 1000 - s;
		if (a[k] > a[k-1] && a[k] <= s + 1)
			print();
		return;
	}
	for (int i = a[k-1] + 1; i <= s + 1; i++) {
		a[k] = i;
		recur(k + 1, s + i);
	}
}

int main(int argc, char *argv[])
{
	recur(5, 31);

	return 0;
}
