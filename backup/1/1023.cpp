#include <cstdio>
#include <string>
using namespace std;

int a[21];

string recur(int n, int m)
{
	if (n == 1)
		return "";
	for (int j = n - 1; j >= 1; j--) {
		if (a[j] * a[n - j] < m) {
			m -= a[j] * a[n - j];
			continue;
		}
		return "E" + recur(j, m / a[j]) + "S" + recur(n - j, m % a[j]);
	}
	return "ERROR";
}

int main(int argc, char *argv[])
{
	int n, m;

	a[1] = 1;
	for (int i = 2; i <= 20; i++)
	for (int j = 1; j < i; j++)
		a[i] += a[j] * a[i - j];

	scanf("%d %d", &n, &m);
	while (n && m) {
		if (n == 1 || m > a[n])
			printf("ERROR");
		else
			printf("%s", recur(n, m).c_str());
		printf("\n");
		scanf("%d %d", &n, &m);
	}

	return 0;
}
