#include <map>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	int n, x, y;
	double x0, y0;
	double x1, y1;
	double ans;
	char ch;
	map<int, int> mp;
	map<int, int>::iterator it;

	mp[-1000000000] = 0;
	mp[+1000000000] = 0;

	scanf("%d", &n);
	while (n--) {
		scanf(" %c", &ch);
		if (ch == 'Q') {
			scanf("%d", &x);
			it = mp.find(x);
			if (it == mp.end()) {
				it = mp.upper_bound(x);
				x1 = it->first;
				y1 = it->second;
				it--;
				x0 = it->first;
				y0 = it->second;
				ans = y0 * (x - x1) / (x0 - x1) + y1 * (x - x0) / (x1 - x0);
			} else {
				ans = it->second;
			}
			printf("%.6f\n", ans);
		} else {
			scanf("%d %d", &x, &y);
			mp[x] = y;
		}
	}

	return 0;
}
