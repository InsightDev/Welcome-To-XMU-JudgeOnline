#include <cstdio>
#include <queue>
#include <set>
using namespace std;

typedef long long ill;

struct node {
	node(ill num, int dep)
	{
		this->num = num;
		this->dep = dep;
	}
	ill num;
	int dep;
};

int a[20];
ill s[51];
int n, m;

int bfs(ill des)
{
	if (des == 0)
		return 0;

	queue<node> que;
	que.push(node(0, 0));
	set<ill> st;
	st.insert(0);

	ill num, nxt;
	int dep, i;

	while (!que.empty()) {
		node nd = que.front();
		que.pop();
		num = nd.num;
		dep = nd.dep + 1;
		for (i = 0; i < m; i++) {
			nxt = num ^ s[a[i]];
			if (st.find(nxt) == st.end()) {
				if (nxt == des)
					return dep;
				que.push(node(nxt, dep));
				st.insert(nxt);
			}
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	int cas, i, j;
	ill des;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &n, &m);
		des = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &j);
			if (j)
				des |= (1ll << i);
		}
		for (i = 1; i <= n; i++)
		{
			s[i] = 0;
			for (j = i - 1; j < n; j += i)
				s[i] |= (1 << j);
		}
		for (i = 0; i < m; i++)
			scanf("%d", &a[i]);
		printf("%d\n", bfs(des));
	}

	return 0;
}
