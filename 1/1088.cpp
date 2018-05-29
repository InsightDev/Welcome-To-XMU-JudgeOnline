#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int s[100];
int p[100];

int main(int argc, char *argv[])
{
	int n, m, i;
	double sum = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", s + i);
	for (i = 0; i < n; i++)
		scanf("%d%%", p + i);

	sort(s, s + m, greater<int>());
	sort(p, p + n, greater<int>());
	for (i = 0; i < m; i++)
		sum += s[i] * p[i];

	sum = sum / 100 + 0.5;
	printf("%d\n", (int)sum);

	return 0;
}
