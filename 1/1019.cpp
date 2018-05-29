#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int x;
	int y;
} point;

vector<int> nt[2000];
point p[2000];
int d[2000];
int b[2000];
int x[2000];

int cmp(const point& p0, const point& p1)
{
	return p0.y != p1.y ? p0.y < p1.y : p0.x < p1.x;
}

int main(int argc, char *argv[])
{
	int n, c = 0;
	int i, j, k;
	vector<int>::iterator it;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	sort(p, p + n, cmp);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (p[j].x >= p[i].x) {
				nt[j].push_back(i);
				d[i]++;
			}
		}
	}

	while (c != n) {
		k = 0;
		for (i = 0; i < n; i++) {
			if (!b[i] && !d[i]) {
				b[i] = 1;
				x[k++] = i;
			}
		}
		c += k;
		for (i = 0; i < k; i++) {
			printf("%d %d", p[x[i]].x, p[x[i]].y);
			printf("%c", i + 1 == k ? '\n' : ' ');
			for (it = nt[x[i]].begin(); it != nt[x[i]].end(); it++)
				--d[*it];
		}
	}

	return 0;
}
