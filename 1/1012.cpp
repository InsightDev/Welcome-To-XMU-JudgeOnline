#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char ch;
	int i = 0;

	while (scanf("%c", &ch) != EOF) {
		if (isupper(ch))
			ch = (((ch - 'A') - i) % 26 + 26) % 26 + 'A';
		else if (islower(ch))
			ch = (((ch - 'a') - i) % 26 + 26) % 26 + 'a';
		printf("%c", ch);
		i++;
	}

	return 0;
}
