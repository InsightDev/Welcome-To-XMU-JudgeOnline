#include <stdio.h>

int main(int argc, char* argv[]) {
	int n, a;
	int s = 0;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		s += a;
	}
	printf("%d\n", s > 1024 ? 1024 : s);

	return 0;
}
