#include <queue>
#include <cstdio>
using namespace std;

int p[100001];
int x[100000];
int c[100001];
int z[200001];
int v[200001];

int main(int argc, char* argv[])
{
	int n, m, t = 0;
	int i, j;
	queue<int> que;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &i, &j);
		p[j] += 1;
		z[++t] = c[i];
		c[i] = t;
		v[t] = j;
	}
	for (i = 1; i <= n; i++)
		if (p[i] == 0)
			que.push(i);

	j = 0;
	while (!que.empty()) {
		i = que.front();
		que.pop();
		x[j++] = i;
		i = c[i];
		while (i != 0) {
			if (--p[v[i]] == 0)
				que.push(v[i]);
			i = z[i];
		}
	}

	if (j == n) {
		printf("%d", x[0]);
		for (i = 1; i < n; i++)
			printf(" %d", x[i]);
		printf("\n");
	} else {
		printf("-1\n");
	}

	return 0;
}
