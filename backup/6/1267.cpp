#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

unsigned long long a[1563];
unsigned long long b[64];

void foper(int x, int y)
{
	int k;
	if (x % 64 != 0)
		a[x / 64] ^= b[x % 64 - 1];

	for (k = x / 64; k * 64 <= y ; k++)
	{
		a[k] ^= b[63];
	}
	if (y % 64 != 63)
	{
		a[y / 64] ^= ~b[y % 64];
	}
}

int aoper(int i)
{
	int j = i % 64;
	if (a[i / 64] & (1llu << j))
		return 1;
	else
		return 0;
}

int main(int argc, char *argv[])
{
	int cas;
	int n, m, i, j;
	char ch;

	for (i = 0; i < 64; i++) {
		b[i] = 1llu << i;
		b[i] += b[i - 1];
	}

	scanf("%d", &cas);
	while (cas--) {
		memset(a, 0, sizeof(a));
		scanf("%d %d", &n, &m);
		while (m--) {
			scanf(" %c", &ch);
			if (ch == 'A') {
				scanf("%d", &i);
				printf("%d\n", aoper(i - 1));
			} else {
				scanf("%d %d", &i, &j);
				foper(i - 1, j - 1);
			}
		}
	}

	return 0;
}
