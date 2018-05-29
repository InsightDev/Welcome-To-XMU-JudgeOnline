#include <cstdio>
#include <cstring>

typedef unsigned long long ull;

char c[2000000];
int z[2000][2000];
ull a[2000][16];
int n, m;

int count(ull v)
{
	int c = 0;

	while (v)
	{
		c++;
		v &= (v - 1);
	}

	return c;
}

int check(int k)
{
	int i, j;
	int c;

	for (i = 0; i < n; i++)
	{
		if (i == k)
			continue;
		if (z[i][k] != -1)
		{
			if (z[i][k] != 2)
				return 0;
			continue;
		}

		c = 0;
		for (j = 0; (j << 6) < m; j++)
			c += count(a[i][j] ^ a[k][j]);

		z[i][k] = z[k][i] = c;
		if (c != 2)
			return 0;
	}

	return 1;
}

int main(int argc, char* argv[])
{
	int i, j, k = 0;
	char s[3000];

	scanf("%d %d", &n, &m);
	while (fgets(s, sizeof(s), stdin))
	{
		for (i = 0; s[i]; i++)
			if (s[i] == '0' || s[i] == '1')
				c[k++] = s[i];
	}

	for (i = 0; i < n; i++)
	{
		k = i * m;
		for (j = 0; j < m; j++)
		{
			if (c[k+j] == '1')
				a[i][j >> 6] |= (1ull << (j - (j >> 6 << 6)));
		}
	}

	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		z[i][j] = -1;

	for (i = n - 1; i >= 0; i--)
	{
		if (check(i))
		{
			printf("%d\n", i + 1);
			break;
		}
	}

	return 0;
}
