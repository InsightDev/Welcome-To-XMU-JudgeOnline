#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[20];

int main(int argc, char *argv[])
{
	int n, m;
	int i, t;
	priority_queue<int, vector<int>, greater<int> > que;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", a + i);

	sort(a, a + n);
	while (m--)
		que.push(0);

	for (i = n - 1; i >= 0; i--) {
		t = que.top();
		que.pop();
		que.push(t + a[i]);
	}
	while (que.size() > 1)
		que.pop();
	printf("%d\n", que.top());

	return 0;
}
