#include <stdio.h>

int main(int argc, char* argv[])
{
	int n, i;
	int	s = 1;

	scanf("%d", &n);
	while(n--) {
		scanf("%d", &i);
		s = s * i % 9973;
	}
	printf("%d\n", s);

	return 0;
}
