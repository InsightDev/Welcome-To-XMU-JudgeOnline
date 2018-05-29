#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char s[10];
	int i, v;

	scanf("%s", s);
	while (strcmp(s, "0")) {
		for (v = 0, i = 0; s[i]; i++) {
			if (s[i] > '8')
				v = (v << 3) + (s[i] - '2');
			else if (s[i] > '3')
				v = (v << 3) + (s[i] - '1');
			else
				v = (v << 3) + (s[i] - '0');
		}
		printf("%s : %d\n", s, v);
		scanf("%s", s);
	}

	return 0;
}
