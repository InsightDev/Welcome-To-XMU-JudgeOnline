#include <stdio.h>

int main(int argc, char *argv[])
{
	int d, h;
	char s[7];

	scanf("%d%s", &h, s);
	d = h / 12;
	h = h % 12;
	if (!h)
		h = 12;

	printf("%s %02d%s\n", d ? "PM" : "AM", h, s);

	return 0;
}
