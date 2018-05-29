#include <stdio.h>
#include <string.h>
#include <limits.h>

int f[101][101];
int p[101][101];
char s[102];

void dyna(int n)
{
	int i, j, k, l;
	int sum;

	for (i = 1; i <= n; i++)
		f[i][i] = 1;
	for (l = 2; l <= n; l++)
	for (j = l; j <= n; j++)
	{
		i = j - l + 1;
		p[i][j] = -1;
		f[i][j] = INT_MAX;
		if ((s[i] == '(' && s[j] == ')') ||
			(s[i] == '[' && s[j] == ']'))
			f[i][j] = f[i+1][j-1];
		for (k = i; k < j; k++) {
			sum = f[i][k] + f[k+1][j];
			if (sum < f[i][j]) {
				f[i][j] = sum;
				p[i][j] = k;
			}
		}
	}
}

void recur(int l, int r)
{
	if (l > r)
		return;

	if (l == r) {
		if (s[l] == '(' || s[l] == ')')
			printf("()");
		else
			printf("[]");
	} else {
		if (p[l][r] == -1) {
			printf("%c", s[l]);
			recur(l + 1, r - 1);
			printf("%c", s[r]);
		} else {
			recur(l, p[l][r]);
			recur(p[l][r] + 1, r);
		}
	}
}

int main(int argc, char *argv[])
{
	int nn;

	scanf("%s", s + 1);
	nn = strlen(s + 1);

	dyna(nn);
	recur(1, nn);
	printf("\n");

	return 0;
}
