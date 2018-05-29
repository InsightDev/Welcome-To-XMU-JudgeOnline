#include <stdio.h>
#include <string.h>

void reverse(char* s)
{
	char temp;
	int i = 0;
	int j = strlen(s) - 1;
	while (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

int check(int k, char* s)
{
	int n = 0;
	int c = 0;
	int b = 0;
	do {
		s[n] = k % 2 + '0';
		if (s[n] == '1') {
			if (++c == 3)
				b = 1;
		} else {
			c = 0;
		}
		n += 1;
		k /= 2;
	} while (k);
	s[n] = '\0';
	reverse(s);
	return b;
}

int main(int argc, char *argv[])
{
	int n, m, i;
	char s[9];

	scanf("%d %d", &m, &n);
	for (i = m; i <= 255; i += n) {
		if (i % 7 == 0 || check(i, s))
			printf("pass\n");
		else
			printf("%s\n", s);
	}

	return 0;
}
