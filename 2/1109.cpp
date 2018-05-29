#include <cstdio>
using namespace std;

bool b[100001] = {true};

int
main(int argc, char *argv[])
{
	int n, m;
	int v, i;

	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%d", &v);
		for (i = m; i >= v; i--)
			b[i] = b[i] || b[i-v];
	}
	for (i = m; i >= 0; i--) {
		if (b[i]) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
