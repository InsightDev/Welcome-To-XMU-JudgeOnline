#include <cstdio>
#include <cstring>

int mt[101][101];
int mx[101];
int my[101];
int vs[101];
int n, m;

int path(int i)
{
	int j;

	for (j = 1; j <= m; j++)
	{
		if (mt[i][j] && !vs[j])
		{
			vs[j] = 1;
			if (my[j] < 0 || path(my[j]))
			{
				mx[i] = j;
				my[j] = i;
				return 1;
			}
		}
	}

	return 0;
}

int hungary()
{
	int i, j;
	int cnt = 0;

	for (i = 1; i <= n; i++)
		mx[i] = -1;
	for (j = 1; j <= m; j++)
		my[j] = -1;

	for (i = 1; i <= n; i++)
	{
		if (mx[i] < 0)
		{
			memset(vs, 0, sizeof(vs));
			cnt += path(i);
		}
	}

	return cnt;
}

int main(int argc, char* argv[])
{
	int cas, e;
	int i, j, k;

	scanf("%d", &cas);
	for (k = 1; k <= cas; k++)
	{
		scanf("%d %d %d", &n, &m, &e);
		memset(mt, 1, sizeof(mt));

		while (e--)
		{
			scanf("%d %d", &i, &j);
			mt[i][j] = 0;
		}

		printf("Case %d: %d\n", k, hungary());
	}

	return 0;
}
