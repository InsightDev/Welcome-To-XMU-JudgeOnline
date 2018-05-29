#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

struct node {
	int v, i, p;
	char name[31];
};

struct comp {
	bool operator()(const node& a,const node& b)
	{
		return a.v != b.v ? a.v > b.v : a.i > b.i;
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
		if (!strcmp(s, "PUT")) {
			scanf("%s %d %d", a.name, &a.v, &a.p);
			a.i = i;
			q.push(a);
		} else {
			if (!q.empty()) {
				a = q.top(), q.pop();
				printf("%s %d\n", a.name, a.p);
			} else {
				printf("EMPTY\n");
			}
		}
	}

	return 0;
}
