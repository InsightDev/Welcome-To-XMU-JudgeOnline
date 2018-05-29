#include <cstdio>
#include <vector>
using namespace std;

vector<int> nt[100000];
int x[100000];
int q[100000];

int main(int argc, char* argv[])
{
	int n, m, u, v;
	int head, tail;
	int i, cnt = 0;
	vector<int>::iterator it;

	scanf("%d %d", &n, &m);
	while (m--) {
		scanf("%d %d", &u, &v);
		nt[u].push_back(v);
		nt[v].push_back(u);
	}
	for (i = 0; i < n; i++) {
		if (x[i] == 0) {
			cnt += 1;
			x[i] = 1;
			head = 0;
			tail = 0;
			q[tail++] = i;
			while (head != tail) {
				u = q[head++];
				for (it = nt[u].begin(); it != nt[u].end(); it++) {
					if (x[*it] == 0) {
						x[*it] = 1;
						q[tail++] = *it;
					}
				}
			}
		}
	}
	printf("%d\n", --cnt);

	return 0;
}
