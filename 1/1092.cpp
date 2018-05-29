#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

struct node{
	int i;
	char* p;
} a[100000];

char s[100001];
int n, k;

int comp(const node& n0, const node& n1)
{
	char* p = n0.p;
	char* q = n1.p;
	for (int i = 0; i < k; i++)
		if (*(p+i) != *(q+i))
			return *(p+i) < *(q+i);
	return n0.i < n1.i;
}

int same(char* p, char* q)
{
	for (int i = 0; i < k; i++)
		if(*(p+i) != *(q+i))
			return 0;
	return 1;
}

int main(int argc, char** argv)
{
	int i, j, c;
	int ans = 0;

	scanf("%d", &k);
	scanf("%s", s);
	n = strlen(s);
	n = n - k + 1;

	for (i = 0; i < n; i++) {
		a[i].p = s + i;
		a[i].i = i;
	}
	sort(a, a + n, comp);

	j = 0;
	c = 1;
	for (i = 1; i < n; i++) {
		if (same(a[i].p, a[j].p)) {
			if (a[i].i - a[j].i >= k) {
				c++;
				j = i;
			}
		} else {
			ans = max(ans, c);
			j = i;
			c = 1;
		}
	}
	ans = max(ans, c);
	if (ans >= 2)
		printf("%d\n", ans);
	else
		printf("0\n");

	return 0;
}
