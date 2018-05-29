#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct node {
	int v, i;
	int c, p;
};

struct comp {
	bool operator()(const node& a,const node& b)
	{
		return a.v != b.v ? a.v > b.v : a.i < b.i;
	}
};

int main(int argc, char* argv[])
{
	int n, i;
	char s[4];
	struct node a;
	priority_queue<node, vector<node>, comp> q;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		if (strcmp(s, "PUT") == 0) {
			scanf("%d %d %d", &a.c, &a.v, &a.p);
			a.i = i;
			q.push(a);
		} else {
			if (!q.empty()) {
				a = q.top(), q.pop();
				printf("%d %d\n", a.c, a.p);
			} else {
				printf("-1\n");
			}
		}
	}

	return 0;
}
