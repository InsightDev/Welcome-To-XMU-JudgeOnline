#include <cstdio>
#include <algorithm>
using namespace std;

int w[1000000];

int main(int argc, char *argv[])
{
	int n, c;
	int i, j;
	int cnt = 0;

	scanf("%d %d", &c, &n);
	for (i = 0; i < n; i++)
		scanf("%d", w + i);

	sort(w, w + n);

	i = 0;
	j = n - 1;
	while (i < j) {
		cnt++;
		if (w[i] + w[j] <= c) {
			i++;
			j--;
		} else {
			j--;
		}
	}
	if (i == j)
		cnt++;
	printf("%d\n", cnt);

	return 0;
}
