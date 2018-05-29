#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nt[1000];
int d[1000][2];
int b[1000];

void treedp(int u)
{
	vector<int>::iterator it;

	b[u] = 1;
	d[u][0] = 0;
	d[u][1] = 1;
	for (it = nt[u].begin(); it != nt[u].end(); it++) {
		if (b[*it])
			continue;
		treedp(*it);
		d[u][0] += d[*it][1];
		d[u][1] += min(d[*it][0], d[*it][1]);
	}
}

int main(int argc, char* argv[])
{
	int n, u, v, i;

	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		nt[u].push_back(v);
		nt[v].push_back(u);
	}
	treedp(0);
	printf("%d\n", min(d[0][0], d[0][1]));

	return 0;
}
