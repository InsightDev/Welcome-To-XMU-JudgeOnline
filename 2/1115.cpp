#include <stdio.h>

const char *s[] = { "", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", "eleven", "twelve",
	"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
	"eighteen", "nineteen" };

const char *t[] = { "", "", "twenty", "thirty", "forty",
	"fifty", "sixty", "seventy", "eighty", "ninety" };

int main(int argc, char *argv[])
{
	int n;

	scanf("%d", &n);
	if (n < 20)
		printf("%s\n", s[n]);
	else if (n % 10 == 0)
		printf("%s\n", t[n / 10]);
	else
		printf("%s %s\n", t[n / 10], s[n % 10]);

	return 0;
}
