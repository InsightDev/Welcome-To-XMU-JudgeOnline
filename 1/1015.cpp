#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char ch;
	int start = 1;

	while (scanf("%c", &ch) != EOF) {
		if (isalpha(ch)) {
			if (start)
				start = 0;
			else
				ch = tolower(ch);
		}
		printf("%c", ch);
		if (ch == '.' || ch == '!' || ch == '?')
			start = 1;
	}

	return 0;
}
