#include<map>
#include<cstdio>
using namespace std;

int main(int argc, char* argv[])
{
	int n, k;
	long long cnt = 0;
	long long t, s = 0;
	map<long long, int> mp;
	map<long long, int>::iterator it;

	scanf("%d", &n);
	scanf("%d", &k);

	mp[0] = 1;
	while (n--) {
		scanf("%lld", &t);
		s += t;
		s %= k;
		mp[s]++;
	}
	for (it = mp.begin(); it != mp.end(); ++it) {
		t = it->second;
		if (t > 1)
			cnt += t * (t - 1) / 2;
	}
	printf("%lld", cnt);

	return 0;
}
