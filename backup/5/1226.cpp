#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
	int n, i = 0;
	int s = 0;

	scanf("%d", &n);
	while (s < n) {
		i++;
		s = 3 * s + 1;
	}
	printf("%d\n", i);

	return 0;
}
