#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

int w[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char c[] = "10X98765432";

int is_leap(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int check_birth(int y, int m, int d)
{
	if (m < 1 || m > 12 || d < 1)
		return 0;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return d <= 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return d <= 30;
	return is_leap(y) ? d <= 29 : d <= 28;
}

int check(string id)
{
	string sy = id.substr(6, 4);
	string sm = id.substr(10, 2);
	string sd = id.substr(12, 2);
	int y = atoi(sy.c_str());
	int m = atoi(sm.c_str());
	int d = atoi(sd.c_str());
	int s = 0;
	if (!check_birth(y, m, d))
		return 0;
	for (int i = 0; i < 17; i++)
		s += w[i] * (id[i] - '0');
	return id[17] == c[s % 11];
}

int main(int argc, char *argv[])
{
	int cas;
	char id[19];

	scanf("%d", &cas);
	while (cas--) {
		scanf("%s", id);
		if (check(id))
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
