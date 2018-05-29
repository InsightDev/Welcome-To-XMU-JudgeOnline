#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, cas;
	unsigned d;
	unsigned s;

	scanf("%d", &cas);
	while (cas--) {
		scanf("%u", &d);
		s = 0;
		i = 1;
		while (s < d) {
			s += i * i;
			i += 1;
		}
		printf("%s\n", s == d ? "Yes" : "No");
	}

	return 0;
}
