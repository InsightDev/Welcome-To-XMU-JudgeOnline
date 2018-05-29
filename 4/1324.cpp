#include <stdio.h>

char s[100005];
char t[100005];

int main(int argc, char* argv[])
{
	int i, k = -1;

	scanf("%s", t);
	for (i = 0; t[i]; i++) {
		if (k < 0 || s[k] != t[i])
			s[++k] = t[i];
		else
			k--;
	}
	s[++k] = '\0';
	printf("%s\n", k ? s : "-1");

	return 0;
}
