#include <map>
#include <string>
#include <cstdio>
using namespace std;

double cal(int b)
{
	if (b < 60)
		return 0;
	else if (b <= 63)
		return 1.0;
	else if (b <= 67)
		return 1.7;
	else if (b <= 71)
		return 2.0;
	else if (b <= 74)
		return 2.3;
	else if (b <= 77)
		return 2.7;
	else if (b <= 80)
		return 3.0;
	else if (b <= 84)
		return 3.3;
	else if (b <= 89)
		return 3.7;
	else if (b <= 94)
		return 4.0;
	else
		return 4.0;
}

int main(int argc, char* argv[])
{
	int n, a, b;
	char w[3];
	double s = 0;
	double t = 0;
	map<string, double> mp;


	mp["A+"] = 4.0;
	mp["A"] = 4.0;
	mp["A-"] = 3.7;
	mp["B+"] = 3.3;
	mp["B"] = 3.0;
	mp["B-"] = 2.7;
	mp["C+"] = 2.3;
	mp["C"] = 2.0;
	mp["C-"] = 1.7;
	mp["D"] = 1.0;
	mp["F"] = 0;

	scanf("%d", &n);
	while (n--) {
		if (scanf("%d %d", &a, &b) == 2) {
			s += a * cal(b);
			t += a;
		} else {
			scanf("%s", w);
			s += a * mp[w];
			t += a;
		}
	}
	printf("%.3f\n", s / t);

	return 0;
}
